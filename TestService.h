#pragma once
#include <iostream>

#include "Service.h"

class TestService :
    public Service
{
public:
    std::string getTestData() {
        return "This is a test";
    }
};

