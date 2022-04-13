#include "Login.h"
#include "Worldstate.h"

string accinfo = "textfiles/accountinfo.txt";

Login::Login() {
    user = '\0';
    pass = '\0';
}

bool Login::CheckAccount(string user, string pass)
{
    string u;
    string p;

    ifstream fin;
    fin.open(accinfo.c_str());
    if(!fin.is_open())
        return false;
    fin >> u;
    fin >> p;
    if(u.compare(user)==0 && p.compare(pass)==0)
    {
        fin.close();
        return true;
    }
    while(!fin.eof())
    {
        fin >> u;
        fin >> p;
        if(u.compare(user)==0 && p.compare(pass)==0)
        {
            fin.close();
            return true;
        }
    }
    fin.close();
    return false;
}

bool Login::CheckSpace(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(isspace(str[i]))
            return true;
    }
    return false;
}

void Login::AddAccount()
{
    string u, p;
    int flag=0;
    ifstream fin;
    cout << "Create an account." << endl;
    fin.open(accinfo.c_str(),fstream::in);
    if(!fin.is_open()){
        return;
    }
    while(flag==0)
    {
        fin.clear();
        fin.seekg(0);
        flag=1;
        cout << "Enter a username: ";
        getline(cin, user);

        fin >> u;
        fin >> p;
        if(u.compare(user)==0)
            flag=0;
        while(!fin.eof() && flag==1)
        {
            fin >> u;
            fin >> p;
            if(u.compare(user)==0)
                flag=0;
        }
        if(flag==0)
            cout << "Username already exists!" << endl;
        else
        {
            if(CheckSpace(user))
            {
                flag = 0;
                cout << "Username should not contain spaces!" << endl;
            }
        }
            
    }
    fin.close();
    flag = 0;
    while(flag == 0)
    {
        flag = 1;
        cout << "Enter a password: ";
        getline(cin,pass);
        if(CheckSpace(pass))
        {
            flag = 0;
            cout << "Password should not cotain spaces!" << endl;
        }
    }

    fstream fon;
    fon.open(accinfo.c_str(),fstream::app);
    if(!fon.is_open())
        return;
    fon.put('\n');
    fon << user;
    fon.put('\n');
    fon << pass;

    cout << "You may log in using your username and password now." << endl << endl;
    fon.close();
}

bool Login::LoginProc() //g++ -o log hackathon.cpp
{
    string init;
    int flag=0;
    do
    {
        cout << "Enter '1' to login\nEnter '2' to create an account.\nEnter '3' to exit.\n\nEnter: ";
        getline(cin,init);
        cout<<endl;
        if(init.compare("1") == 0)
        {
            cout << "Username: ";
            getline(cin, user);
            cout << "Password: ";
            getline(cin, pass);
            cout<<endl;
            if(CheckAccount(user,pass))
                flag=1;
            if(flag==0)
                cout << "Username or password is incorrect! Try again." << endl << endl;
        }
        else if(init.compare("2") == 0)
        {
            //Login::AddAccount();
            EOA newUser;
        }
        else if(init.compare("3") == 0)
            return false;
        else
            cout << "Incorrect input! Try again." << endl << endl;
    } while(flag==0);
    return true;
}

string Login::getuser() {
    return user;
}

string Login::getpass() {
    return pass;
}