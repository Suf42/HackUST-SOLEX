#include "Worldstate.h"
#include "Login.h"
#include "SHA256.h"
#include <iostream>
#include <cstring>

using namespace std;

string wrldState = "textfiles/Worldstate.txt";

AccountState::AccountState() {
    Login newUser;
    newUser.AddAccount();
    address = newUser.getuser();
    nonce = 0;
    balance = 0;
    energyBalance = 0;
    //prevNode
    //nextNode

}

string AccountState::getaddress() {
    return address;
}

unsigned int AccountState::getnonce() {
    return nonce;
}

double AccountState::getbalance() {
    return balance;
}

double AccountState::getenergyBalance() {
    return energyBalance;
}

//AccountState* AccountState::getprevNode() {
//    return prevNode;
//}

//AccountState* AccountState::getnextNode() {
//    return nextNode;
//}

EOA::EOA() : AccountState() {
    //store AccountState into world State
    
    fstream fon;
    fon.open(wrldState.c_str(),fstream::app);
    if(!fon.is_open())
        return;
    fon.put('\n');
    fon << getaddress();
    fon.put('\n');
    fon << getnonce();
    fon.put('\n');
    fon << getbalance();
    fon.put('\n');
    fon << getenergyBalance();
    fon.put('\n');
    fon << "0";
    fon.put('\n');
    fon << "0";
    fon.put('\n');
    fon.close();
    
}

SmartContract::SmartContract() : AccountState() {
    storageRoot = 1;
    codeHash = 1;


    fstream fon;
    fon.open(wrldState.c_str(),fstream::app);
    if(!fon.is_open())
        return;
    fon.put('\n');
    fon << getaddress();
    fon.put('\n');
    fon << getnonce();
    fon.put('\n');
    fon << getbalance();
    fon.put('\n');
    fon << getenergyBalance();
    fon.put('\n');
    fon << storageRoot;
    fon.put('\n');
    fon << codeHash;
    fon.put('\n');
    fon.close();

}

string SmartContract::getstorageRoot() {
    return storageRoot;
}

string SmartContract::getcodeHash() {
    return codeHash;
}