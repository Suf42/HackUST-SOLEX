#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include "Block.h"
#include <vector>

using namespace std;

class Blockchain : public Block {
    Block genesisBlock();

    public:
    vector<Block> blockchain;
    Blockchain();
    void addBlock(Transaction transaction);
    bool validChain();
    ~Blockchain();
};

#endif
