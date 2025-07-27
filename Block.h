// -*- C++ -*-

#ifndef BLOCK_HEADER
#define BLOCK_HEADER

/**
 * @file Bloch.h
 * @date Created 2025-07-27
 * 
 * This file contains the declaration of Block class in a Block Chain system
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * class to represent a block in a blockchain 
 */
class Block{
    public:
        /**
         * an unique id that is used to identify the block
         */
        string BlockId;

        /**
         * one word string describing the data
         */
        string BlockData;

        /**
         * represents the status either (Success or Fail)
         */
        string BlockType;

        /**
         * pointer to the next block, defaulted to nullptr
         */
        Block* nextBlock;

        /**
         * Initializes a block object
         * Block type validation should be done outside
         * 
         * @param BlockId an unique id to identify the block
         * @param BlockData data to be stored inside the data 
         * @param BlockType Type of the block (Success or Fail)
         * @param nextBlock pointer to the previous block in the chain, defaulted to nullptr
         */
        Block(string BlockId, string BlockData, string BlockType, Block* nextBlock = nullptr);
};

#endif