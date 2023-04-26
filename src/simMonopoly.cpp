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
  List results;
  List finalResults;

  // setting the cores
  omp_set_num_threads(cores);

#pragma omp parallel for private(numGames, maxTurns, sides, numDice, i) default(none)
  for (int i = 0; i < numGames; ++i){
    results = monopoly(maxTurns, sides, numDice);
    finalResults.push_back(results);
  }

  return results;

}
