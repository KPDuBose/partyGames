#include <omp.h>
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(openmp)]]


arma::mat monopoly(int maxTurns, int sides, int numDice);

// // [[Rcpp::export]]
// arma::vec monoVec(int maxTurn, int sides, int numDice){
//   List mono = monopoly(maxTurn, sides, numDice);
//
//   arma::colvec monopolyVec = mono[1];
//
//   return monopolyVec;
// }

// // [[Rcpp::export]]
// List simMonopoly(
//     int numGames,
//     int maxTurns,
//     int sides,
//     int numDice,
//     int cores = 1
// ) {
//   arma::vec results(numGames);
//
//   arma::mat game(numGames);
//
//   // setting the cores
//   omp_set_num_threads(cores);
//
// #pragma omp parallel for firstprivate(numGames, maxTurns, sides, numDice, results, game) default(none)
//   for (int i = 0; i < numGames; i++){
//     results = monoVec(maxTurns, sides, numDice);
//     game[i] = results;
//
//
//   }
//
//   return game;
//
// }



