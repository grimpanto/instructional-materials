
#include "measurement.h"

#include "json.hpp"

#include <iostream>
#include <random>

using namespace std;

int main() {
    random_device rd;
    mt19937 gen{rd()};
    uniform_real_distribution<> dis_real(0.0, 10.0);
    uniform_int_distribution<> dis_int(0, 10);
    uniform_int_distribution<> dis_bool(0, 2);
    uniform_int_distribution<> dis_choice(0, 4);
    for (int n = 0; n < 10; ++n) {
        switch (auto choice{dis_choice(gen)}; choice) {
          case 0:
            cout << dis_real(gen) << endl;
            break;
          case 1:
            cout << dis_int(gen) << endl;
            break;
          case 2:
            if (dis_bool(gen))
                cout << "true" << endl;
            else
                cout << "false" << endl;
            break;
          case 3:
            measurement::Measurement m;
            nlohmann::json out=m;
            cout << out << endl;
            break;
        }
    }
}
