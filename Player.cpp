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
    //hand_ = Hand(); //call constructor
    score_ = 0;
    opponent_ = nullptr;
    // actiondeck_ = new Deck<ActionCard>();
    // pointdeck_ = new Deck<PointCard>();]
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
}

//destructor
Player::~Player()
{
    // delete actiondeck_;
    // delete pointdeck_; //dynamic mem allocation taking place need to use delete keyword cause u initialzied with new
    //delete actiondeck_;
    //actiondeck_ = nullptr;

    //delete pointdeck_;
    //pointdeck_ = nullptr;

    //delete opponent_;
    //opponent_ = nullptr;
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
    card.setDrawn(true); //draw the card 

    if (card.isPlayable()) //first figure out if u can play the card
    {
        std::string instruction = card.getInstruction(); //get the instruction store in instruction variable
        std::regex draw("DRAW (\\d+) CARD(\\(S\\))?"); //draw x card or cards
        std::regex play("PLAY (\\d+) CARD(\\(S\\))?"); //play x card or cards
        std::smatch format;

        std::cout << "PLAYING ACTION CARD: " << instruction << std::endl; //hpp deinfed this

        if(std::regex_match(instruction, format, play)) //compares instruction with play regex format
        {
            std::string temp = format[1].str(); //gets string like the x in play x cards
            int x = std::stoi(temp); //turns that string to int

            for (int i = 0; i < x; ++i)
            {
                playPointCard(); //plays
            }
        }

        else if(std::regex_match(instruction, format, draw)) //compares instruction with draw regex format
        {
            std::string temp = format[1].str(); //gets string like the x in draw x cards
            int y = std::stoi(temp); //turns that string to int

            for (int i = 0; i < y; ++i)
            {
                // auto y = pointdeck_->Draw(); //not allowed lvalue rvalue issue so combine these two sentences into this
                // hand_.addCard(y);
                //hand_.addCard(pointdeck_->Draw());
                drawPointCard();
            }
        }

        else if(instruction == "SWAP HAND WITH OPPONENT")
        {
            Hand urHand = getHand(); //gets ur hand_ var
            Hand oppHand = opponent_->getHand(); //get opponent hand

            setHand(oppHand); //now ur hand is opponents hand
            opponent_->setHand(urHand); //now opponent hand is ur hand
        }

        else if(instruction == "REVERSE HAND")
        {
            hand_.Reverse(); //simple enough lmao
        }
    }
}

//draw point card into hand
void Player::drawPointCard()
{
    //auto temp = pointdeck_->Draw(); //auto to simplify type, draw from point card store it in temp
    //hand_.addCard(temp); //add that card to hand
    //thats not allowed, lvalue cant be case as rvalue witjout move so combining the two works:
    //if (pointdeck_ != nullptr) //as long as the point deck isnt empty
    //{
        //hand_.addCard(pointdeck_->Draw());
    //}

//     if (pointdeck_ != nullptr && !pointdeck_->IsEmpty())
//     {
//         PointCard&& card = pointdeck_->Draw(); // Draw a card from the point deck // added && for move
//         hand_.addCard(std::move(card)); // Add that card to the player's hand
//     }
    if (pointdeck_ == nullptr)
    {
        return;
    }

    if (pointdeck_->IsEmpty())
    {
        return;
    }

    PointCard&& card = pointdeck_->Draw();
    hand_.addCard(std::move(card));
}

//play point card and update score
void Player::playPointCard()
{
    //if (!hand_.isEmpty() == true) //if hands not empty
    //{
        score_ += hand_.PlayCard();
    //}
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