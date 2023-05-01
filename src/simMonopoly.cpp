#ifdef _OPENMP
#include <omp.h>
#endif

#include<stdio.h>
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
  std::vector < std::vector< double > > start(effective_ncores);
  std::vector < std::vector< double > > end(effective_ncores);


  int sums = 0u;
  for (int i = 0; i < effective_ncores; i++){
    nreplicates[i] = static_cast<int>(std::floor(numGames/effective_ncores));

    nreplicates_csum[i] = sums;

    sums += nreplicates[i];

  }

  if (sums < numGames) nreplicates[effective_ncores - 1] += (numGames - sums);


  std::vector< std::vector< double > > res(effective_ncores);
  for (int i = 0; i < effective_ncores; ++i)
    res[i].resize(nreplicates[i]*40);

  for (int i = 0; i < effective_ncores; i++){
    start[i].resize(nreplicates);
    end[i].resize(nreplicates);
  }

  for (int i = 0; i < effective_ncores; i++){
    for (int j = 0; i < nreplicates[i]; i++){
      start[i][j] = j * 40;
      end[i][j] = start[i][j] + 40;
    }
  }
#pragma omp parallel shared(start, end, numGames, nreplicates, effective_ncores, maxTurns, sides, numDice, res) default(none)
{

  int iam = omp_get_thread_num();

  for (int i = 0; i < nreplicates[iam]; i++){
    for (int j = start[iam][i]; j < end[iam][j]; j++){
      for (int k = 0; k < 40; k++) res[iam][j] = monopoly(numGames, sides, numDice)[k];

    }
  }
}

return res;

}

