#pragma once

#include "Feature.h"
#include "Injector.h"
#include "TestService.h"

class TestFeature :
    public Feature
{
    void  run() {
        std::cout << Injector::get<TestService>()->getTestData() << std::endl;
        Injector::get<UtilsService>()->wait();
    };
    std::string  getName() {
        return "Test";
    };
};

