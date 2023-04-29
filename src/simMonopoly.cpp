#include <omp.h>
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(openmp)]]


arma::mat monopoly(int maxTurns, int sides, int numDice);

// [[Rcpp::export]]
arma::mat simMonopoly(
    arma::uword numGames = 10,
    int maxTurns = 500,
    int sides = 6,
    int numDice = 2,
    int cores = 1
) {
  arma::mat results(numGames, 40);
  arma::mat game(2, 40);

  // setting the cores
  omp_set_num_threads(cores);

#pragma omp parallel for shared(numGames, maxTurns, sides, numDice, results) firstprivate(game) default(none)
  for (arma::uword i = 0; i < numGames; i++){
    game = monopoly(maxTurns, sides, numDice);
    results.row(i) = game.row(1);
  }

  return results;

}
