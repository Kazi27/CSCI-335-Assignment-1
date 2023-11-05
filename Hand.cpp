/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: November 4th, 2023
Hand.cpp defines the member functions for the PointCard class.
*/

#include "Hand.hpp"

//default constructor
Hand::Hand()
{
    //no initialzier list needed
}

//destructor
Hand::~Hand()
{
    //no deletion required
}

//copy constructor
Hand::Hand(const Hand& other)
{
    cards_ = other.cards_;
}

//copy assignment operator
Hand& Hand::operator=(const Hand& other)
{
    if (this == &other) //& for refrence use in copy assignment, this is chcking for self assignemnt
    {
        return *this; //a pointer that points to current obj
    }

    // if (this != &other) //not needed
    // {
        cards_ = other.cards_;
        return *this;
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
    if (this == &other) //self assignment
    {
        return *this;
    }

    std::swap(cards_, other.cards_);
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
    cards_.push_back(card); //point card has a move and move assignment operator defined so its a movable type so u can do this plus card is a vect so u can push/pop etc
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
    if (isEmpty())
    {
        //return 0;
        throw std::runtime_error("empty hand"); //throw exception
    }

    PointCard card2play = std::move(cards_.front()); //front card from hand

    cards_.pop_front(); //remove card from hand

    if (card2play.isPlayable() == true) //if card playable
    {
        return (std::stoi(card2play.getInstruction())); //return points player gets after playing it
    }

    if (card2play.isPlayable() == false)
    {
        return 0; //card not played so 0pts
    }
}