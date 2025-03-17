// @copyright 2019 Günter Kolousek

#include "csv_utilities.h"
#include "string_utilities.h"

#include <stdexcept>

using namespace std;

vector<vector<string>> csv_reader(vector<string> lines, vector<string>& header) {
    vector<vector<string>> data;
    int line_cnt{};
    size_t field_cnt{};

    for (auto line : lines) {
        vector<string> fields{split(line, ',')};
        if (line_cnt == 0) {
            field_cnt = fields.size();
            header = fields;
        } else {
            if (fields.size() != field_cnt) {
                throw runtime_error("line " + to_string(line_cnt) + " differs in length from header");
            } else {
                data.push_back(fields);
            }
        }
        ++line_cnt;
    }

    return data;
}


vector<string> csv_writer(vector<vector<string>> data, vector<string> header) {
    vector<string> lines;

    lines.push_back(join(header, ','));

    for (auto record : data) {
        lines.push_back(join(record, ','));
    }

    return lines;
}
