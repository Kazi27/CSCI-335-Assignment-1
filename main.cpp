#include <iostream>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"

int main() 
{
    PointCard pc1;
    PointCard pc2;
    pc1.setInstruction("1");
    pc2.setInstruction("2");

    ActionCard ac1;
    ActionCard ac2;
    ActionCard ac3;
    ActionCard ac4;
    ac2.setInstruction("REVERSE HAND");
    ac1.setInstruction("SWAP HAND WITH OPPONENT");
    ac3.setInstruction("DRAW 3 CARD(S)");
    ac4.setInstruction("PLAY 6 CARD(S)");
    //std::cout << ac2.getInstruction() << std::endl;

    Deck<PointCard> pdeck;
    Deck<ActionCard> adeck;

    pdeck.AddCard(pc1);
    pdeck.AddCard(pc2);

    adeck.AddCard(ac1);
    adeck.AddCard(ac2);
    adeck.AddCard(ac3);
    adeck.AddCard(ac4);

    std::cout << adeck.getSize() << std::endl;
    adeck.Shuffle();

    int adeckSize = adeck.getSize();
    for (int i=0; i < adeckSize; i++) {
        ActionCard card = adeck.Draw();
        card.Print();
        std::cout << std::endl;
    }
    std::cout << adeck.getSize() << std::endl;

    for (const ActionCard& card : adeck.getDeck()) {
        card.Print();
        std::cout << std::endl;
    }

    return 0;
}