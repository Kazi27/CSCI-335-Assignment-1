/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: November 1st, 2023
ActionCard.cpp defines the member functions for the ActionCard class.
*/

#include "ActionCard.hpp"

ActionCard::ActionCard() : Card()
{
    //action card is a typa card so u inherit it from card class but defualt is point so u need to change the cardtype_
    setType(ACTION_CARD);
}

bool ActionCard::isPlayable() 
{
    //checks whether the card is playable or no so first check if the card is drawm if not drawn it cant be played
    if (getDrawn() == false) 
    {
        return false;
    }

    if (getInstruction() == "SWAP HAND WITH OPPONENT" || getInstruction() == "REVERSE HAND") 
    {
        return true;
    } 

    std::regex pattern(R"((?:DRAW|PLAY)\s([1-9]\d{0,1})\sCARD\(S\))");

    if (!std::regex_match(getInstruction(), pattern)) 
    {
        return false;
    }

    return true;
}

void ActionCard::Print() const 
{
    std::cout << "Type: " << getType() << "\n" << "Instructions: " << getInstruction() << "\n" << "Card: " << "\n";

    if (getImageData() == nullptr)
    {
        std::cout << "No image data" << std::endl;
    }

    if (getImageData() != nullptr) 
    {
        std::cout << getImageData();
    }
}