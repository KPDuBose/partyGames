#include <Rcpp.h>
using namespace Rcpp;


//'Play a White Elephant Game with two coins
//'
//'Simulates a White Elephant party game. The gift starts at position "1" and
//'each player rolls dice and flips a randomly chosen coin from two available.
//'If the coin is heads, the present gets passed one to the left. If tails, the
//'present gets passed one to the right.
//'
//'
//'@name twoCoinElephant
//'
//'
//'@param n Number of participants in the game
//'@param pheads1 The probability of heads, or passing the present to the left if using the first coin
//'@param pheads2 The probability of heads, or passing the present to the left if using the second coin
//'
//'@return A list containing the final position of the present and a vector
//'representing the movement of the present, where negative numbers represent
//'movement to the left and positive number represent movement to the right.
//'
//'@examples
//'# 10 people playing with a fair coin and an unfair coin
//'twoCoinElephant(10, 0.5, 0.7)
//'
//'# 20 people playing with two unfair coins (pheads1 = 0.3, pheads2 = 0.7)
//'twoCoinElephant(20, 0.3, 0.7)
//'
//'@export


 // [[Rcpp::export]]
 List twoCoinElephant(
     int n,
     double pheads1,
     double pheads2
 ){
   int player = 1;
   int flip = 0;

   double pheads = 0;

   NumericVector coins = {pheads1, pheads2};

   IntegerVector leftRight = {-1, 1};

   IntegerVector movement(n);

   for (int i = 0; i < n; ++i){
     pheads = Rcpp::sample(coins, 1, true)[0];
     NumericVector probs = {pheads, 1 - pheads};
     flip = Rcpp::sample(leftRight, 1, true, probs)[0];
     movement[i] = flip;
     player = player + flip;
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
