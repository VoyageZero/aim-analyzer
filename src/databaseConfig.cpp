#include "databaseConfig.h"
#include "utils.h"

DatabaseConfig::DatabaseConfig() {}
//DatabaseConfig(std::string connectionString)
DatabaseConfig(
    std::string host,
    int port,
    std::string name,
    std::string user,
    std::string password,
    int maxConnections,
    int connectionTimeout // set 0 for no timeout
  ) : host(host), name(name), user(user), password(password) {
    validatePort(port);
    validateNonNegative(maxConnections);
    validateNonNegative(connectionTimeout);

    this->port = port;
    this->maxConnections = maxConnections;
    this->connectionTimeout = connectionTimeout;
}

  const std::string getHost() {
    return host;
  }

  void setHost(const std::string& host) {
    this->host = host;
  }

  const int getPort() {
    return port;
  }

  void setPort(int port) {
    validatePort(port);
    this->port = port;
  }

  const std::string getUser() {
    return user;
  }

  void setUser(const std::string& user) {
    this->user = user;
  }

  // Will eventually add safer setup.
  const std::string getPassword() {
    return password;
  }

  void setPassword(const std::string& password) {
    this->password = password;
  }

  int getMaxConnections() {
    return maxConnections;
  }

  void setMaxConnections(int newMax) {
    validateNonNegative(newMax);
    this->maxConnections = newMax;
  }

  int getConnectionTimeout() {
    return connectionTimeout;
  }

  void setConnectionTimeout(int connectionTimeout) {
    validateNonNegative(connectionTimeout);
    this->connectionTimeout;
  }

  void DatabaseConfig::validatePort(int port) {
    if (port < 0 || port > 65535) {
      throw std::invalid_argument("Port value must be between 0-65535.\n");
    }
  }

