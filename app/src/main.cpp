#include <iostream>
#include <Viper.h>

class SandBox : public viper::Application {
    public:
        SandBox() {}
        ~SandBox() {}
};

viper::Application* viper::createApp() {
    return new SandBox();
}
