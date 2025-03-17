
#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis(0.0, 10.0);
    for (int n = 0; n < 10; ++n) {
        cout << dis(gen) << endl;
    }
}
