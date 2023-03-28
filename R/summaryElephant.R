#' Summarize a simulation
#'
#' A general function to summarize a simulation of white elephant games.
#'
#' @param object An object of class `elphList` to be summarized
#' @param ... Additional arguments affecting the summary produced
#'
#' @return An object of class `elphSum` containing a table of moves over a
#' simulation and a table of times each chair won.
#' @export summary.partyGames
#' @export
#'
summary.partyGames <- function(object, ...){
  if (inherits(object, "elphList")){

  moves <- sapply(object, "[[", "moves")

  moves <- table(moves)

  winner <- sapply(object, "[[", "winner")

  winner <- table(winner)

  elphSum <- list(winner = winner, moves = moves)

  elphSum <- structure(elphSum, class = c("elphSum", "list"))

  return(elphSum)

  }

}

