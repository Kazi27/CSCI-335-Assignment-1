# CSCI-335-Assignment-1
A program in C++ using OOP principles and efficient linear data structures to implement a simple card game. 
The game consists of various classes, including Card, ActionCard, PointCard, Hand, Deck, and Player, each of which plays a specific role in the game -- which requires no user input at all.

# Card Game Readme

This is the readme for the Card Game implemented in C++ for the CSCI335 Fall 2023 course. The game consists of various classes, including `Card`, `ActionCard`, `PointCard`, `Hand`, `Deck`, and `Player`, each of which plays a specific role in the game. The primary objective of this game is to manage and play cards with different types and instructions.

## Table of Contents
- [Card](#card)
- [ActionCard](#actioncard)
- [PointCard](#pointcard)
- [Hand](#hand)
- [Deck](#deck)
- [Player](#player)

## Card
`Card` is the base class for all the cards in the game. It defines the common attributes and methods for both `ActionCard` and `PointCard`. These attributes include:
- `cardType_`: An enumeration representing the card type, which can be either `POINT_CARD` or `ACTION_CARD`.
- `instruction_`: A string containing the instructions or description of the card.
- `drawn_`: A boolean indicating whether the card has been drawn.
- `bitmap_`: An integer pointer that can be used to store image data for the card.

### Constructors
- Default Constructor: Initializes the card with default values.
- Copy Constructor: Copies the attributes of another card.
- Copy Assignment Operator: Assigns the attributes of another card.
- Move Constructor: Moves the attributes of another card.
- Move Assignment Operator: Assigns the attributes of another card using a move operation.

### Methods
- `getType()`: Returns the type of the card.
- `setType(const CardType& type)`: Sets the card type.
- `getInstruction()`: Returns the instruction of the card.
- `setInstruction(const std::string& instruction)`: Sets the instruction.
- `getImageData()`: Returns a pointer to the image data.
- `setImageData(int* data)`: Sets the image data.
- `getDrawn()`: Returns the drawn status of the card.
- `setDrawn(const bool& drawn)`: Sets the drawn status.

## ActionCard
`ActionCard` is a derived class of `Card` and represents cards that have specific actions or instructions. These cards can be played under certain conditions. The class has additional methods for determining playability and printing the card details.

### Constructors
- Default Constructor: Initializes an action card.
- Additional Constructors: The class inherits constructors from the base `Card` class.

### Methods
- `isPlayable()`: Checks whether the action card is playable based on its instruction.
- `Print()`: Displays the card type, instruction, and image data if available.

## PointCard
`PointCard` is another derived class of `Card`, representing cards with point values. Like `ActionCard`, it can be played under specific conditions.

### Constructors
- Default Constructor: Initializes a point card.
- Additional Constructors: Inherited from the base `Card` class.

### Methods
- `isPlayable()`: Checks whether the point card is playable based on its point value.
- `Print()`: Displays the card type, point value, and image data if available.

## Hand
`Hand` represents the player's hand, which contains a collection of cards. It has methods for managing the cards in the hand, such as adding, playing, and reversing the order of cards.

### Constructors
- Default Constructor: Initializes an empty hand.

### Methods
- `addCard(PointCard&& card)`: Adds a point card to the hand.
- `isEmpty()`: Checks if the hand is empty.
- `Reverse()`: Reverses the order of cards in the hand.
- `PlayCard()`: Plays the front card of the hand and returns the point value.

## Deck
`Deck` represents a collection of cards that can be drawn and shuffled. It contains methods for adding cards, drawing cards, checking if it's empty, shuffling, getting the deck's size, and getting the vector of cards.

### Constructors
- Default Constructor: Initializes an empty deck.

### Methods
- `AddCard(const CardType& card)`: Adds a card to the deck.
- `IsEmpty()`: Checks if the deck is empty.
- `Draw()`: Draws a card from the deck.
- `Shuffle()`: Shuffles the cards in the deck.
- `getSize()`: Returns the size of the deck.
- `getDeck()`: Returns a vector of the cards in the deck.

## Player
`Player` represents a player in the card game. It manages the player's hand, score, opponent, action deck, and point deck. The class has methods for playing action cards, drawing point cards, and updating the player's score.

### Constructors
- Default Constructor: Initializes a player with default values.
- Destructor: Frees the memory associated with action and point decks and the opponent.

### Methods
- `getHand()`: Returns the player's hand.
- `setHand(const Hand& hand)`: Sets the player's hand.
- `getScore()`: Returns the player's score

.
- `setScore(const int& score)`: Sets the player's score.
- `getActionDeck()`: Returns the player's action deck.
- `setActionDeck(const Deck& actionDeck)`: Sets the player's action deck.
- `getPointDeck()`: Returns the player's point deck.
- `setPointDeck(const Deck& pointDeck)`: Sets the player's point deck.
- `getOpponent()`: Returns the player's opponent.
- `setOpponent(Player* opponent)`: Sets the player's opponent.
- `PlayActionCard()`: Plays an action card from the action deck.
- `DrawPointCard()`: Draws a point card from the point deck.
- `UpdateScore(int score)`: Updates the player's score based on the played point card.

## How to Play the Game
1. Create two players.
2. Create action and point decks and populate them with cards.
3. Shuffle the action and point decks.
4. Deal a hand of cards to each player.
5. Players take turns playing action cards and drawing point cards.
6. The game continues until a winning condition is met.

Enjoy playing the card game!

If you have any questions or encounter issues with the game, please contact the game developer at developer@email.com.

Happy gaming!