// @copyright 2019 Günter Kolousek

#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <sstream>
#include <iomanip>

using namespace std;
using namespace std::literals;

void lada_taiga(int& total_time, unsigned int laps) {
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_real_distribution<> dis{1, 10};

    ostringstream buf;

    unsigned int lap{1};

    while (lap <= laps) {
        double time_seconds;
        int sleep_time;

        time_seconds = dis(gen);
        sleep_time = static_cast<int>(time_seconds * 1000);
        total_time += sleep_time;

        this_thread::sleep_for(chrono::milliseconds{sleep_time});
        buf << lap << " Lada Taiga " << setprecision(3) << time_seconds << 's' << endl;
        cout << buf.str();
        buf.str("");
        ++lap;
    }
}

class Car {
    string name;
    int total_time{};
  public:
    Car(string name_) : name{name_} {}
    void operator()(unsigned int laps) {
        std::random_device rd;
        std::mt19937 gen{rd()};
        std::uniform_real_distribution<> dis{1, 10};

        ostringstream buf;
        unsigned int lap{1};

        while (lap <= laps) {
            double time_seconds;
            int sleep_time;

            time_seconds = dis(gen);
            sleep_time = static_cast<int>(time_seconds * 1000);
            total_time += sleep_time;

            this_thread::sleep_for(chrono::milliseconds{sleep_time});
            buf << lap << ' ' << name << ' ' << setprecision(3) << time_seconds << 's' << endl;
            cout << buf.str();
            buf.str("");

            ++lap;
        }
    }
    int get_total_time() const { return total_time; }
};


void help() {
    cout << "Usage: contest [-h | --help | LAPS]" << endl;
    exit(0);
}


void error(string msg="") {
    if (msg != "")
        cerr << msg << endl;
    cerr << "Run with --help for more information." << endl;
    exit(1);
}


int main(int argc, char* argv[]) {
    if (argc > 2) {
        error("The following argument was not expected: "s + argv[2]);
    }

    uint laps{};

    if (argc == 2) {
        size_t pos;
        string arg{argv[1]};

        if (arg == "-h" or arg == "--help")
            help();

        try {
            laps = stoi(arg, &pos);
        } catch (const invalid_argument& e) {
            error("Could not convert: "s + arg);
        } catch (const out_of_range& e) {
            error("Out of range (1 <= laps < 16): "s + arg);
        }

        if (pos != arg.size())
            error("Could not convert: "s + arg);

        if (laps < 1 or laps > 15)
            error("Out of range (1 <= laps < 16): "s + arg);
    } else
        laps = 10;

    int total_time_lada_taiga{};
    thread lada_thread{lada_taiga, ref(total_time_lada_taiga), laps};
    Car opel_manta{"Opel Manta"};
    //thread opel_thread{&Car::operator(), ref(opel_manta)};
    thread opel_thread{ref(opel_manta), laps};
    lada_thread.join();
    opel_thread.join();

    if (total_time_lada_taiga < opel_manta.get_total_time()) {
        cout << "Sieger ist: Lada Taiga mit " << total_time_lada_taiga / 1000.0 << "s" << endl;
        cout << "Verlierer ist: Opel Manta mit " << opel_manta.get_total_time() / 1000.0 << "s"  << endl;
    } else if (total_time_lada_taiga == opel_manta.get_total_time()) {
        cout << "Beide sind Sieger mit " << total_time_lada_taiga / 1000.0 << "s"  << endl;
    } else {
        cout << "Sieger ist: Opel Manta mit " << opel_manta.get_total_time() / 1000.0 << "s"  << endl;
        cout << "Verlierer ist: Lada Taiga mit " << total_time_lada_taiga / 1000.0 << "s" << endl;
    }
}
