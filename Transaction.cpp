#include "Transaction.h"

using namespace std;

Transaction::Transaction() {
    amount = 0;
    senderKey = "\0";
    recieverKey = "\0";
    timestamp = time(NULL);
}
    
Transaction::Transaction(double amount, string senderKey, string recieverKey, time_t timestamp) : amount(amount), senderKey(senderKey), recieverKey(recieverKey), timestamp(timestamp) {

}

double Transaction::getamount() {
    return amount;
}
    
string Transaction::getsenderKey() {
    return senderKey;
}
    
string Transaction::getrecieverKey() {
    return recieverKey;
}
    
time_t Transaction::gettimestamp() {
    return timestamp;
}
