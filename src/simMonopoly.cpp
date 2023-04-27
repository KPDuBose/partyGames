#include <omp.h>
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::plugins(openmp)]]


List monopoly(int maxTurns, int sides, int numDice);

// [[Rcpp::export]]
List simMonopoly(
    int numGames,
    int maxTurns,
    int sides,
    int numDice,
    int cores = 1
) {
  List results(numGames);
  // List finalResults;

  // setting the cores
  omp_set_num_threads(cores);

#pragma omp parallel for shared(numGames, maxTurns, sides, numDice, results) default(none)
  for (int i = 0; i < numGames; i++){
    results[i] = monopoly(maxTurns, sides, numDice);
  }

  return results;

}
