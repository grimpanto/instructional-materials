
#pragma once

#include "json.hpp"

#include "date.h"

#include <chrono>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <random>

namespace measurement {
  using nlohmann::json;
  struct Measurement {
      unsigned long long id{++last_id};
      inline static unsigned long long last_id{};
      std::string date;
      double value;

      Measurement() {
          std::time_t datetime_now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
          std::stringstream buf;
          buf << std::put_time(std::localtime(&datetime_now), "%F %T");
          date = buf.str();
          std::random_device rd;
          std::mt19937 gen{rd()};
          std::uniform_real_distribution<> dis_real(0.0, 10.0);
          value = dis_real(gen);
      }      
  };

  void to_json(json& j, const Measurement& m) {
      j = json{{"id", m.id}, {"date", m.date}, {"value", m.value}};
  }

  void from_json(const json& j, Measurement& m) {
      j.at("id").get_to(m.id);
      j.at("date").get_to(m.date);
      j.at("value").get_to(m.value);
  }

  std::ostream& operator<<(std::ostream& os, const Measurement& m) {
      os << "Measurement(" << m.id << ", " << m.date  << ", " << m.value << ")";
      return os;
  }
}
