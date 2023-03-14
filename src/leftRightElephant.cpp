#include <Rcpp.h>
using namespace Rcpp;

//'Play a White Elephant Game with a coin
//'
//'Simulates a White Elephant party game. The gift starts at position "1" and
//'proceeds to move around the circle as each person flips a coin. If heads, the
//' present moves to the left. If tails, the present moves to the right.
//'
//'
//'To further elaborate on the rules of the game, if the player in position "1"
//'flips tails, the player to his right is sitting in position "2". If he flips
//'heads, the player to the left of position "1" is sitting in the last position.
//'
//'@name leftRightElephant
//'
//'
//'@param n Number of participants in the game
//'@param pheads The probability of heads, or moving the present to the left. Cannot
//'be a `NULL` value
//'
//'@return A list containing the final position of the present and a vector
//'representing the movement of the present (1 is a pass to the right, and -1
//'is a pass to the left).
//'
//'@examples
//'# 10 people playing with a fair coin
//'leftRightElephant(10, 0.5)
//'
//'# 20 people playing with an unfair coin
//'leftRightElephant(20, 0.9)
//'
//'@export
// [[Rcpp::export]]
 List leftRightElephant(
   int n,
   double pheads
 ){
   if (pheads > 1 || pheads < 0){
     stop("'pheads' must be a value between 0 and 1");
   }

   IntegerVector leftRight = {-1, 1};
   NumericVector probs = {pheads, 1 - pheads};

   IntegerVector movement = Rcpp::sample(leftRight, n, true, probs);

   int seat = 1 + sum(movement);

   while (seat < 1){
     seat = seat + n;
   }

   while (seat > n){
     seat = seat - n;
   }

   return List::create(
     _["movement"] = movement,
     _["winner"] = seat
   );

 }
