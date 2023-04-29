#ifdef _OPENMP
#include <omp.h>
#endif


#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(openmp)]]


arma::mat monopoly(int maxTurns, int sides, int numDice);

// [[Rcpp::export]]
std::vector< std::vector< int > > simMonopoly(
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
  int sums = 0u;
  for (int i = 0; i < effective_ncores; i++){
    nreplicates[i] = static_cast<int>(std::floor(numGames/effective_ncores));

    nreplicates_csum[i] = sums;

    sums += nreplicates[i];
  }

  if (sums < numGames) nreplicates[effective_ncores - 1] += (numGames - sums);

#pragma omp parallel for shared(numGames, nreplicates, effective_ncores, maxTurns, sides, numDice, results) default(none)
{
    auto thd = omp_get_thread_num();
    for (int i = 0; i < nreplicates[thd]; i++){
      arma::mat game = monopoly(maxTurns, sides, numDice);

      arma::rowvec gamerow = game.row(1);

      std::vector<int> vec(gamerow.begin(), gamerow.end());

      for (int j = 0; j < 40; j++){

        results[i][j] += vec[j];
      }
    }
 }


  return results;

}

