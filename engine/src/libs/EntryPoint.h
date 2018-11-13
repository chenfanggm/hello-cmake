#pragma once

#ifdef VIPER_PLATFORM_OSX
extern viper::Application* viper::createApp();

int main(int argc, char** argv) {
    viper::Log::Init();
    VIPER_CORE_WARN("-- Log service initialized");
    VIPER_INFO("-- Starting Viper Engine");

    viper::Application* app = viper::createApp();
    app->run();
    delete app;
}
#endif