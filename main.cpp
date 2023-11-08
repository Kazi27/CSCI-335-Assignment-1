#include <iostream>
#include <string>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Player.hpp"

int main() 
{
    PointCard pc1;
    ActionCard ac1;
    PointCard pc2;
    ActionCard ac2;
    PointCard pc3;
    ActionCard ac3;
    PointCard pc4;
    ActionCard ac4;
    
    pc1.setInstruction("1");
    ac1.setInstruction("REVERSE HAND");
    pc2.setInstruction("2");
     ac2.setInstruction("SWAP HAND WITH OPPONENT");
    pc3.setInstruction("3");
    ac3.setInstruction("DRAW 3 CARD(S)");
    pc4.setInstruction("4");
    ac4.setInstruction("PLAY 2 CARD(S)");

    Deck<PointCard> pdeck;
    Deck<ActionCard> actionDeck;

    pdeck.AddCard(pc1);
    actionDeck.AddCard(ac1);
    pdeck.AddCard(pc2);
    actionDeck.AddCard(ac2);
    pdeck.AddCard(pc3);
    actionDeck.AddCard(ac3);
    pdeck.AddCard(pc4);
    actionDeck.AddCard(ac4);

    Player kazi;
    Hand hand1;
    Player anwar;
    Hand hand2;
    
    kazi.setHand(hand1);
    anwar.setHand(hand2);
    kazi.setOpponent(&anwar);
    anwar.setOpponent(&kazi);
    kazi.setPointDeck(&pdeck);
    anwar.setPointDeck(&pdeck);
    kazi.setActionDeck(&actionDeck);
    anwar.setActionDeck(&actionDeck);

    std::cout << "Initial Scores:" << "\n" << kazi.getScore() << "\n" << anwar.getScore() << "\n";

    kazi.play(std::move(ac3));
    anwar.play(std::move(ac3));
    kazi.play(std::move(ac1));
    anwar.play(std::move(ac1));
    kazi.play(std::move(ac2));
    kazi.play(std::move(ac4));
    anwar.play(std::move(ac4));

    std::cout << "Updated Scores:" << "\n" << kazi.getScore() << "\n" << anwar.getScore() << "\n";

    kazi.play(std::move(ac3));
    kazi.play(std::move(ac4));
    anwar.play(std::move(ac3));
    kazi.play(std::move(ac4));

    std::cout << "Updated Scores:" << "\n" << kazi.getScore() << "\n" << anwar.getScore() << "\n";
    return 0;
}