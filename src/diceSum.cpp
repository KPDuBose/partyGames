#include <Rcpp.h>
using namespace Rcpp;

//'Roll a dice
//'
//'This function rolls dice and returns the sum of the dice.
//'
//'@name diceSum
//'
//'
//'@param sides An integer representing the number of sides on the dice
//'@param numDice The number of dice of size 'sides' to be rolled
//'@return A number.
//'@examples
//'diceSum(6,1)
//'diceSum(6,2)
//'diceSum(100,2)
//'@export
// [[Rcpp::export]]
int diceSum(
    int sides,
    int numDice
) {
  IntegerVector roll = sample(sides, numDice, true);

  int sumDice = sum(roll);

  return sumDice;
}
