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
    setType(CardType::POINT_CARD); 
    setInstruction("0"); 
    setImageData(nullptr); 
    setDrawn(false); 
} 

bool PointCard::isPlayable() 
{ 
    //first get the instruction then check if its valid like if its a digit or nah
    std::string instruction = getInstruction(); 
    for (char c : instruction) 
    { 
        if (std::isdigit(c) == false) 
        { 
            return false; 
        }
    } 
    return getDrawn(); 
} 

void PointCard::Print() const 
{ 
    std::cout << "Type: " << getType() << std::endl; 
    std::cout << "Points: " << getInstruction() << std::endl; 
    std::cout << "Card:" << std::endl; 
    if (getImageData() != nullptr) 
    { 
        for (int i = 0; i < 80; i++) 
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