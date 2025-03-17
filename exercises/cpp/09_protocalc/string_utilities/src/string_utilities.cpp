// @copyright 2019 Günter Kolousek

#include "string_utilities.h"

#include <sstream>

using namespace std;

vector<string> split(const string& s, char delimiter) {
   vector<string> tokens;
   string token;
   istringstream token_stream(s);
   while (getline(token_stream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}


string join(const vector<string>& data, char delimiter) {
    string line;
    for (size_t i{}; i < data.size(); ++i) {
        line += data[i];
        if (i != data.size() - 1) {
            line += delimiter;
        }
    }
    return line;
}
