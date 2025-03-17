// @copyright 2019 Günter Kolousek

#pragma once

#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> read_textfile(std::istream& file); // throws runtime_error
std::vector<std::string> read_textfile(const std::string filename); // throws runtime_error
void write_textfile(std::ostream& file, std::vector<std::string> lines); // throws runtime_error
void write_textfile(const std::string filename, std::vector<std::string> lines); // throws runtime_error
