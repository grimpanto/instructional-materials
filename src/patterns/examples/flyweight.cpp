
#include <iostream>
#include <map>

using namespace std;


struct Drawable {  // Flyweight
    virtual void draw(int x, int y)=0;
};

struct Icon : public Drawable {
    string name;
    int width;
    int height;
    Icon(string name) : name{name} {
        width = 16;  // dependent of...
        height = 16;
    }
    void draw(int x, int y) {
        cout << "icon at " << x << ":" << y << endl;
    }
};

struct IconFactory {
    map<string, Icon*> pool;
    Icon* get(string name) {
        auto search = pool.find(name);
        if (search == pool.end()) {
            pool[name] = new Icon(name);
        }
        return pool[name];
    }
};

int main() {
    IconFactory factory;
    Icon* i1{factory.get("hearts")};
    Icon* i2{factory.get("diamonds")};
    Icon* i3{factory.get("hearts")};
    cout << (i1 == i2) << endl;  // -> 0
    cout << (i1 == i3) << endl;  // -> 1
}
