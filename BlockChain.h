// -*- C++ -*-

#ifndef BLOCK_CHAIN_HEADER
#define BLOCK_CHAIN_HEADER

/**
 * @file BlockChain.h
 * @date Created 2025-07-25
 * 
 * This file contains the declaration of Block structure in a blockchain and blockchain class with its member and method declaration.
 */

#include <iostream>
#include <string>

using namespace std;

#include "Block.h"

/**
 * represents a simplified blockchain log system
 */
class BlockChain {
    private:

        /**
         * pointer to the first block in the blockchain
         */
        Block* genesisBlock;

    public:

        /**
         * Initializes an object for the block chain class
         * 
         * @param genesisBlock pointer of the block struct which will be the first block in the block chain, default nullptr
         */
        BlockChain(Block* genesisBlock = nullptr);

        /**
         * Addes a new block at the rear of the blockchain
         * prints in "Block <blockid> (<blockdata> - <blocktype?) added." if the appending is successful
         * 
         * @param id the id of the block to be adde of string type
         * @param data the data to be stored in the new block of string type
         * @param type the type of data to be added 
         * 
         * @returns true if the appending is successful otherwise false 
         */
        bool addBlock(string id, string data, string type);

        /**
         * Deletes a block from the block chain using the block id
         * prints "Block <blockid> removed" if block with the specified id is found, 
         * otherwise prints "Block <blockid> not found"
         * 
         * @param id the id of the block to be removed from the block chain
         * @returns pointer to the block that has been removed, if the block does not exists returns nullptr
         */
        Block* deleteBlock(string id);

        /**
         * prints all the blocks in "<blockid> <blockdata> <blocktype>" format one line per block
         * prints "Blockchain is empty" if the genesisBlock points to a nullptr
         */
        void print();

        /**
         * works just as print function but reverses the block chain 
         * calls the reverse function, then the print function and calls the reverse function again to return the blockchain to the
         * original format
         */
        void printReverse();

        /**
         * Reverses the block chain using 3 pointer approach
         */
        void reverse();

        /**
         * sort the blockchain with all blocks of the given type (Success or Fail) appearing first
         * uses merge sort
         * 
         * @param type the type of the blocks that has to appear first of the block chain
         */
        void sort(string type);

        /**
         * searches for the block containing a specified id
         * 
         * @param id the id of the block that has to be searched
         * @returns pointer to the block if the id matches, otherwise nullptr
         */
        Block* find(string id);
};

#endif