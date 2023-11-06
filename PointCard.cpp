/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: November 2nd, 2023
PointCard.cpp defines the member functions for the PointCard class.
*/

#include "PointCard.hpp" 

PointCard::PointCard() : Card()
{ 
    setInstruction("0");
    //point card is a typa card so u inherit it from card class and defualt is point so u dont even need to change the cardtype_
} 

bool PointCard::isPlayable() //check if the point card is playable
{ 
    //if the card is not drawn yet, its not playable
    if (getDrawn() == false) 
    {
        return false;
    }

    //convert instruction to integer and then check if its greater than 99 or less than 1 which means its not within the range so not playable
    if (stoi(getInstruction()) > 99 || stoi(getInstruction()) < 1) 
    {
        return false;
    }

    return true; //if ur here it means card has been drawn and the points are withing 1 and 99 meaning it is playable
} 

void PointCard::Print() const 
{ 
    //shows card type, points of the point card then the card image data but first u check if there isss data. If no then say no, if yes then show it 
    std::cout << "Type: " << getType() << "\n" << "Points: " << getInstruction() << "\n" << "Card: " << "\n";

    if (getImageData() == nullptr)
    {
        std::cout << "No image data" << std::endl;
    }

    if (getImageData() != nullptr)  
    {
        std::cout << getImageData();
    }
}