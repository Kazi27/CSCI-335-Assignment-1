/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: November 4th, 2023
Hand.cpp defines the member functions for the PointCard class.
*/

#include "Hand.hpp"
#include <algorithm> //NEEDED FOR REVERSE

//default constructor
Hand::Hand()
{
    //no initialzier list needed
}

//destructor
Hand::~Hand() = default; //proff said no defaults but like this works lmao
//{
    //V2 that does work but defualt v1 works better
    // while(!this->isEmpty()) //as long as obj isnt empty popback aka delete
    // {
    //     cards_.pop_back();
    // }
//}

//copy constructor
Hand::Hand(const Hand& other)
{
    //V1 iterating thru each
    // for (auto card : other.cards_) //auto to simplify type, iterate over all the cards in other hand
    // {
    //     cards_.push_back(card); //copy each card from other to this
    // }

    //v2 efficienter
    cards_ = other.cards_; //similar approach to prev copy constructors
}

//copy assignment operator
Hand& Hand::operator=(const Hand& other)
{
    //V1 self assignemtn check but not efficienter than v2
    // if (this == &other) //& for refrence use in copy assignment, this is chcking for self assignemnt
    // {
    //     return *this; //a pointer that points to current obj
    // }

    //V2, figured out ur gonna be returning Hand& anyways so combined the two returns
    if (this != &other) //self assignment check, if theyre not equal then cards_ = other.cards_
    { 
        cards_ = other.cards_; 
    }
    return *this; //in any case ur return type is Hand& so u wanna return this even if u changed something or didnt cause it didnt pass self assignment

    //V1 part 2
    // if (this != &other) 
    // {
    //     cards_ = other.cards_;
    //     return *this;
    // }

    // for (auto card : other.cards_)
    // {
    //     this->cards_.push_back(card); //copies cards from other and pushes it into this card obj
    // }
    // return *this;

    // if (this != &other) //not needed
    // {
        // cards_ = other.cards_;
        // return *this;
    // }
}

//move constructor
Hand::Hand(Hand&& other)
{
    cards_ = std::move(other.cards_); //move cards_ from other to cards_ of current obj
}

//Move assignment operator
Hand& Hand::operator=(Hand&& other)
{
    //V1 less efficient
    // if (this == &other) //self assignment
    // {
    //     return *this;
    // }

    // cards_ = std::move(other.cards_);
    // return *this;

    //V2 works cause ur gonna return Hand& anywyas so might as well combine the two return statements
    if (this != &other) 
    {
        cards_ =  std::move(other.cards_); //look at copy assignment explanation
    }
    return *this; 
}

//get cards
const std::deque<PointCard>& Hand::getCards() const
{
    return cards_;
}

//add a card
void Hand::addCard(PointCard&& card)
{
    card.setDrawn(true);
    cards_.push_back(std::move(card)); //point card has a move and move assignment operator defined so its a movable type so u can do this plus card is a vect so u can push/pop etc
}

//is hand empty or na
bool Hand::isEmpty() const
{
    return cards_.empty();
}

//reverse hand
void Hand::Reverse()
{
    std::reverse(cards_.begin(), cards_.end()); //begin is an iterator, end is another iterator, reverse reverses order of the deque
}

//play card front of hand, remove it from hand, exception if hand empty or card unplayable in which case remove that card from hand
int Hand::PlayCard()
{
    //V1 + V2 check
    if (isEmpty())
    {
        //return 0;
        throw std::runtime_error("empty hand"); //throw exception as defined in hpp
    }

    //V1
    // PointCard card2play = std::move(cards_.front()); //front card from hand

    // cards_.pop_front(); //remove card from hand

    // if (card2play.isPlayable() == true) //if card playable
    // {
    //     return (std::stoi(card2play.getInstruction())); //return points player gets after playing it
    // }

    // if (card2play.isPlayable() == false)
    // {
    //     return 0; //card not played so 0pts
    // }

    //V2 honestly simpler and better form of V1 without edge cases
    int playcardvalue = std::stoi(cards_.front().getInstruction());
    cards_.pop_front();
    return playcardvalue;
}