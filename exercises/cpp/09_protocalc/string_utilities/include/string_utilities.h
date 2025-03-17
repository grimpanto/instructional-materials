// @copyright 2019 Günter Kolousek

#pragma once

#include <vector>
#include <string>

std::vector<std::string> split(const std::string& s, char delimiter);
std::string join(const std::vector<std::string>& data, char delimiter);
