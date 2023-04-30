// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// diceRoll
IntegerVector diceRoll(int sides, int numDice);
RcppExport SEXP _partyGames_diceRoll(SEXP sidesSEXP, SEXP numDiceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    rcpp_result_gen = Rcpp::wrap(diceRoll(sides, numDice));
    return rcpp_result_gen;
END_RCPP
}
// diceSum
int diceSum(int sides, int numDice);
RcppExport SEXP _partyGames_diceSum(SEXP sidesSEXP, SEXP numDiceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    rcpp_result_gen = Rcpp::wrap(diceSum(sides, numDice));
    return rcpp_result_gen;
END_RCPP
}
// dieElephant
List dieElephant(int n, int sides, int numDice);
RcppExport SEXP _partyGames_dieElephant(SEXP nSEXP, SEXP sidesSEXP, SEXP numDiceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    rcpp_result_gen = Rcpp::wrap(dieElephant(n, sides, numDice));
    return rcpp_result_gen;
END_RCPP
}
// leftRightElephant
List leftRightElephant(int n, double pheads);
RcppExport SEXP _partyGames_leftRightElephant(SEXP nSEXP, SEXP pheadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type pheads(pheadsSEXP);
    rcpp_result_gen = Rcpp::wrap(leftRightElephant(n, pheads));
    return rcpp_result_gen;
END_RCPP
}
// lrDieElephant
List lrDieElephant(int n, double pheads, int sides, int numDice);
RcppExport SEXP _partyGames_lrDieElephant(SEXP nSEXP, SEXP pheadsSEXP, SEXP sidesSEXP, SEXP numDiceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type pheads(pheadsSEXP);
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    rcpp_result_gen = Rcpp::wrap(lrDieElephant(n, pheads, sides, numDice));
    return rcpp_result_gen;
END_RCPP
}
// monopoly
arma::mat monopoly(int maxTurns, int sides, int numDice);
RcppExport SEXP _partyGames_monopoly(SEXP maxTurnsSEXP, SEXP sidesSEXP, SEXP numDiceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type maxTurns(maxTurnsSEXP);
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    rcpp_result_gen = Rcpp::wrap(monopoly(maxTurns, sides, numDice));
    return rcpp_result_gen;
END_RCPP
}
// simMonopoly
std::vector < std::vector< int > > simMonopoly(int numGames, int maxTurns, int sides, int numDice, int cores);
RcppExport SEXP _partyGames_simMonopoly(SEXP numGamesSEXP, SEXP maxTurnsSEXP, SEXP sidesSEXP, SEXP numDiceSEXP, SEXP coresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type numGames(numGamesSEXP);
    Rcpp::traits::input_parameter< int >::type maxTurns(maxTurnsSEXP);
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    Rcpp::traits::input_parameter< int >::type cores(coresSEXP);
    rcpp_result_gen = Rcpp::wrap(simMonopoly(numGames, maxTurns, sides, numDice, cores));
    return rcpp_result_gen;
END_RCPP
}
// twoCoinDieElephant
List twoCoinDieElephant(int n, double pheads1, double pheads2, int sides, int numDice);
RcppExport SEXP _partyGames_twoCoinDieElephant(SEXP nSEXP, SEXP pheads1SEXP, SEXP pheads2SEXP, SEXP sidesSEXP, SEXP numDiceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type pheads1(pheads1SEXP);
    Rcpp::traits::input_parameter< double >::type pheads2(pheads2SEXP);
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    rcpp_result_gen = Rcpp::wrap(twoCoinDieElephant(n, pheads1, pheads2, sides, numDice));
    return rcpp_result_gen;
END_RCPP
}
// twoCoinElephant
List twoCoinElephant(int n, double pheads1, double pheads2);
RcppExport SEXP _partyGames_twoCoinElephant(SEXP nSEXP, SEXP pheads1SEXP, SEXP pheads2SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type pheads1(pheads1SEXP);
    Rcpp::traits::input_parameter< double >::type pheads2(pheads2SEXP);
    rcpp_result_gen = Rcpp::wrap(twoCoinElephant(n, pheads1, pheads2));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_partyGames_diceRoll", (DL_FUNC) &_partyGames_diceRoll, 2},
    {"_partyGames_diceSum", (DL_FUNC) &_partyGames_diceSum, 2},
    {"_partyGames_dieElephant", (DL_FUNC) &_partyGames_dieElephant, 3},
    {"_partyGames_leftRightElephant", (DL_FUNC) &_partyGames_leftRightElephant, 2},
    {"_partyGames_lrDieElephant", (DL_FUNC) &_partyGames_lrDieElephant, 4},
    {"_partyGames_monopoly", (DL_FUNC) &_partyGames_monopoly, 3},
    {"_partyGames_simMonopoly", (DL_FUNC) &_partyGames_simMonopoly, 5},
    {"_partyGames_twoCoinDieElephant", (DL_FUNC) &_partyGames_twoCoinDieElephant, 5},
    {"_partyGames_twoCoinElephant", (DL_FUNC) &_partyGames_twoCoinElephant, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_partyGames(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
