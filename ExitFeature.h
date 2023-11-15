#pragma once
#include <cstring>
#include <iostream>

#include "Feature.h"
#include "ManagerService.h"

class ExitFeature : public Feature
{
public:
	void run() {
		
		Injector::get<ManagerService>()->exit();

	}
	std::string getName() {
		return "Esci";
	}

};

