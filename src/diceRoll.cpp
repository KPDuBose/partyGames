#include <Rcpp.h>
using namespace Rcpp;

//'Simulate rolling a dice and getting the sum
//'
//'This function rolls dice and returns each different roll of the dice. If
//'asked to roll two dice, this will return a numeric vector representing the
//'value of each dice.
//'
//'@name diceRoll
//'
//'
//'@param sides An integer representing the number of sides on the dice
//'@param numDice The number of dice of size 'sides' to be rolled
//'@return A number representing the sum of the dice rolled.
//'@examples
//'diceRoll(6,1)
//'diceRoll(6,2)
//'diceRoll(100,2)
//'@export
// [[Rcpp::export]]
IntegerVector diceRoll(
  int sides = 6,
  int numDice = 2
){
  IntegerVector roll = sample(sides, numDice, true);

  return roll;
}
