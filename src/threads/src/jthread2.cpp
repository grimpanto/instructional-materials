#include <iostream>
#include <thread>
using namespace std;
int main() {
    jthread t{[](stop_token tok){ // first in arg. list
        int cntr{0};
        while (cntr < 10){
            this_thread::sleep_for(0.3s);
            if (tok.stop_requested()) return;
            cout << "interruptable: " << cntr << endl; 
            ++cntr;
        }
    }};
    this_thread::sleep_for(1s);//  t.request_stop();
    // destr will request_stop() and join()
}
