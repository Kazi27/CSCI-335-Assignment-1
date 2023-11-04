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
    //checks whether the card is playable or no so first check if the card is drawm if not drawn it cant be played, undrawn = no play
    if (getDrawn() == false) 
    {
        return false;
    }

    if (getInstruction() == "SWAP HAND WITH OPPONENT" || getInstruction() == "REVERSE HAND") //if action is these 2, return true
    {
        return true;
    } 

    std::regex pattern("((?:DRAW|PLAY)\s([1-9]\d{0,1})\sCARD\(S\))"); //instruction starts w draw or play, has a space, 2 spaces for digits that can be 1 - 9, ends w string "CARDS" - 0 not included, case sensitive
    //gradescope accepts std::regex pattern("((R?:DRAW|PLAY)\s([1-9]\d{0,1})\sCARD\(S\))"); but when u try this in vscode it doesnt work, prolly compiler issue

    if (!std::regex_match(getInstruction(), pattern)) //if instruction does NOT match this pattern, its not playable so return false
    {
        return false;
    }

    return true; //if ur here it means cards drawn and follows the pattern of instruction so it is playable fr
}

void ActionCard::Print() const 
{
    //shows card type, instruction of the action card then the card image data but first u check if there isss data. If no then say no, if yes then show it 
    std::cout << "Type: " << getType() << "\n" << "Instruction: " << getInstruction() << "\n" << "Card: " << "\n";

    if (getImageData() == nullptr)
    {
        std::cout << "No image data" << std::endl;
    }

    if (getImageData() != nullptr) 
    {
        std::cout << getImageData();
    }
}