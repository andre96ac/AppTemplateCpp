#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#include "Feature.h"
#include "Constraints.h"
#include "Injector.h"

#include "ManagerService.h"
#include "UtilsService.h"






class App
{
public: 

	int run() {
		this->onInit();
		while (!Injector::get<ManagerService>()->hasToExit())
		{
			int choose = showMenu();

			if (choose == 0 ||choose > features.size()) {
				std::cout << std::endl << "Errore: scelta non permessa" ;
				Injector::get<UtilsService>()->wait();
			}
			else {
				Injector::get<UtilsService>()->clear();
				try
				{
					features[choose - 1]->run();
				}
				catch (const std::invalid_argument& ex)
				{
					std::cout << "ERRORE - " << ex.what() << " - La funzione e' stata interrotta";
					Injector::get<UtilsService>()->wait();
				}

			}


		}
		Injector::get<UtilsService>()->clear();
		this->onExit();
		return 0;
	}


	template <typename T>
	void registerFeature() {
		T* feature = new T();
		if (feature != NULL) {
			features.push_back(feature);
		}
	}

	template <typename T>
	void registerService() {
		try
		{
			Injector::registerService<T>();
		}
		catch (const std::exception& ex)
		{
			std::cerr << "Errore - Impossibile registrare il servizio - "<< ex.what() << std::endl;
		}
	}

private:
	std::vector<Feature*> features;

	int showMenu() {
		std::string choose;
		int iChoose = 0;
		int c = 0;
		Injector::get<UtilsService>()->clear();
		std::cout << "######## " << APP_NAME << " " << APP_VERSION << " ########" << std::endl << std::endl;
		std::cout << "Cosa vuoi fare?" << std::endl;

		for (auto feature : features)
		{
			if (feature != NULL) {
				std::cout << ++c << " - " << feature->getName() << std::endl;
			}
			else {
				break;
			}
		}
		try
		{
			iChoose = Injector::get<UtilsService>()->getConsoleLine<int>();
		}
		catch(std::exception E){

		}
		
	
		return iChoose;
	}

	void onInit() {
		std::cout << "Benvenuto in "<< APP_NAME << " " << APP_VERSION << std::endl<<std::endl;
	}
	void onExit() {
		std::cout << "Uscita..." << std::endl;
	}


};

