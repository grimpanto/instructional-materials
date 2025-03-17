// @copyright 2019 Günter Kolousek

#include "calc_awards.h"

using namespace std;

vector<vector<string>> calc_awards(vector<vector<string>> data) {
    vector<vector<string>> result;

    for (auto record : data) {
        int sum{};
        string award;
        bool has_four{};

        for (size_t i{1}; i < record.size(); ++i) {
            auto mark{stoi(record[i])};
            if (mark == 5) {
                award = "nicht bestanden";
                break;
            } else if (mark == 4) {
                has_four = true;
            }
            sum += mark;
        }
        if (award == "") {
            if (has_four)
                award = "bestanden";
            else {
                double average{static_cast<double>(sum) / (record.size() - 1)};
                if (average <= 1.5)
                    award = "mit ausgezeichnetem Erfolg bestanden";
                else if (average <= 2)
                    award = "mit gutem Erfolg bestanden";
                else
                    award = "bestanden";
            }
        }
        record.push_back(award);
        result.push_back(record);
    }
    return result;
}
