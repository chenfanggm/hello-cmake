#pragma once

#ifdef VIPER_PLATFORM_OSX
extern viper::Application* viper::createApp();

int main(int argc, char** argv) {
    printf("-- Starting Viper Engine\n");
    viper::Application* app = viper::createApp();
    app->run();
    delete app;
}
#endif