    #include <iostream>
    #include <cstdint>
    using namespace std;
  
    int main() {
        uint8_t i{254};
        uint8_t res;
        res = i + i;
        cout << +res << endl;  // -> 252
        res = res - i;
        cout << +res << endl;  // -> 254
    }
