#include <iostream>
#include "Application.h"

namespace viper {
    Application::Application() {}

    Application::~Application() {}

    void Application::run() {
        std::cout << "-- Running App" << std::endl;
    }
}