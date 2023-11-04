#include <iostream>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
//#include "Deck.hpp"

int main()
{
    //!!to test use make rebuild which means isntead of doing g++ -o main (all the .cpp files), u just do make rebuild and it’ll do all that for all files
    //!!after that, executable file called main is created and to run that u do ./main which wil then show u stuff in ur terminal
    
    PointCard pc1;
    PointCard pc2;
    pc1.setInstruction("1");
    pc2.setInstruction("2");
    
    ActionCard ac1;
    ActionCard ac2;
    ac1. setInstruction ("REVERSE HAND"); 
    ac2.setInstruction("SWAP HAND WITH OPPONENT");

    std::cout << "pc1 isPlayable: " << pc1.isPlayable() << std::endl;

    // Deck<PointCard> pdeck;
    // Deck<ActionCard> adeck;

    // pdeck. AddCard (pc1);
    // pdeck. AddCard (pc2);
    // adeck. AddCard (ac1);
    // adeck. AddCard (ac2);

    // for (int i=0; i < pdeck.getSizel); i++) 
    // {
    //     PointCard card = pdeck.Draw();
    //     card. Print ();
    // }
    
    // for (int i=0; i < adeck.getSize(); i++) 
    // {
    //     ActionCard card = adeck. Draw();
    //     card.Print ();
    // }
}