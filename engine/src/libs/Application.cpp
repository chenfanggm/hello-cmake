#include <iostream>
#include "Log.h"
#include "Application.h"

namespace viper {
    Application::Application() {}

    Application::~Application() {}

    void Application::run() {
        VIPER_INFO("-- Running App");
    }
}