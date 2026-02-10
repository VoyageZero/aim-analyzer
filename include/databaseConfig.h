#pragma once 

class DatabaseConfig {
  public:
    DatabaseConfig();
    //DatabaseConfig(std::string connectionString);  set to add eventually
    DatabaseConfig(
        std::string host,
        int port,
        std::string name,
        std::string user,
        std::string password,
        int maxConnections,
        int connectionTimeout
    );

    const std::string getHost();
    void setHost(const std::string& host);

    const int getPort();
    void setPort(int port);

    const std::string getUser();
    void setUser(const std::string& user);

    // Will eventually add safer setup.
    const std::string getPassword();
    void setPassword(const std::string& password);

    int getMaxConnections();
    void setMaxConnections(int newMax);

    int getConnectionTimeout();
    void setConnectionTimeout(int connectionTimeout);

  private:
    std::string host;
    int port;
    std::string name;
    std::string user;
    std::string password;
    int maxConnections;
    int connectionTimeout;

    void validatePort(int port);
}
