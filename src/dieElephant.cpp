#include <Rcpp.h>
using namespace Rcpp;


//'Play a White Elephant Game
//'
//'Simulates a White Elephant party game. The gift starts at position "1" and
//'each player rolls a dice. For each number rolled, the present moves around the
//'circle that many positions in a counter-clockwise fashion.
//'
//'
//'
//'@name dieElephant
//'
//'
//'@param n Number of participants in the game
//'@param sides Number of sides the dice have
//'@param numDice Number of dice to be rolled
//'
//'@return A list containing the final position of the present and a vector
//'representing the movement of the present.
//'
//'@examples
//'# 10 people playing with a six-sided die
//'dieElephant(10, 6, 1)
//'
//'# 20 people playing with two six-sided dice
//'dieElephant(20, 6, 2)
//'
//'@export


int diceSum(int sides, int numDice);


// [[Rcpp::export]]
List dieElephant(
  int n,
  int sides,
  int numDice
){
  int player = 1;
  // int played = 0;
  int roll = 0;
  IntegerVector movement(n);

  for (int i = 0; i < n; ++i){
    roll = diceSum(sides, numDice);
    movement[i] = roll;
    player = player + roll;
  }


  while (player > n){
    player = player - n;
  }

  return List::create(
    _["moves"] = movement,
    _["winner"] = player
  );

}
