// @copyright 2019 Günter Kolousek

#include "file_utilities.h"
#include "csv_utilities.h"
#include "calc_awards.h"

#include "CLI11.hpp"

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#include "fmt/format.h"
#include "fmt/ranges.h"
#pragma GCC diagnostic pop

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char** argv) {
    CLI::App app{"Calculates the awards for the given students"};

    string stdin;
    string infile;
    string outfile;

    app.add_option("STDIN", stdin, "stdin marker (must be '-')");
    app.add_option("-i,--infile", infile, "The file to be processed (if ommited: stdin");
    app.add_option("-o,--outfile", outfile, "The file to be written (if ommited: stdout)");

    app.get_formatter()->label("OPTIONS", "Options");

    CLI11_PARSE(app, argc, argv);

    vector<string> lines;

    if (string line{}; stdin == "-" || (stdin == "" && infile == ""))
        while (true) {
            getline(cin, line);
            if (cin)
                lines.push_back(line);
            else
                break;
        }
    else if (stdin != "") {
        cerr << app.help() << endl;
        return 1;
    }

    try {
        if (infile != "")
            lines = read_textfile(infile);
    } catch (exception& e) {
        cerr << e.what() << endl;;
        return 2;
    }

    vector<vector<string>> data;
    vector<string> header;
    try {
        data = csv_reader(lines, header);
    } catch (exception& e) {
        cerr << e.what() << endl;
        return 3;
    }

    data = calc_awards(data);

    header.push_back("award");
    lines = csv_writer(data, header);

    if (outfile != "")
        write_textfile(outfile, lines);
    else
        write_textfile(cout, lines);

    return 0;
}
