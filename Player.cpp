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
    score_ = 0;
    // V1 hand_ = Hand(); //call constructor
    opponent_ = nullptr;
    // V1 actiondeck_ = new Deck<ActionCard>();
    actiondeck_ = nullptr;
    // V1 pointdeck_ = new Deck<PointCard>();]
    pointdeck_ = nullptr;
}

//destructor
Player::~Player()
{
    // V1 delete actiondeck_;
    // V1 delete pointdeck_; //dynamic mem allocation taking place need to use delete keyword cause u initialzied with new
    delete actiondeck_;
    // V2 actiondeck_ = nullptr; //u can have this or not
    delete pointdeck_;
    // V2 pointdeck_ = nullptr;
    delete opponent_;
    //V2 opponent_ = nullptr;
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
    //Below is V1 but V2 also works
    std::string instruct = card.getInstruction(); //get instruction store it in instruct
    std::cout << "PLAYING ACTION CARD: " << instruct << std::endl; //print that like the hpp asks u to do
    std::regex draw("DRAW (\\d+) CARD(S)?"); //this is the draw format
    std::regex play("PLAY (\\d+) CARD(S)?"); //this is the play format
    std::smatch format; //format is format

    if(std::regex_search(instruct, format, play)) //match instruct w play format and if its a match then enter
    {
        int a = std::stoi(format[1].str()); //remember instructieons were ins tring so convert them into int
        for (int i = 0; i < a; ++i) 
        {
            if(hand_.isEmpty()) //empty? draw it then but no empty? play it then
            {
                drawPointCard(); //if ur hands empty first draw it
            }
            playPointCard(); //then play it
        }
    } 
    
    else if(std::regex_search(instruct, format, draw)) //if ur here it didnt match w play sotry matching w draw format and if its a match then enter
    {
        int z = std::stoi(format[1].str()); //remember instructieons were ins tring so convert them into int
        for (int i = 0; i < z; ++i) 
        {
            drawPointCard(); //draw
        }
    } 
    
    else if(instruct == "SWAP HAND WITH OPPONENT") //if ur here none of the formats matched so maybe its a swap
    {
        if (opponent_) 
        {
            Hand oppHand = opponent_->getHand(); //basic swap, can also use std::swap i beleive
            opponent_->setHand(this->getHand());
            this->setHand(oppHand);
        }
    } 
    
    else if(instruct == "REVERSE HAND") //if ur here nothing else matched so its a reverse which u implemented earlier so call that
    {
        hand_.Reverse();
    }
    
    //V2 ALSO WORKS
    // card.setDrawn(true); //draw the card 

    // if (card.isPlayable()) //first figure out if u can play the card
    // {
    //     std::string instruction = card.getInstruction(); //get the instruction store in instruction variable
    //     std::regex draw("DRAW (\\d+) CARD(\\(S\\))?"); //draw x card or cards
    //     std::regex play("PLAY (\\d+) CARD(\\(S\\))?"); //play x card or cards
    //     std::smatch format;

    //     std::cout << "PLAYING ACTION CARD: " << instruction << std::endl; //hpp deinfed this

    //     if(std::regex_match(instruction, format, play)) //compares instruction with play regex format
    //     {
    //         std::string temp = format[1].str(); //gets string like the x in play x cards
    //         int x = std::stoi(temp); //turns that string to int

    //         for (int i = 0; i < x; ++i)
    //         {
    //             playPointCard(); //plays
    //         }
    //     }

    //     else if(std::regex_match(instruction, format, draw)) //compares instruction with draw regex format
    //     {
    //         std::string temp = format[1].str(); //gets string like the x in draw x cards
    //         int y = std::stoi(temp); //turns that string to int

    //         for (int i = 0; i < y; ++i)
    //         {
    //             // auto y = pointdeck_->Draw(); //not allowed lvalue rvalue issue so combine these two sentences into this
    //             // hand_.addCard(y);
    //             //hand_.addCard(pointdeck_->Draw());
    //             drawPointCard();
    //         }
    //     }

    //     else if(instruction == "SWAP HAND WITH OPPONENT")
    //     {
    //         Hand urHand = getHand(); //gets ur hand_ var
    //         Hand oppHand = opponent_->getHand(); //get opponent hand

    //         setHand(oppHand); //now ur hand is opponents hand
    //         opponent_->setHand(urHand); //now opponent hand is ur hand
    //     }

    //     else if(instruction == "REVERSE HAND")
    //     {
    //         hand_.Reverse(); //simple enough lmao
    //     }
    // }
}

//draw point card into hand
void Player::drawPointCard()
{
    //V1
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
//          PointCard card = pointdeck_->Draw(); // Draw a card from the point deck
//         hand_.addCard(std::move(card)); // Add that card to the player's hand
//     }
    // if (pointdeck_ == nullptr)
    // {
    //     return;
    // }

    // if (pointdeck_->IsEmpty())
    // {
    //     return;
    // }

    //PointCard&& card = pointdeck_->Draw(); //DECK works
    // PointCard card = pointdeck_->Draw(); //PLAYER works

    // hand_.addCard(std::move(card));

    //SIMPLIFIED V1 INTO V2, BETTER EFFICIENTLY AND SIMPLER TO UNDERSTAND LMOA
    if (pointdeck_ != nullptr && !pointdeck_->IsEmpty ()) //combine the two conditions
    {
        PointCard card = pointdeck_->Draw();
        hand_.addCard(std::move(card));
    }
}

//play point card and update score
void Player::playPointCard()
{
    if (!hand_.isEmpty() == true) //if hands not empty
    {
        score_ += hand_.PlayCard();
    }
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