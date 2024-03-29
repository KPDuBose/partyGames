#include <Rcpp.h>
using namespace Rcpp;

//'Simulate rolling a dice and getting the sum
//'
//'This function rolls dice and returns the sum of the dice. The default function
//'rolls two six-sided dice.
//'
//'@name diceSum
//'
//'
//'@param sides An integer representing the number of sides on the dice
//'@param numDice The number of dice of size 'sides' to be rolled
//'@return A number representing the sum of the dice rolled.
//'@examples
//'diceSum(6,1)
//'diceSum(6,2)
//'diceSum(100,2)
//'@export
// [[Rcpp::export]]
int diceSum(
    int sides = 6,
    int numDice = 2
) {
  IntegerVector roll = sample(sides, numDice, true);

  int sumDice = sum(roll);

  return sumDice;
}
