/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: October 29th, 2023
Card.cpp defines the member functions for the Card class.
*/

#include "Card.hpp"
#include <utility> //move error squiggles goes away after doing this

// Default Constructor
Card::Card() 
{
    //creates a new Card object
    //cardType_ = POINT_CARD;  //set an initial type like point card (default ig) //update - removed cuz i do it in the action/point now
    instruction_ = "";       //set an initial instruction, empty in this case
    drawn_ = false;          //set the initial drawn status like flase
    bitmap_ = nullptr;       //image data pointer to nullptr.
}

// Destructor
Card::~Card() 
{
    //destructor destroying duh
    delete[] bitmap_; //removed the [] but idk y ?
}

// Copy Constructor also here ur creating a new obj so u dont check for self assignment
Card::Card(const Card& rhs) 
{
    //creates a new Card object by copying another Card object (rhs) by copying all it's data members
    //update - bitmap instead of iterating thru a forloop, treating it like every other data member worked
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
    bitmap_=rhs.bitmap_;

    //OLD VERSION KAZI27 COMMIT 56d10a98b11c8ee3e86045e87b2b8f8ea65fe80 
    //also need to copy the bitmap but first check if rhs has a valid bitmap so:
    // if (rhs.bitmap_ != nullptr)
    // {
    //     bitmap_ = new int[80]; 
    //     for (int i = 0; i < 80; ++i) //i++ same as ++i
    //     { 
    //         bitmap_[i] = rhs.bitmap_[i]; 
    //     }
    // }

    // if (rhs.bitmap_ == nullptr)
    // {
    //     bitmap_ = nullptr;
    // }

    // bitmap_ = new int[80]; 
    // for (int i = 0; i < 80; ++i) //i++ same as ++i
    // { 
    //     bitmap_[i] = rhs.bitmap_[i]; 
    // } 

}

// Copy Assignment Operator also here ur copying stuff from two existing objs so check for self assignment
Card& Card::operator=(const Card& rhs) 
{
    if (this == &rhs)
    {
        return *this; //if current obj is same as rhs jus return bro
    }

    if (this != &rhs)
    {
        //v1 that works
        //*bitmap_ = *rhs.bitmap_; previous
        // delete[] bitmap_;
        // bitmap_ = new int[80]; 
        // for (int i = 0; i < 80; ++i) //i++ same as ++i
        // { 
        //     bitmap_[i] = rhs.bitmap_[i]; 
        // }

        //v2 that makes use of copy isntead of looping
        if (rhs.bitmap_) 
        {
            bitmap_ = new int[80];
            std::copy(rhs.bitmap_, rhs.bitmap_ + 80, bitmap_); //PROFF SAID U CAN USE COPY..TO COPY LMAO
        }

        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;
    }
}

// Move Constructor, ur making a new obj and moving stuff from existing obj to there, setting exisiting obj priv data members to default
Card::Card(Card&& rhs) 
{
    //v1 that works
    //move the contents of Card object (rhs) into another (*this) and then set rhs priv data members to default vals
    // cardType_ = rhs.cardType_;
    //instruction_ = rhs.instruction_;// previous
    // instruction_ = std::move(rhs.instruction_);
    // bitmap_ = rhs.bitmap_;
    // drawn_ = rhs.drawn_;

    //v2 that works better than manual movement in v1
    instruction_ = std::move(rhs.instruction_); //all of this needs the <utility>
    cardType_ = std::move(rhs.cardType_); 
    bitmap_ = std::move(rhs.bitmap_);
    drawn_ = std::move(rhs.drawn_);

    //v1 trying stuff
    //reset source obj's stuff
    // rhs.bitmap_ = nullptr;
    // rhs.cardType_ = POINT_CARD; //remember we set default to point b4
    // rhs.instruction_ = "";
    // rhs.drawn_ = false;
}

// Move Assignment Operator, ur essentially swapping 2 objects data members
Card& Card::operator=(Card&& rhs) 
{
    //v1 that works
    // if (this == &rhs) //self assignment
    // { 
    //     return *this; 
    // } 
    // std::swap (bitmap_, rhs.bitmap_);
    // std::swap (cardType_, rhs.cardType_);
    // std::swap (instruction_, rhs.instruction_);
    // std::swap (drawn_, rhs.drawn_);
    // return *this;
    // delete[] bitmap_; 
    // cardType_ = rhs.cardType_; 
    // instruction_ = std::move(rhs.instruction_); 
    // bitmap_ = rhs.bitmap_; 
    // drawn_ = rhs.drawn_; 
    // rhs.bitmap_ = nullptr; 
    // return *this;

    //v2 that works better than manual movement in v1
    instruction_ = std::move(rhs.instruction_); //all of this needs the <utility>
    cardType_ = std::move(rhs.cardType_); 
    bitmap_ = std::move(rhs.bitmap_);
    drawn_ = std::move(rhs.drawn_);
    return *this; //only diff from this and move constructor above is that here ur returning but constructor no return
}

//IF UR CARD DOESNT WORK, ITS PROLLY FROM THE ABOVE STUFF BECAUSE BELOW IS SIMPLE STUFF

//get the type fo the card via getter
std::string Card::getType() const 
{
    if (cardType_ == POINT_CARD) 
    {
        return "POINT_CARD";
    } 
    
    else if (cardType_ == ACTION_CARD) 
    {
        return "ACTION_CARD";
    } 

    else
    {
        return "";
    }
}

//setter sets card type based on the param
void Card::setType(const CardType& type) 
{
    cardType_ = type;
}

//get the instruction of the card via getter
const std::string& Card::getInstruction() const 
{
    return instruction_;
}

//setter sets instruction based on the param
void Card::setInstruction(const std::string& instruction) 
{
    instruction_ = instruction;
}

//getter returns pointer to the image data
const int* Card::getImageData() const 
{
    return bitmap_;
}

//setter sets imagedata type based on the param
void Card::setImageData(int* data) 
{
    bitmap_ = data;
}

//getter gets the drawn status of the card
bool Card::getDrawn() const 
{
    return drawn_;
}

//setter sets drawn status based on the param
void Card::setDrawn(const bool& drawn) 
{
    drawn_ = drawn;
}