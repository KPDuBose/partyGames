#include <Rcpp.h>
using namespace Rcpp;

//'Play a game of Monopoly under specific circumstances
//'
//'This function allows you to look at and emulate playing a game of Monopoly
//'with a single player. This simulation does not keep track of money or which
//'properties that you buy, but instead rolls dice for a specified number of
//'turns and returns information specifying how many times each space was landed
//'on by the player during the game and how many times doubles were rolled during
//'the game.
//'
//'@name monopoly
//'
//'
//'@param turns An integer representing the max number of turns to be played
//'@param sides An integer representing the size of dice to be rolled. Default is a six sided dice
//'@param numDice The number of dice of size 'sides' to be rolled. Default is two dice.
//'@return A list of two vectors representing the number of times each space was
//'landed on and the number of times doubles were rolled.
//'@export
IntegerVector diceRoll(int sides, int numDice);

IntegerVector chanceCards(int numCards){

  //Shuffle the deck
  IntegerVector chanceDeck = sample(numCards, numCards, false);

  return chanceDeck;

}

// [[Rcpp::export]]
List monopoly(
  int maxTurns = 500,
  int sides = 6,
  int numDice = 2
){
  //Initialize and shuffle the Chance and Community decks
  IntegerVector chance = chanceCards(16);
  IntegerVector community = chanceCards(16);

  //Set locations of the utility spaces and railroad spaces
  IntegerVector utility = {13,29};
  IntegerVector railroads = {6, 16, 26, 36};

  //Set up spaces tracker vector
  IntegerVector spaceTracker;

  //Turn counter
  int count = 0;

  //Double tracker
  int dTrack = 0;

  //Token movement
  int token = 1;

  //Set up turn movements
  while (count < maxTurns){
    count += 1;
    dTrack = 0;

    //Roll the dice
    IntegerVector dice = diceRoll(sides, numDice);
    int roll = sum(dice);

    token += roll;

    //Check if over 40
    while (token > 40){
      token -= 40;
    }

    //Append to spaceTracker
    spaceTracker.push_back(token);

    //Check if rolled doubles
    while(dice[0] == dice[1]){
      dTrack += 1;
      if (dTrack > 2){
        token = 11;
        spaceTracker.push_back(token);
        count += 2; //Misses turns due to being in jail
        break;
      }

      //Roll the dice
      IntegerVector dice = diceRoll(sides, numDice);
      int roll = sum(dice);

      token += roll;

      //Check if over 40
      while (token > 40){
        token -= 40;
      }

      //Append to spaceTracker
      spaceTracker.push_back(token);
    }
  }


  return List::create(
    _["chance"]     = chance,
    _["space"]      = spaceTracker,
    _["utilities"]  = utility,
    _["railroads"]  = railroads,
    _["count"]      = count
  );
}







