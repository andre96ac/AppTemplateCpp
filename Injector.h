#pragma once
#include<vector>

#include "Service.h"




class Injector
{
private:
	inline static std::vector<Service*> services;

public:

	template<typename T>
	static void registerService() {
		T* instance = new T();

		T* foundService = NULL;
		try
		{
			foundService = get<T>();
		}
		catch (const std::exception&)
		{

		}

		if (foundService != NULL) {
			throw std::invalid_argument("Servizio duplicato");
		}

		services.push_back(instance);
		
		
	}

	template<typename T>
	static T* get() {



		for (auto service : services) {

			T * retInstance = dynamic_cast<T* >(service);
			if (retInstance != NULL) {
				return retInstance;
			}
		}
		throw std::invalid_argument("Servizio non trovato");
	}

};

