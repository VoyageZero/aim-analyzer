#include "commandType.h"

#include <iostream>
#include <sstream>
#include <optional>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>

void trim(std::string& s) {
  std::string excludeChars = " \t\n\r\f\v";
  size_t first = s.find_first_not_of(excludeChars);
  if (std::string::npos == first) {
    s.clear();
    return;
  }

  size_t last = s.find_last_not_of(excludeChars);

  s.erase(last + 1);
  s.erase(0, first);
}

std::optional<std::tm> strToDate(const std::string& dateStr) {
  std::string trimmed = dateStr;
  trim(trimmed);

  std::tm tm = {};
  std::istringstream ss(trimmed);
  ss >> std::get_time(&tm, "%m-%d-%Y");

  if (ss.fail()) {
    std::cerr << "Unable to set date to " trimmed 
      << ". Date must be in MM-DD-YYYY format." << std::endl;
    return std::nullopt;
  }

  return tm;
}

std::string dateToStr(const std::tm& tm) {
  std::ostringstream oss;
  oss << std::put_time(&tm, "%m-%d-%Y");
  return oss.str();
}

void validateNonNegative(int n) {
  if (n < 0) {
    throw std::invalid_argument("Value must be greater than 0.");
  }
}

