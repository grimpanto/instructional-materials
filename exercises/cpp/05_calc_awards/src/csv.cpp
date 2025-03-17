// @copyright 2019 Günter Kolousek

#include "csv_utilities.h"

using namespace std;

vector<string> read_textfile(ifstream& file) {
    vector<string> result;

    string line;
    while (getline(file, line)) {
        result.push_back(line);
    }

    if (!file.eof())
        throw runtime_error("Error reading from stream");

    return result;
}

vector<string> read_textfile(const string filename) { // throws runtime_error
    ifstream file{filename};
    if (!file) {
        throw runtime_error("Could not open " + filename + "for reading");
    }

    vector<string> result;

    try {
        result = read_textfile(file);
    } catch (runtime_error& e) {
        // throw runtime_error("Error reading " + filename);
        throw_with_nested(runtime_error("Error reading " + filename));
    }

    file.close();
    return result;
}


void write_textfile(ofstream& file, vector<string> lines) {
    for (auto line : lines) {
        file << line << endl;
    }

    if (!file.good())
        throw runtime_error("Error writing to stream");
}

void write_textfile(const string filename, vector<string> lines) { // throws runtime_error
    ofstream file{filename};

    if (!file) {
        throw runtime_error("Could not open " + filename + "for writing");
    }

    try {
        write_textfile(file, lines);
    } catch (...) {
        throw_with_nested(runtime_error("Error writing to " + filename));
    }

    file.close();
}
