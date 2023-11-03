/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: November 1st, 2023
ActionCard.cpp defines the member functions for the ActionCard class.
*/

#include "ActionCard.hpp"

ActionCard::ActionCard() 
{
    // initializers list
    setType(ACTION_CARD);
    setInstruction("");  // empty tring
    setDrawn(false);     // not inifitally drawn
    setImageData(nullptr); 
}

bool ActionCard::isPlayable() 
{
    //checks whether the card is playable or no so first check if the card is drawm if not drawn it cant be played
    if (getDrawn() == false) 
    {
        return false;
    }

    std::string instruction = getInstruction(); 

    // Check if the instruction matches valid patterns 
    std::regex validInstructions("(DRAW \\d+ CARD\\(S\\))|(PLAY \\d+ CARD\\(S\\))|(REVERSE HAND)|(SWAP HAND WITH OPPONENT)"); 
    return std::regex_match(instruction, validInstructions); 
}

void ActionCard::Print() const {

    // print the card type and instruction
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card:" << std::endl; 

    //if there is image data, print it but if not just say no image data
    const int* imageData = getImageData();
    if (getImageData() != nullptr) 
    { 
        for (int i = 0; i < 80; ++i) 
        { 
            std::cout << getImageData()[i] << " "; 
        } 
    } 
    
    else 
    { 
        std::cout << "No image data"; 
    } 
    
    std::cout << std::endl; 
}