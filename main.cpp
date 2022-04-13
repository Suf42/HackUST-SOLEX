#include <iostream>
#include <ctime>
#include <vector>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include "Login.h"
#include "Transaction.h"
#include "Block.h"
#include "Blockchain.h"
#include "Worldstate.h"

using namespace std;

//increase nonce

string wrldstate = "textfiles/Worldstate.txt";
string temp = "textfiles/temp.txt";
string blckchain = "textfiles/Blockchain.txt";

string checkBalance(Login user) {
            if(user.getuser().compare("\0")==0){
                cout<<"Please Login!";

                if(user.LoginProc()) cout << "You have logged in successfully!\n\n";
            }
            string u;
            string nonce;
            string balance;

            ifstream fin;
            fin.open(wrldstate.c_str());
            if(!fin.is_open())
            {
                cout << "Could not retrieve information" << endl; exit(0);
            }
            //fin >> u;
            //if(u.compare(user.getuser())==0)
            //{
            //    fin >> nonce;
            //    fin >> balance;
            //    fin.close();
            //}
            while(!fin.eof())
            {
                fin >> u;

                if(u.compare(user.getuser())==0)
                {
                    fin >> nonce;
                    fin >> balance;
                    //fin.close();
                }
            }
            fin.close();

            return balance;     
}

string checkenergyBalance(Login user) {
            if(user.getuser().compare("\0")==0){
                cout<<"Please Login!";

                if(user.LoginProc()) cout << "You have logged in successfully!\n\n";
            }
            string u;
            string nonce;
            string balance;
            string energyBalance;

            ifstream fin;
            fin.open(wrldstate.c_str());
            if(!fin.is_open())
            {
                cout << "Could not retrieve information" << endl; exit(0);
            }
            //fin >> u;
            //if(u.compare(user.getuser())==0)
            //{
            //    fin >> nonce;
            //    fin >> balance;
            //    fin >> energyBalance;
            //    fin.close();
            //}
            while(!fin.eof())
            {
                fin >> u;
                
                if(u.compare(user.getuser())==0)
                {
                    fin >> nonce;
                    fin >> balance;
                    fin >> energyBalance;
                    //fin.close();
                }
            }
            fin.close();

            return energyBalance;
}

Blockchain loadBlockchain() {
    Blockchain blockchain;

    return blockchain;
}

//debug

void updateBlockchain(Blockchain blockchain, Transaction newTransaction) {
    double amount;
    string senderKey;
    string recieverKey;
    time_t timestamp;

    fstream fin;
    fstream fon;
    fin.open(blckchain.c_str());
    fon.open(temp.c_str());
    if(!fin.is_open()) {
        cout << "Could not retrieve information" << endl;
        exit(0);
    }
    if(!fon.is_open()) {
        cout << "Could not update information" << endl;
        exit(0);
    }

    while(!fin.eof())
    {
        fin >> amount;
        fin >> senderKey;
        fin >> recieverKey;
        fin >> timestamp;
        fon.put('\n');
        fon << amount;
        fon.put('\n');
        fon << senderKey;
        fon.put('\n');
        fon << recieverKey;
        fon.put('\n');
        fon << timestamp;
    }

    fon.put('\n');
    fon << newTransaction.getamount();
    fon.put('\n');
    fon << newTransaction.getsenderKey();
    fon.put('\n');
    fon << newTransaction.getrecieverKey();
    fon.put('\n');
    fon << newTransaction.gettimestamp();

    fin.close();
    fon.close();

    remove(blckchain.c_str());
    rename(temp.c_str(),blckchain.c_str());
}


