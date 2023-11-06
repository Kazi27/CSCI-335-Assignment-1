#include <iostream>
#include <string>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Player.hpp"

bool hasHiddenCharacters(const std::string& str);

int main() {
    PointCard pc1;
    PointCard pc2;
    PointCard pc3;
    PointCard pc4;
    PointCard pc5;
    PointCard pc6;
    PointCard pc7;
    PointCard pc8;
    pc1.setInstruction("1");
    pc2.setInstruction("2");
    pc3.setInstruction("3");
    pc4.setInstruction("4");
    pc5.setInstruction("5");
    pc6.setInstruction("6");
    pc7.setInstruction("7");
    pc8.setInstruction("8");

    ActionCard ac1;
    ActionCard ac2;
    ActionCard ac3;
    ActionCard ac4;
    ac1.setInstruction("REVERSE HAND");
    ac2.setInstruction("SWAP HAND WITH OPPONENT");
    ac3.setInstruction("DRAW 3 CARD(S)");
    ac4.setInstruction("PLAY 2 CARD(S)");
    //std::cout << ac2.getInstruction() << std::endl;

    Deck<PointCard> pdeck;
    Deck<ActionCard> adeck;

    pdeck.AddCard(pc1);
    pdeck.AddCard(pc2);
    pdeck.AddCard(pc3);
    pdeck.AddCard(pc4);
    pdeck.AddCard(pc5);
    pdeck.AddCard(pc6);
    pdeck.AddCard(pc7);
    pdeck.AddCard(pc8);

    adeck.AddCard(ac1);
    adeck.AddCard(ac2);
    adeck.AddCard(ac3);
    adeck.AddCard(ac4);

    Player player1;
    Hand hand1;
    Player player2;
    Hand hand2;
    
    player1.setHand(hand1);
    player1.setOpponent(&player2);
    player1.setPointDeck(&pdeck);
    player1.setActionDeck(&adeck);

    player2.setHand(hand2);
    player2.setOpponent(&player1);
    player2.setPointDeck(&pdeck);
    player2.setActionDeck(&adeck);

    std::cout << "Initial Scores:" << "\n";
    std::cout << player1.getScore() << "\n";
    std::cout << player2.getScore() << "\n";

    player1.play(std::move(ac3));
    player2.play(std::move(ac3));
    player1.play(std::move(ac1));
    player2.play(std::move(ac1));
    
    player1.play(std::move(ac2));

    player1.play(std::move(ac4));
    player2.play(std::move(ac4));

    std::cout << "Updated Scores:" << "\n";
    std::cout << player1.getScore() << "\n";
    std::cout << player2.getScore() << "\n";

    player1.play(std::move(ac3));
    //player2.play(std::move(ac3));

    player1.play(std::move(ac4));
    player1.play(std::move(ac4));

    std::cout << "Updated Scores:" << "\n";
    std::cout << player1.getScore() << "\n";
    std::cout << player2.getScore() << "\n";

    return 0;
}