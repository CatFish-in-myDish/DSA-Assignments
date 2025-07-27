// -*- C++ -*-

/**
 * @file Block.cpp
 * @date Created 2025-07-27
 * 
 * This file contains the definition of Block class in a Block Chain system
 */

#include <iostream>
#include <string>

#include "BlockChain.h"

using namespace std;

Block::Block(string BlockId, string BlockData, string BlockType, Block* nextBlock) {
    this->BlockId = BlockId;
    this->BlockData = BlockData;
    this->BlockType = BlockType;
    this->nextBlock = nextBlock;
}