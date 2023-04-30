#' Simulates multiple single-player Monopoly Games
#'
#' A general function to simulate various multiple single-player Monopoly games.
#'
#' This function uses Open MP to parallelize code and run a few different games
#' at the same time.
#'
#' @seealso [monopoly()]
#'
#' @param numGames Number of games to be played
#' @param maxTurns Max number of turns to be played
#' @param sides Number of sides on dice
#' @param numDice Number of dice rolled
#' @param cores Number of cores to be used
#'
#' @return A matrix of class `monopoly`
#'
#' @export
simulateMonopoly <- function(
    numGames = 10,
    maxTurns = 500,
    sides = 6,
    numDice = 2,
    cores = 1){
 ans <- simMonopoly(numGames, maxTurns, sides, numDice, cores)
 ans <- structure(ans, class = "monopoly")

 return(ans)
}
