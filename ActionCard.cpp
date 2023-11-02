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
}

bool ActionCard::isPlayable() 
{
    //checks whether the card is playable or no so first check if the card is drawm if not drawn it cant be played

    if (!getDrawn()) 
    {
        return false;
    }

    // // Now, let's validate the instruction. We need to make sure it follows specific patterns.
    // // We'll use regular expressions for this purpose. The regex pattern checks if the instruction
    // // is in one of the four valid formats: DRAW x CARD(S), PLAY x CARD(S), REVERSE HAND, SWAP HAND WITH OPPONENT.
    // std::regex validInstructionPattern("^(DRAW \\d+ CARD(S)?|PLAY \\d+ CARD(S)?|REVERSE HAND|SWAP HAND WITH OPPONENT)$");
    // std::string instruction = getInstruction();
    // return std::regex_match(instruction, validInstructionPattern);
}

void ActionCard::Print() const {

    // print the card type and instruction
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;

    //if there is image data, print it but if not just say no image data
    const int* imageData = getImageData();
    if (imageData) 
    {
        std::cout << "Card: " << std::endl;
        for (int i = 0; i < 5; ++i) 
        {
            std::cout << imageData[i] << " ";
        }
        std::cout << std::endl;
    } 
    
    else 
    {
        std::cout << "Card: No image data" << std::endl;
    }
}