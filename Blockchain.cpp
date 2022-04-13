#include "Transaction.h"
#include "Block.h"
#include "Blockchain.h"
#include <iostream>
#include <ctime>

using namespace std;

Blockchain::Blockchain() {
    blockchain.push_back(genesisBlock());
}

Block Blockchain::genesisBlock() {
    time_t current;
    return Block(0, Transaction(), "NULL");
}

void Blockchain::addBlock(Transaction transaction) {
    blockchain.push_back(Block(blockchain.size() - 1, transaction, blockchain.back().getHash()));
}

bool Blockchain::validChain() {
    for(vector<Block>::iterator it = blockchain.begin(); it!=blockchain.end(); it++) {
        if (!((*it).validHash())) return false;
        if((*it).getindex() && (*it).getprevHash() != (*(it - 1)).getHash()) return false;
    }

    return true;
}

Blockchain::~Blockchain() {
    blockchain.clear();
}
