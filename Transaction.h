#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include <cstring>
#include <iostream>

using namespace std;

class Transaction {
    double amount;
    string senderKey;
    string recieverKey;
    time_t timestamp;

    //nonce
    //gas price
    //gas limit
    //to
    //value
    //v,r,s
    //data
    //mining sequence

    public:
    Transaction();
    Transaction(double amount, string senderKey, string recieverKey, time_t timestamp);
    double getamount();
    string getsenderKey();
    string getrecieverKey();
    time_t gettimestamp();
};

#endif