#' Summarize a simulation of monopoly games
#'
#' A general function to summarize a simulation of white elephant games.
#'
#' @param object An object of class `monopoly` to be summarized
#' @param ... Additional arguments affecting the summary produced
#'
#' @return An object of class `monopoly` containing a table of moves over a
#' simulation and a table of times each chair won.
#' @export summary.monopoly
#' @export
#'
summary.monopoly <- function(object, ...){
  if (inherits(object, "monopoly")){

    n <- length(object)

    monoSum <- t(data.frame(object))

    rownames(monoSum) <- NULL

    colnames(monoSum) <- 1:40

    monoSum <- colSums(monoSum)

    monoSum <- structure(monoSum, class = c("monoSum", "numeric"))

    return(monoSum)

  }

}

