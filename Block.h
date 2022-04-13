#ifndef BLOCK_H
#define BLOCK_H

#include "Transaction.h"
#include <iostream>
#include <cstring>

using namespace std;

class Block : public Transaction {
    unsigned int index;
    string blockHash;
    string prevHash;
    string generateHash(); //PRIVATE!! FOR TESTING ONLY

    public:
    Block() = default;
    Block(int index, Transaction transaction, string prevHash);
    unsigned int getindex();
    string getHash();
    string getprevHash();
    Transaction transaction;
    bool validHash();
};

#endif