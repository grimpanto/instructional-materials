// @copyright 2019 Günter Kolousek

#pragma once

#include <vector>
#include <string>

std::vector<std::vector<std::string>>
csv_reader(std::vector<std::string> lines, std::vector<std::string>& header);

std::vector<std::string>
csv_writer(std::vector<std::vector<std::string>> data,
  std::vector<std::string> header);
