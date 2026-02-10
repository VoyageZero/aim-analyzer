/*
 * User should have access to and be able to update:
 *  - filtering
 *  - processing
 *  - allow debug mode
 */

#pragma once

#include <filesystem>
#include "databaseConfig.h"

namespace fs = std::filesystem;
namespace db = DatabaseConfig

struct Config {
  fs::path csvDirectory;
  db::DatabaseConfig dbConfig;
};

