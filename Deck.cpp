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
    //V1
    cards_.clear(); //u can call clear here

    //V2
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
    //V1 -- sometiems works sometimes doesnt
    // if (IsEmpty() == true)
    // {
    //     return false;
    // }

    //if (IsEmpty() == false) 
    //if (!IsEmpty()) //its not empty
    //{
        //cards_.back().setDrawn(true);
        //move the card from the back to top

        //CardType&& card = std::move(cards_.back()); //DECK works 
        //CardType card = std::move(cards_.back()); //PLAYER works

        //cards_.pop_back(); //remove that card from the deck
        //card.setDrawn(true);
        //return std::move(card); //return it as r value
        //return card;
    //}
    //return CardType(); // new addition, makes player work
    //return card; //this makes player not work aka 34

    //V2 -- works
    if (IsEmpty() == false) //if its not empty
    {
        CardType&& front = std::move(cards_.back()); //make front the owner of the backest card
        cards_.pop_back(); //remove the backest card now
        return std::move(front); //RETURN AS R VALUE REFRENCE THIS TOOK ME SO LONG THIS WAS SO AHRD
    } 
    
    else //its empty
    {
        return CardType(); //default constructor
    }
}   

// V3...
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
    //V1 works but simplaer to understand V2 for me
    //std::mt19937 seed(2028358904); //random number generator using std::mt19937 with a seed
    //std::shuffle(cards_.begin(), cards_.end(), seed); //shuffle the cards using std::shuffle

    //V2
    std::mt19937 k; //random number generator thing mt19937 provided in hpp
    k.seed(2028358904); //runs that generator starting from that number
    std::shuffle(cards_.begin(), cards_.end(), k); //specifies range like begin and end and k for kazi provides randomness ofc
}

//get size of the deck
template <typename CardType>
int Deck<CardType>::getSize() const
{
    //return (cards_.size()); //works just trying smth
    //return (this->cards_.size());
    return static_cast<int>(cards_.size()); //the above 2 returns also work, this just felt fancy if im being honest
}

//get vector of the cards
template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}