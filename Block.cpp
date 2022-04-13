#include "Transaction.h"
#include "Block.h"
#include "SHA256.h"
#include <ctime>

Block::Block(int index, Transaction transaction, string prevHash) : index(index), transaction(transaction), prevHash(prevHash) {
    blockHash = generateHash();
}

string Block::generateHash() {
    time_t timestamp = time(NULL);
    string source = to_string(index) + to_string(timestamp) + prevHash;
    SHA256 sha;
    sha.update(source);
    uint8_t * digest = sha.digest();
    string destination = SHA256::toString(digest);
    delete[] digest;

    return destination;
}

unsigned int Block::getindex() {
    return index;
}

string Block::getHash() {
    return blockHash;
}

string Block::getprevHash() {
    return prevHash;
}

bool Block::validHash() {
    return (generateHash() == blockHash);
}