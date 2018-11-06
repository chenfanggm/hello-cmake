#pragma once

#include "Core.h"

namespace viper {
    class Application {
        public:
            Application();
            virtual ~Application();

            void run();
    };

    Application* createApp();
}