void updateWorldstateBalance(Login user, double newVal) {
            string address;
            unsigned int nonce;
            double balance;
            double energyBalance;
            string storageRoot;
            string codeHash;

            ifstream fin;
            ofstream fon;
            fin.open(wrldstate.c_str());
            fon.open(temp.c_str());

            if(!fin.is_open())
            {
                cout << "Could not retrieve information" << endl; exit(0);
            }
            if(!fon.is_open())
            {
                cout << "Could not update information" << endl; exit(0);
            }
            /*
            fin >> address;
            fin >> nonce;
            fin >> balance;
            fin >> energyBalance;
            fin >> storageRoot;
            fin >> codeHash;
            if(address.compare(user.getuser())==0)
            {
                fon.put('\n');
                fon << address;
                fon.put('\n');
                fon << nonce;
                fon.put('\n');
                fon << newVal;
                fon.put('\n');
                fon << energyBalance;
                fon.put('\n');
                fon << storageRoot;
                fon.put('\n');
                fon << codeHash;
            }
            else
            {
                fon.put('\n');
                fon << address;
                fon.put('\n');
                fon << nonce;
                fon.put('\n');
                fon << balance;
                fon.put('\n');
                fon << energyBalance;
                fon.put('\n');
                fon << storageRoot;
                fon.put('\n');
                fon << codeHash;
            }
            */
            while(!fin.eof())
            {
                fin >> address;
                fin >> nonce;
                fin >> balance;
                fin >> energyBalance;
                fin >> storageRoot;
                fin >> codeHash;
                if(address.compare(user.getuser())==0)
                {
                    fon.put('\n');
                    fon << address;
                    fon.put('\n');
                    fon << nonce;
                    fon.put('\n');
                    fon << newVal;
                    fon.put('\n');
                    fon << energyBalance;
                    fon.put('\n');
                    fon << storageRoot;
                    fon.put('\n');
                    fon << codeHash;
                    //fon.put('\n');
                }
                else
                {
                    fon.put('\n');
                    fon << address;
                    fon.put('\n');
                    fon << nonce;
                    fon.put('\n');
                    fon << balance;
                    fon.put('\n');
                    fon << energyBalance;
                    fon.put('\n');
                    fon << storageRoot;
                    fon.put('\n');
                    fon << codeHash;
                    //fon.put('\n');
                }
            }

            fin.close();
            fon.close();

            fin.open(temp.c_str());
            fon.open(wrldstate.c_str());
            
            if(!fin.is_open())
            {
                cout << "Could not write information" << endl; exit(0);
            }
            if(!fon.is_open())
            {
                cout << "Could not write information" << endl; exit(0);
            }

            while(!fin.eof())
            {
                fin >> address;
                fin >> nonce;
                fin >> balance;
                fin >> energyBalance;
                fin >> storageRoot;
                fin >> codeHash;
                    fon.put('\n');
                    fon << address;
                    fon.put('\n');
                    fon << nonce;
                    fon.put('\n');
                    fon << balance;
                    fon.put('\n');
                    fon << energyBalance;
                    fon.put('\n');
                    fon << storageRoot;
                    fon.put('\n');
                    fon << codeHash;
                    //fon.put('\n');
            }

            fin.close();
            fon.close();

            //remove(wrldstate.c_str());
            //rename(temp.c_str(),wrldstate.c_str());
}

void updateWorldstateenergyBalance(Login user, double newVal) {
            string address;
            unsigned int nonce;
            double balance;
            double energyBalance;
            string storageRoot;
            string codeHash;

            ifstream fin;
            ofstream fon;
            fin.open(wrldstate.c_str());
            fon.open(temp.c_str());
            if(!fin.is_open())
            {
                cout << "Could not retrieve information" << endl; exit(0);
            }
            if(!fon.is_open())
            {
                cout << "Could not update information" << endl; exit(0);
            }
            /*
            fin >> address;
            fin >> nonce;
            fin >> balance;
            fin >> energyBalance;
            fin >> storageRoot;
            fin >> codeHash;
            if(address.compare(user.getuser())==0)
            {
                fon.put('\n');
                fon << address;
                fon.put('\n');
                fon << nonce;
                fon.put('\n');
                fon << balance;
                fon.put('\n');
                fon << newVal;
                fon.put('\n');
                fon << storageRoot;
                fon.put('\n');
                fon << codeHash;
            }
            else
            {
                fon.put('\n');
                fon << address;
                fon.put('\n');
                fon << nonce;
                fon.put('\n');
                fon << balance;
                fon.put('\n');
                fon << energyBalance;
                fon.put('\n');
                fon << storageRoot;
                fon.put('\n');
                fon << codeHash;
            }
            */
            while(!fin.eof())
            {
                fin >> address;
                fin >> nonce;
                fin >> balance;
                fin >> energyBalance;
                fin >> storageRoot;
                fin >> codeHash;
                if(address.compare(user.getuser())==0)
                {
                    fon.put('\n');
                    fon << address;
                    fon.put('\n');
                    fon << nonce;
                    fon.put('\n');
                    fon << balance;
                    fon.put('\n');
                    fon << newVal;
                    fon.put('\n');
                    fon << storageRoot;
                    fon.put('\n');
                    fon << codeHash;
                }
                else
                {
                    fon.put('\n');
                    fon << address;
                    fon.put('\n');
                    fon << nonce;
                    fon.put('\n');
                    fon << balance;
                    fon.put('\n');
                    fon << energyBalance;
                    fon.put('\n');
                    fon << storageRoot;
                    fon.put('\n');
                    fon << codeHash;
                }
            }

            fin.close();
            fon.close();

            fin.open(temp.c_str());
            fon.open(wrldstate.c_str());
            
            if(!fin.is_open())
            {
                cout << "Could not write information" << endl; exit(0);
            }
            if(!fon.is_open())
            {
                cout << "Could not write information" << endl; exit(0);
            }

            while(!fin.eof())
            {
                fin >> address;
                fin >> nonce;
                fin >> balance;
                fin >> energyBalance;
                fin >> storageRoot;
                fin >> codeHash;
                    fon.put('\n');
                    fon << address;
                    fon.put('\n');
                    fon << nonce;
                    fon.put('\n');
                    fon << balance;
                    fon.put('\n');
                    fon << energyBalance;
                    fon.put('\n');
                    fon << storageRoot;
                    fon.put('\n');
                    fon << codeHash;
                    //fon.put('\n');
            }

            fin.close();
            fon.close();

            //remove(wrldstate.c_str());
            //rename(temp.c_str(),wrldstate.c_str());
}

