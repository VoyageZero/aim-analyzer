#pragma once

#include <optional>

std::optional<std::tm> strToDate(const std::string& dateStr);
std::string dateToStr(const std::tm& tm);

void validateNonNegative(const std::string& value, int n);

void trim(std::string& s);

