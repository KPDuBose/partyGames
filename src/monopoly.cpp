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

// [[Rcpp::export]]
List monopoly(
  int turns = 500,
  int sides = 6,
  int numDice = 2
) {
  int space = 1;
  IntegerVector timesLanded;

  for (int n = 1; n < turns; ++n){

  }




  return List::create(
    _["turns"] = turns,
    // _["test"]  = n,
    _["test2"] = space
  );


}









