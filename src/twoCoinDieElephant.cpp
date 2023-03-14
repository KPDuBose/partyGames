#include <Rcpp.h>
using namespace Rcpp;


//'Play a White Elephant Game with dice and a coin
//'
//'Simulates a White Elephant party game. The gift starts at position "1" and
//'each player rolls dice and flips a randomly chosen coin from two available.
//'If the coin is heads, the present gets passed to the left however many seats
//'the dice have shown. If the coin is tails, the present gets passed to the
//'right however many seats the dice show.
//'
//'
//'@name twoCoinDieElephant
//'
//'
//'@param n Number of participants in the game
//'@param pheads1 The probability of heads, or passing the present to the left if using the first coin
//'@param pheads2 The probability of heads, or passing the present to the left if using the second coin
//'@param sides Number of sides on the dice
//'@param numDice Number of dice to be rolled
//'
//'@return A list containing the final position of the present and a vector
//'representing the movement of the present, where negative numbers represent
//'movement to the left and positive number represent movement to the right.
//'
//'@examples
//'# 10 people playing with a six sided dice and a fair coin
//'lrDieElephant(10, 0.5, 6, 1)
//'
//'# 20 people playing with two six-sided dice and an unfair coin (pheads = 0.7)
//'lrDieElephant(20, 0.7, 6, 2)
//'
//'@export


 int diceSum(int sides, int numDice);


 // [[Rcpp::export]]
 List twoCoinDieElephant(
     int n,
     double pheads1,
     double pheads2,
     int sides,
     int numDice
 ){
   int player = 1;
   int roll = 0;
   int flip = 0;

   double pheads = 0;

   NumericVector coins = {pheads1, pheads2};

   IntegerVector leftRight = {-1, 1};

   IntegerVector movement(n);

    for (int i = 0; i < n; ++i){
     roll = diceSum(sides, numDice);
     pheads = Rcpp::sample(coins, 1, true)[0];
     NumericVector probs = {pheads, 1 - pheads};
     flip = Rcpp::sample(leftRight, 1, true, probs)[0];
     movement[i] = roll * flip;
     player = player + roll * flip;
   }


   while (player > n){
     player = player - n;
   }

   while (player <= 0){
     player = player + n;
   }

   return List::create(
     _["moves"] = movement,
     _["winner"] = player
   );

 }
