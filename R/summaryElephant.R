#' Summarize a simulation
#'
#' A general function to summarize a simulation of white elephant games.
#'
#' @param sim An object of class `elphList` to be summarized
#'
#' @return An object of class `elphSum` containing a table of moves over a
#' simulation and a table of times each chair won.
#'
#' @export
#'
#'

summaryElephant <- function(sim){
  if (!is(sim, "elphList")) stop("sim must be a 'elphList' class object")

  moves <- sapply(sim, "[[", "moves")

  moves <- table(moves)

  winner <- sapply(sim, "[[", "winner")

  winner <- table(winner)

  elphSum <- list(winner = winner, moves = moves)

  class(elphSum) <- c("elphSum", "list")

  return(elphSum)
}
