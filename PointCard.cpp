/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: November 2nd, 2023
PointCard.cpp defines the member functions for the PointCard class.
*/

#include "PointCard.hpp" 

PointCard::PointCard() 
{ 
    // initializer list 
    setType(POINT_CARD); 
    setInstruction("0"); 
    setImageData(nullptr); 
    setDrawn(false); 
} 

bool PointCard::isPlayable() 
{ 
    //first get the instruction then check if its valid like if its a digit or nah
    if (getDrawn() == false) 
    {
        return false;
    }

    if (stoi(getInstruction()) > 99 || stoi(getInstruction()) < 1) 
    {
        return false;
    }

    return true;
} 

void PointCard::Print() const 
{ 
    std::cout << "Type: " << getType() << std::endl; 
    std::cout << "Points: " << getInstruction() << std::endl; 
    std::cout << "Card:" << std::endl; 
    if (getImageData() == nullptr)
    {
        std::cout << "No image data" << std::endl;
    }
    
    if (getImageData() != nullptr) 
    {
        std::cout << getImageData();
    }
}