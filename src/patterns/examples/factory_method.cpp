
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

struct ButtonCreator {
    virtual Button* create()=0;
};

struct LinuxButtonCreator : public ButtonCreator {
    Button* create() {
        return new LinuxButton();
    }
};

int main() {
    //Button* btn{new LinuxButton()};  // -> hard coded!
    ButtonCreator* factory{new LinuxButtonCreator()};
    Button* btn{factory->create()};
    btn->paint();
}
