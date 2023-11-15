
#include "App.h"
#include "Feature.h"
#include "Constraints.h"

#include "ExitFeature.h"
#include "TestFeature.h"

#include "TestService.h"
#include "UtilsService.h"
#include "ManagerService.h"



int main()
{

    App* app = new App();

    app->registerService<ManagerService>();
    app->registerService<UtilsService>();
    app->registerService<TestService>();
  

    app->registerFeature<TestFeature>();
    app->registerFeature<ExitFeature>();
   

    return (app->run());
}

