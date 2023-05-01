#' Plot results of a Monopoly simulation
#'
#' A general function to plot the results of a White Elephant simulation.
#'
#' @param x An object of class `monopoly` or `monoSum` to be summarized
#' @param ... Additional arguments in `plot` function
#'
#' @return A plot showing the distribution of each winning seat and how often they won.
#'
#' @export plot.monopoly
#' @export
plot.monopoly <- function(x, ...){
  if(inherits(x, "monopoly") | inherits(x, "monoSum")){

    if(inherits(x, "monopoly")){
      x <- summary.monopoly(x)
    }

    graphics::barplot(
      as.numeric(x),
      ylim = c(0, max(x) + 25),
      sub = sprintf("Distribution of simulated monopoly games"),
      names.arg = 1:40,
      main = "Which space is landed on?",
      col = "cornflowerblue",
      border = "dimgray"
    )

  }

}
