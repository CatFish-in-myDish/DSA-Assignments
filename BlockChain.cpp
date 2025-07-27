// -*- C++ -*-

/**
 * @file BlockChain.cpp
 * @date Created 2025-07-27
 * 
 * This file contains the definition of Blockchain class methods
 */

#include <iostream>
#include <string>

#include "BlockChain.h"

using namespace std;

BlockChain::BlockChain(Block* genesisBlock) {
    this->genesisBlock = genesisBlock;
}

bool BlockChain::addBlock(string id, string data, string type) {
    if (type != "Success" && type != "Fail") {
        cout << "Block not added." << endl;
        return false;
    }

    Block* newBlock = new Block(id, data, type);

    if (this->genesisBlock == nullptr) {
        this->genesisBlock = newBlock;
        cout << "Block " << id << " (" << type << " - " << data << ")added.\n";
        return true;
    }

    Block* current = this->genesisBlock;
    
    while (current->nextBlock != nullptr) {
        if (current->BlockId == id) {
            cout << "Block not added." << endl;
            return false;
        }
        current = current->nextBlock;
    }
    if (current->BlockId == id) {
            cout << "Block not added." << endl;
            return false;
    }
    newBlock->nextBlock = this->genesisBlock;
    this->genesisBlock = newBlock;
    cout << "Block " << id << " (" << type << " - " << data << ")added.\n";
    return true;
}

Block* BlockChain::deleteBlock(string id) {

    if (this->genesisBlock == nullptr) {
        cout << "Block " << id << " not found\n";
        return nullptr;
    }

    Block* current = this->genesisBlock;

    if (this->genesisBlock->BlockId == id) {
        Block* temp = this->genesisBlock;
        this->genesisBlock = this->genesisBlock->nextBlock;
        cout << "Block " << temp->BlockId << " removed\n";
        return temp;
    }

    for (; current->nextBlock != nullptr; current = current->nextBlock) {
        if (current->nextBlock->BlockId == id) {
            Block* temp = current->nextBlock;
            current->nextBlock = current->nextBlock->nextBlock;
            cout << "Block " << temp->BlockId << " removed\n";
            return temp;
        }
    }

    cout << "Block " << id << " not found\n";
    return nullptr;
}

void BlockChain::print() {
    
   this->reverse();

   this->printReverse();

   this->reverse();
}

Block* BlockChain::find(string id) {

    if (this->genesisBlock == nullptr) {
        return nullptr;
    }

    Block* current = this->genesisBlock;

    while (current != nullptr) {
        if (current->BlockId == id) {
            cout << current->BlockId << " " << current->BlockData << " " << current->BlockType << "\n";
            return current;
        }

        current = current->nextBlock;
    }

    cout << "Block not found\n";

    return nullptr;
}

void BlockChain::reverse() {

    if (this->genesisBlock == nullptr) {
        return;
    }

    if (this->genesisBlock->nextBlock == nullptr) {
        return;
    }

    Block* prev = nullptr;
    Block* current = this->genesisBlock;
    Block* next = nullptr;

    for (; current != nullptr; next = current->nextBlock, current->nextBlock = prev, prev = current, current = next);

    this->genesisBlock = prev;
}

void BlockChain::printReverse() {
    if (this->genesisBlock == nullptr) {
        cout << "Task list is empty" << endl;
        return;
    }

    Block* current = this->genesisBlock;

    for (; current != nullptr; current = current->nextBlock) {
        cout << current->BlockId << " " << current->BlockData << " " << current->BlockType << "\n";
    }
}

Block* cut(Block* genesisBlock) {
    Block* fast = genesisBlock;
    Block* slow = genesisBlock;

    while (fast != nullptr && fast->nextBlock != nullptr) {
        fast = fast->nextBlock->nextBlock;
        if (fast != nullptr) {
            slow = slow->nextBlock;
        }
    }

    Block* temp = slow->nextBlock;
    slow->nextBlock = nullptr;
    return temp;
}

Block* merge(Block* first, Block* second, string type) {
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    if (first->BlockType != type) {
        first->nextBlock = merge(first->nextBlock, second, type);
        return first;
    } else {
        second->nextBlock = merge(first, second->nextBlock, type);
        return second;
    }

}

Block* mergeSort(Block* genesisBlock, string type) {
    if (genesisBlock == nullptr || genesisBlock->nextBlock == nullptr) {
        return genesisBlock;
    }

    Block* second = cut(genesisBlock);
    genesisBlock = mergeSort(genesisBlock, type);
    second = mergeSort(second, type);
    return merge(genesisBlock, second, type);
}

void BlockChain::sort(string type) {

    if (type != "Success" && type != "Fail") {
        cout << "Blockchain not sorted due to invalid type" << endl;
        return ;
    }

    this->genesisBlock = mergeSort(this->genesisBlock, type);
    cout << "Blockchain sorted with " << type << " blocks first\n";
}   