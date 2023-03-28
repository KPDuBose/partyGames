#' Plot results of a White Elephant simulation
#'
#' A general function to plot the results of a White Elephant simulation.
#'
#' @param x An object of class `elphList` or `elphSum` to be summarized
#' @param ... Additional arguments in `plot` function
#'
#' @return A plot showing the distribution of each winning seat and how often they won.
#'
#' @export plot.partyGames
#' @export
plot.partyGames <- function(x, ...){
  if(inherits(x, "elphList") | inherits(x, "elphSum")){

    if(inherits(x, "elphList")){
      x <- summary.partyGames(x)
    }

  graphics::barplot(
    x[[1]] / sum(x[[1]]),
    ylim = c(0, max(x[[1]] / sum(x[[1]])) + 0.05),
    sub = sprintf("Distribution of %i simulated white elephant games", sum(x[[1]])),
    main = "Who gets the present?",
    col = "cornflowerblue",
    border = "dimgray"
  )

  }

}

# x <- structure(1, class = c("a", "b"))
#
#
# y <- structure(1, class = c("a", "c"))
#
#
# plot.a <- function(x) {
#
#   if (inherits(x, "b"))
#     print("It is A!")
#   else
#     print("It is B!")
#
#   graphics::plot.default(x)
# }
#
# plot(x)
# plot(y)
