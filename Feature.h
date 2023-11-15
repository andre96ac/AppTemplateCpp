#pragma once
#include <iostream>
class Feature
{

public: 
	void virtual run() = 0;
	std::string virtual getName() = 0;

};

