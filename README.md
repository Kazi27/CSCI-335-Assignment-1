# CSCI-335-Assignment-1
A program in C++ using OOP principles and efficient linear data structures to implement a simple card game. 
The game consists of various classes, including `Card`, `ActionCard`, `PointCard`, `Hand`, `Deck`, and `Player`, each of which plays a specific role in the game -- which requires no user input at all.

## Table of Contents
- [Card](#card)
- [ActionCard](#actioncard)
- [PointCard](#pointcard)
- [Hand](#hand)
- [Deck](#deck)
- [Player](#player)

## Card
`Card` is the base class for all the cards in the game. It defines the common attributes and methods for both `ActionCard` and `PointCard` like cardtype, instruction, drawn status and bitmap for the image data. It has the big 5 implemented as well as various getters and setters for the private data members.

## ActionCard
`ActionCard` is a derived class of `Card` and represents cards that have specific actions or instructions. These cards can be played under certain conditions. The class has additional methods for determining playability and printing the card details as well as the constructor.

## PointCard
`PointCard` is another derived class of `Card`, representing cards with point values. Like `ActionCard`, it can be played under specific conditions, has a print and isplayable function aswell as a constructor.

## Hand
`Hand` represents the player's hand, which contains a collection of cards. It has methods for managing the cards in the hand, such as adding, playing, and reversing the order of cards. It has a efault Constructor that initializes an empty hand, a function called addcard that adds a point card to the hand, isempty that checks if hand is empty, reverse that reverses order of the cards and playcard that plays the front card and returns value of the point card.

## Deck
`Deck` represents a collection of cards that can be drawn and shuffled. It contains methods for adding cards, drawing cards, checking if it's empty, shuffling, getting the deck's size, and getting the vector of cards by calling on isempty, draw, shuffle, getsize or deck as well as the default constructor.

## Player
`Player` represents a player in the card game. It manages the player's hand, score, opponent, action deck, and point deck. The class has methods for playing action cards, drawing point cards, and updating the player's score. It has a constructor with default values, destructor for dynamic memory allocation, various getters and setters, playing action/point card and updating score based on the played point card. 

# How to Play the Game
1. Create two players.
2. Create action and point decks and populate them with cards.
3. Shuffle the action and point decks.
4. Deal a hand of cards to each player.
5. Players take turns playing action cards and drawing point cards.
6. The game continues until a winning condition is met.
7. A main and make file is attached that was used to test.
