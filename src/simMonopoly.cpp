#ifdef _OPENMP
#include <omp.h>
#endif

#include<random>

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(openmp)]]


std::vector<int> monopoly(int maxTurns, int sides, int numDice);

// [[Rcpp::export]]
std::vector < std::vector< int > > simMonopoly(
    int numGames = 10,
    int maxTurns = 500,
    int sides = 6,
    int numDice = 2,
    int cores = 1
) {
  std::vector < std::vector< int > > results(numGames, std::vector<int>(40));

#ifdef _OPENMP
  // setting the cores
  omp_set_num_threads(cores);
#endif

#ifdef _OPENMP
  int effective_ncores = cores;
#else
  int effective_ncores = 1;
#endif

  std::vector< int > nreplicates(effective_ncores, 0);
  std::vector< int > nreplicates_csum(effective_ncores, 0);
  std::vector< int > start(effective_ncores, 0);
  std::vector< int > end(effective_ncores, numGames);

  int sums = 0u;
  for (int i = 0; i < effective_ncores; i++){
    nreplicates[i] = static_cast<int>(std::floor(numGames/effective_ncores));

    nreplicates_csum[i] = sums;

    sums += nreplicates[i];

  }

  if (sums < numGames) nreplicates[effective_ncores - 1] += (numGames - sums);

  for (int i = 0; i < effective_ncores; i++){
    start[i] = nreplicates_csum[i];
  }

  if (effective_ncores > 1){
  for (int i = 0; i < effective_ncores - 1; i++){
    end[i] = start[i + 1];
  }}


#pragma omp parallel shared(start, end, numGames, effective_ncores, maxTurns, sides, numDice, results) default(none)
{

  int iam = omp_get_thread_num();
  // std::vector<int> gamerow(40);


  for (int i = start[iam]; i < end[iam]; i++){

    // gamerow = monopoly(maxTurns, sides, numDice);

    // std::vector<int> vec(gamerow.begin(), gamerow.end());



      results[i] = monopoly(maxTurns, sides, numDice);
    }
}

return results;

}

