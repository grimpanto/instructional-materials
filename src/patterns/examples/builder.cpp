
#include <iostream>
#include <vector>

using namespace std;

struct HtmlBuilder;

struct HtmlElement {
    string name;
    string text;
    vector<HtmlElement> elements;
    
    static HtmlBuilder& create(string name);

    string to_string() {
        string res{name + ':' + text};
        if (elements.size() != 0) {
            res += '{';
            for (int i{0}; i < elements.size(); ++i) {
                res += '{';
                res += elements[i].to_string();
                res += '}';
                if (i != elements.size() - 1)
                    res += ", ";
            }
            res += '}';
        }
        return res;
    } 
};


struct HtmlBuilder {
    HtmlElement root;
    HtmlBuilder& add_child(string name, string text) {
        HtmlElement elem{name, text};
        root.elements.emplace_back(elem);
        return *this;
    }
    HtmlBuilder(string name) {
        root.name = name;
    }
    HtmlElement& get_root() { return root; }
};

HtmlBuilder& HtmlElement::create(string name) {
    return *(new HtmlBuilder(name));
}


int main() {
    HtmlElement list{HtmlElement::create("ul")
          .add_child("li", "banana")
          .add_child("li", "apple").
          get_root()};
    cout << list.to_string() << endl;
}
