
#include "phone_dict.h"

#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

// @copyright 2019 Günter Kolousek

#include "json.hpp"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using json = nlohmann::json;

int main(int argc, const char** argv) {
    CLI::App app{"Stores, retrieves, and deletes phone numbers"};

    string phone_numbers_file{"phone_numbers.json"};
    string name;
    int number{};
    bool erase_it{};
    bool list_it{};

    app.add_option("-f,--file", phone_numbers_file, "The file to be processed (default: phone_numbers.json)")->envname("PHONE_NUMBERS_FILE");
    CLI::Option* list_flag{app.add_flag("-l", list_it, "List the content of the phone dictionary")};
    CLI::Option* erase_flag{app.add_flag("-e", erase_it, "Erase the entry for the given NAME")};
    CLI::Option* name_opt{app.add_option("NAME", name, "name to query or set")};
    CLI::Option* num_opt{app.add_option("NUMBER", number, "phone number to set")};
    erase_flag->excludes(num_opt);
    list_flag->excludes(erase_flag);
    list_flag->excludes("NAME");
    //list_flag->excludes(num_opt);
    erase_flag->needs(name_opt);
    num_opt->needs(name_opt);

    app.get_formatter()->label("OPTIONS", "Options");

    CLI11_PARSE(app, argc, argv);

    ifstream ifs{phone_numbers_file};
    //json phone_numbers;
    PhoneDict phone_numbers;
    ifs >> phone_numbers;
    ifs.close();

    if (list_it) {
        for (auto& [key, value] : phone_numbers) {
            cout << key << ": " << value << "\n";
        }
    } else if (*num_opt) {
        phone_numbers[name] = number;
        ofstream ofs{phone_numbers_file};
        ofs << setw(4) << phone_numbers << endl;
        ofs.close();
        cerr << "number " << number << " set for " << name << endl;
    } else {
        if (phone_numbers.find(name) != end(phone_numbers)) {
            if (*erase_flag) {
                phone_numbers.erase(name);
                ofstream ofs{phone_numbers_file};
                ofs << setw(4) << phone_numbers << endl;
                ofs.close();
                cerr << "name " << name << " erased" << endl;
            } else
                cout << phone_numbers[name] << endl;
        } else {
            cerr << "no user " << name << endl;
            return 1;
        }
    }

    return 0;
}
