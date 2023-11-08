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
    setInstruction("");
    setType(POINT_CARD);
    setImageData(nullptr);
    setDrawn(false);
    //point card is a typa card so u inherit it from card class and defualt is point so u dont even need to change the cardtype_
    //UPDATE yea u do now cause in ur card.cpp constructor u dont have it default to point card
} 

bool PointCard::isPlayable() //check if the point card is playable
{ 
    //if the card is not drawn yet, its not playable
    if (getDrawn() == false) 
    {
        return false;
    }

    //V1 works
    //convert instruction to integer and then check if its greater than 99 or less than 1 which means its not within the range so not playable
    // if (stoi(getInstruction()) > 99 || stoi(getInstruction()) < 1) 
    // {
    //     return false;
    // }
    // return true; //if ur here it means card has been drawn and the points are withing 1 and 99 meaning it is playable

    //V2 works but efficienter?
    const std::string& x = getInstruction(); //x is gonna hold the instruction string thats returned from get isntruction
    for (char c : x) //iterate thru each character c in string x
    { 
        if (isdigit(c) == false) //for each charachter u encounter, check if its a digit. only enter the ifstatement if it is not a digit
        {  
            return false; //return false if its not a digit
        }
    }
    return true; //if ur here it means all the digits are digits and its playbale
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
        for (int i = 0; i < 80; ++i) //prof said ++i is better than i++ cuz in i++ u do a copy
        {
            std::cout << getImageData()[i];
        }
    }
}