#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Login {
    string user;
    string pass;

    public:
      Login();
      bool CheckAccount(string user, string pass);
      bool CheckSpace(string str);
      void AddAccount();
      bool LoginProc();
      string getuser();
      string getpass();
};

#endif