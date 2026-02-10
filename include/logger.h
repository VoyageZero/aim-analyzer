#pragma once

#include <ctime>

struct LogMessage {
  time_t timestamp;
  LogLevel level;
  std::string details;
} LogMessage;

enum class LogLevel {
  DEBUG,
  INFO,
  WARN,
  ERROR
};
