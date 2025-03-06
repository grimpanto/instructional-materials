
#include <iostream>

using namespace std;

struct Button {
    virtual void paint()=0;
};

struct LinuxButton : public Button {
    void paint() {
        cout << "Linux button" << endl;
    }
};

struct GUIFactory {
    virtual Button* create_button()=0;
};

struct LinuxGUIFactory : public GUIFactory {
    Button* create_button() {
        return new LinuxButton();
    }
};


int main() {
    //Button* btn{new LinuxButton()};  // -> hard coded!
    GUIFactory* factory{new LinuxGUIFactory()};
    Button* btn{factory->create_button()};
    btn->paint();
}
