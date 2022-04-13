/*
address (username) -> account state (personal info)
account state - 
nonce
balance
storage root -> storage
code hash -> code
world state is 1 root connected to many addresses (starting address of array)
Externally owned account vs smart contract account (have storage and code)
address is a 160-bit (32) hex number created from mnemonic or username with pair of public and private key
for contract, it is creator address and nonce = 1
Transaction contains 
nonce
gas price
gas limit
to
value
v,r,s
data
mining sequence determined by miner so no stacks to store transactions
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

class AccountState {
    string address;
    unsigned int nonce;
    double balance;
    double energyBalance;
    //AccountState* prevNode;
    //AccountState* nextNode;

    public:
    AccountState();
    string getaddress();
    unsigned int getnonce();
    double getbalance();
    double getenergyBalance();
    //AccountState* getprevNode();
    //AccountState* getnextNode();
};

class EOA : public AccountState {
    public:
    EOA();
};

class SmartContract : public AccountState {
    string storageRoot;
    string codeHash;

    public:
    SmartContract();
    string getstorageRoot();
    string getcodeHash();
};

//class WorldState : public AccountState {
//    public:
//      vector<AccountState*> root;
//};