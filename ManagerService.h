#pragma once


#include "Service.h"

class ManagerService: public Service
{
private:
	bool exiting = false;

	

public:
	void exit() {
		exiting = true;
	}
	bool hasToExit() {
		return exiting;
	}


	

};

