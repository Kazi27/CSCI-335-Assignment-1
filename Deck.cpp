/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: November 4th, 2023
Deck.cpp defines the member functions for the Deck class.
*/

#include "Deck.hpp"

//Default Constructor
template <typename CardType>
Deck<CardType>::Deck()
{
    //cards_ = [];
    //u dont need to do that because cards_ vector is empty by default anyways yk?
}

//Destructor
template <typename CardType>
Deck<CardType>::~Deck()
{
    //delete cards_;
    //cards is a vector so you don't hav to worry abt deleting it, it deletes itself when ur done w the program
}

//add a card to the deck
template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card)
{
    cards_.push_back(card); //add the card ur passing to the cards_ vector
}

//is card_ empty or nah
template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
    return cards_.empty(); //works but trying smth
    //return (cards_.size() == 0);
}

//draw a card from the deck
template <typename CardType>
CardType&& Deck<CardType>::Draw() //&& means move
{
    // if (IsEmpty() == true)
    // {
    //     return false;
    // }

    if (IsEmpty() == false) 
    //if (!IsEmpty()) //its not empty
    {
        //cards_.back().setDrawn(true);
        CardType&& card = std::move(cards_.back()); //move the card from the back to top
        //CardType card = std::move(cards_.back()); //player works
        cards_.pop_back(); //remove that card from the deck
        card.setDrawn(true);
        return std::move(card); //return it as r value
        //return card;
    }
    return CardType(); // new addition, makes player work
    //return card; //this makes player not work aka 34
}   

// template <typename CardType>
// CardType&& Deck<CardType>::Draw() 
// { 
//     if (cards_.size() != 0) 
//     {
//         if (cards_.size() != 0) 
//         {
//             CardType card = std::move(cards_.back());
//             cards_.pop_back();

//             card.setDrawn(true);
//             return card; 
//         }
//     }
//     return std::move(card);
// } 

//shuffle the deck
template <typename CardType>
void Deck<CardType>::Shuffle()
{
    std::mt19937 seed(2028358904); //random number generator using std::mt19937 with a seed
    std::shuffle(cards_.begin(), cards_.end(), seed); //shuffle the cards using std::shuffle
}

//get size of the deck
template <typename CardType>
int Deck<CardType>::getSize() const
{
    //return (cards_.size()); //works just trying smth
    return (this->cards_.size());
}

//get vector of the cards
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}