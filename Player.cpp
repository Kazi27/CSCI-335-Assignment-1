/*
CSCI335 Fall 2023
Assignment 1 – Card Game
Name: Kazi Anwar
Date: November 5th, 2023
Player.cpp defines the member functions for the Player class.
*/

#include "Player.hpp"

//default constructor
Player::Player()
{
    hand_ = Hand(); //call constructor
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr; //dont know why we dont call the deck constructor here
    pointdeck_ = nullptr;
}

//destructor
Player::~Player()
{
    //no new keyword or dynamic mem allocation taking place so no need for delete keyword?
}

//get players hand
const Hand& Player::getHand() const
{
    return hand_;
}

//set players hand to hand passed as a param
void Player::setHand(const Hand& hand)
{
    hand_ = hand;
}

//get score
int Player::getScore() const
{
    return score_;
}

//set score to the score as a param
void Player::setScore(const int& score)
{
    score_ = score;
}

//play the action card and report the instruction
void Player::play(ActionCard&& card)
{
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << std::endl;
    if (card.getInstruction() == "SWAP HAND WITH OPPONENT")
    {
        //?
    }

    else if (card.getInstruction() == "REVERSE HAND")
    {
        hand_.Reverse();
    }
}

//draw point card into hand
void Player::drawPointCard()
{
    //auto temp = pointdeck_->Draw(); //auto to simplify type, draw from point card store it in temp
    //hand_.addCard(temp); //add that card to hand
    //thats not allowed, lvalue cant be case as rvalue witjout move so combining the two works:
    hand_.addCard(pointdeck_->Draw());
}

//play point card and update score
void Player::playPointCard()
{
    score_ += hand_.PlayCard();
}

//set opponent
void Player::setOpponent(Player* opponent)
{
    opponent_ = opponent;
}

//get opponent
Player* Player::getOpponent()
{
    return opponent_;
}

//set action deck
void Player::setActionDeck(Deck<ActionCard>* actiondeck)
{
    actiondeck_ = actiondeck;
}

//get action deck
Deck<ActionCard>* Player::getActionDeck()
{
    return actiondeck_;
}

//set point deck
void Player::setPointDeck(Deck<PointCard>* pointdeck)
{
    pointdeck_ = pointdeck;
}

//get point deck
Deck<PointCard>* Player::getPointDeck()
{
    return pointdeck_;
}