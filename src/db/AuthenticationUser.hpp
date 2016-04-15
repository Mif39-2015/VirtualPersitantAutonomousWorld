#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class AuthenticationUser {
private:
    string dbName;
    string userName;
    string userPassword;

public:
    AuthenticationUser(string dbName,string userName,string userPassword);
    ~AuthenticationUser();
    string checkUser();
};
