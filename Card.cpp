/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: October 29th, 2023
Card.cpp defines the member functions for the Card class.
*/

#include "Card.hpp"

// Destructor
Card::~Card() 
{
    // You should free any dynamically allocated memory in this destructor if needed.
    delete[] bitmap_;
}

// Copy Constructor
Card::Card(const Card& rhs) 
{
    //creates a new Card object by copying another Card object by copying all the data members from rhs to current obj
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;

    /* dont know about deep copies
    // Make a deep copy of the image data.
    if (rhs.bitmap_ != nullptr) {
        bitmap_ = new int[ of [80];
        for (int i = 0; i < 80; ++i) {
            bitmap_[i] = rhs.bitmap_[i];
        }
    } else {
        bitmap_ = nullptr;  // The source object has no image data.
    }*/
}

// Copy Assignment Operator
Card& Card::operator=(const Card& rhs) 
{
    //assigns one Card obj to another like rhs to current obj
    if (this == &rhs) 
    {
        //if this obj is the same as the rhs just return that bro
        return *this;
    }

    //clean up the current object's resources, dont know if we need to tho
    delete[] bitmap_;

    //copy the stuff from rhs to the current obj like the copy constructor
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;

    /* dont know about deep copies
    // Make a deep copy of the image data.
    if (rhs.bitmap_ != nullptr) {
        bitmap_ = new int[80];
        for (int i = 0; i < 80; ++i) {
            bitmap_[i] = rhs.bitmap_[i];
        }
    } else {
        bitmap_ = nullptr;  // The source object has no image data.
    }*/

    return *this;  //return current obj
}

// Move Constructor
Card::Card(Card&& rhs) 
{
    //move one Card object to another aka rhs to the current obj like take resources from the source object and set it to a valid but "empty" state
    cardType_ = rhs.cardType_;
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;
    
    //set source obj's pointer to nullptr aka valid but empty state
    rhs.bitmap_ = nullptr;
}

// Move Assignment Operator
Card& Card::operator=(Card&& rhs) 
{
    //assigns one Card obj to another
    if (this == &rhs) 
    {
        return *this;
    }

    //clean up current obj's stuff
    delete[] bitmap_;

    //move data from rhs to the current obj
    cardType_ = rhs.cardType_;
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = rhs.bitmap_;
    drawn_ = rhs.drawn_;

    //set source obj's pointer to nullptr aka valid but empty state
    rhs.bitmap_ = nullptr;
    return *this;
}

// Default Constructor
Card::Card() 
{
    //creates a new Card object
    cardType_ = POINT_CARD;  //set an initial type like point card
    instruction_ = "";       //set an initial instruction, empty in this case
    drawn_ = false;          //set the initial drawn status like flase
    bitmap_ = nullptr;       //image data pointer to nullptr.
}

// getType() Function
std::string Card::getType() const 
{
    //get the type fo the card via getter
    if (cardType_ == POINT_CARD) 
    {
        return "Point Card";
    } 
    
    else if (cardType_ == ACTION_CARD) 
    {
        return "Action Card";
    } 
    
    else 
    {
        return "Unknown";  //type is neither point nor action
    }
}

// setType() Function
void Card::setType(const CardType& type) 
{
    //setter sets card type based on the param
    cardType_ = type;
}

// getInstruction() Function
const std::string& Card::getInstruction() const 
{
    //get the instruction of the card via getter
    return instruction_;
}

// setInstruction() Function
void Card::setInstruction(const std::string& instruction) 
{
    //setter sets instruction based on the param
    instruction_ = instruction;
}

// getImageData() Function
const int* Card::getImageData() const 
{
    //getter returns pointer to the image data
    return bitmap_;
}

// setImageData() Function
void Card::setImageData(int* data) 
{
    //setter sets imagedata type based on the param
    bitmap_ = data;
}

// getDrawn() Function
bool Card::getDrawn() const 
{
    //getter gets the drawn status of the card
    return drawn_;
}

// setDrawn() Function
void Card::setDrawn(const bool& drawn) 
{
    //setter sets drawn status based on the param
    drawn_ = drawn;
}