#define ENERGY_PRICE 2;

int main() {
    Blockchain blockchain;



    double amount;
    string senderKey;
    string recieverKey;
    time_t timestamp;

    ifstream fin;
    fin.open(blckchain.c_str());
    if(!fin.is_open()) {
        cout << "Could not retrieve information" << endl;
        exit(0);
    }
    
    //fin >> amount;
    //fin >> senderKey;
    //fin >> recieverKey;
    //fin >> timestamp;
    //blockchain.addBlock(Transaction(amount, senderKey, recieverKey, timestamp));

    while(!fin.eof())
    {
        fin >> amount;
        fin >> senderKey;
        fin >> recieverKey;
        fin >> timestamp;
        blockchain.addBlock(Transaction(amount, senderKey, recieverKey, timestamp));
    }

    fin.close();



    Login user;
    cout << "\nWelcome to SOLEX! Get started trading...\n\n";

    string init;
    bool flag = false;
    do
    {
        init = '\0';
        cout << "L - Login" << endl; // this works
        cout << "B - Buy energy" << endl;
        cout << "S - Sell energy" << endl;
        cout << "D - Deposit" << endl;
        cout << "C - Check balance (in HKD)" << endl; // works 
        cout << "E - Exit" << endl << endl; // works
        cout << "Enter a choice (L/B/S/D/C/E): ";
        getline(cin,init);
        cout << endl;
        if(init.compare("L") == 0)
        {
            if(user.LoginProc()) cout << "You have logged in successfully!\n\n";
            flag = true;
        }
        else if(init.compare("B") == 0)
        {
            cout << "Current energy price is (HKD): " << ENERGY_PRICE;
            cout << endl;
            cout << "You have " << checkBalance(user) << " (HKD) left to trade." << endl;
            double tradeAmount;
            cout << "How much energy would you like to purchase?" << endl;
            cout << "Enter an amount (in HKD): ";
            cin >> tradeAmount;

            if(stof(checkBalance(user)) < tradeAmount) {
                cout << "You don't have sufficient funds. Please top up before proceeding!" <<endl;

                double addVal;
                double newVal;

                cout<<"Please enter amount to top up or enter '0' to exit: ";
                cin >> addVal;

                if(addVal == 0) exit(0);

                newVal = addVal + stof(checkBalance(user));

                updateWorldstateBalance(user, newVal);

                cout << "Account has been successfully topped up." << endl;
            }

            //Transaction newTransaction(tradeAmount, user.getuser(), to_string(0), time(NULL));
            //blockchain.addBlock(newTransaction);
            //updateBlockchain(blockchain, newTransaction);

            double energyChange = tradeAmount/ENERGY_PRICE;

            updateWorldstateBalance(user, stof(checkBalance(user)) - tradeAmount);
            cout << stof(checkenergyBalance(user)) + energyChange << endl;
            updateWorldstateenergyBalance(user, stof(checkenergyBalance(user)) + energyChange);

            cout << "Trade successful. Account has been updated." << endl << endl;
        }
        else if(init.compare("S") == 0)
        {
            string energy = checkenergyBalance(user);
            cout << "Current energy price is (HKD): " << ENERGY_PRICE;
            cout << endl;
            cout << "You have " << energy << " (kWh) left to sell." << endl;
            double tradeAmount;
            cout << "How much energy would you like to sell?" << endl;
            cout << "Enter an amount (in kWh): ";
            cin >> tradeAmount;

            if(stof(checkenergyBalance(user)) < tradeAmount) {
                cout << "You don't have sufficient energy. input a smaller value!" <<endl;

                cout<<"Please enter amount to sell or enter '0' to exit: ";
                cin >> tradeAmount;

                if(tradeAmount == 0) exit(0);
            }

            //Transaction newTransaction(tradeAmount, user.getuser(), to_string(0), time(NULL));
            //blockchain.addBlock(newTransaction);
            //updateBlockchain(blockchain, newTransaction);

            double balanceChange = tradeAmount*ENERGY_PRICE;

            updateWorldstateBalance(user, stof(checkBalance(user)) + balanceChange);
            updateWorldstateenergyBalance(user, stof(checkenergyBalance(user)) - tradeAmount);

            cout << "Trade successful. Account has been updated." << endl << endl;
        }
        else if(init.compare("D") == 0)
        {
            double addVal;
            double newVal;

            cout<<"Please enter amount to top up: ";
            cin >> addVal;

            newVal = addVal + stof(checkBalance(user));

            updateWorldstateBalance(user, newVal);

            cout << "Account has been successfully topped up." << endl << endl << endl;
        }
        else if(init.compare("C") == 0)
        {
            cout << "Your balance is " << checkBalance(user) << " HKD." << endl << endl;
        }
        else if(init.compare("E") == 0)
        {
            exit(0);
        }
        else
        {
            flag = true;
            cout << "Incorrect input! Try again." << endl << endl;
        }
    } while(1);

    /*
    main menu
    */
   
    //cout<<"New user"<<endl;
    //EOA Luna;
    //SmartContract Silvia;

    return 0;
}