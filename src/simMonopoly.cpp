#ifdef _OPENMP
#include <omp.h>
#endif


#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(openmp)]]


arma::mat monopoly(int maxTurns, int sides, int numDice);

// [[Rcpp::export]]
arma::mat simMonopoly(
    int numGames = 10,
    int maxTurns = 500,
    int sides = 6,
    int numDice = 2,
    int cores = 1
) {
  arma::mat results(numGames, 40);

#ifdef _OPENMP
  // setting the cores
  omp_set_num_threads(cores);
#else
  omp_set_num_threads(1);
#endif

#pragma omp parallel for shared(numGames, maxTurns, sides, numDice, results) default(none)
  for (int i = 0; i < numGames; i++){
    arma::mat game = monopoly(maxTurns, sides, numDice);

    results.row(i) = game.row(1);

}
  return results;

}

