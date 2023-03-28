#' Plot results of a White Elephant simulation
#'
#' A general function to plot the results of a White Elephant simulation.
#'
#' @param sim An object of class `elphList` or `elphSum` to be summarized
#'
#' @return A plot showing the distribution of each winning seat and how often they won.
#'
#' @export plot.partyGames
#' @export
plot.partyGames <- function(sim, ...){
  if(inherits(sim, "elphList") | inherits(sim, "elphSum")){

    if(inherits(sim, "elphList")){
      sim <- summary.partyGames(sim)
    }

  graphics::barplot(
    sim[[1]] / sum(sim[[1]]),
    ylim = c(0, max(sim[[1]] / sum(sim[[1]])) + 0.05),
    sub = sprintf("Distribution of %i simulated white elephant games", sum(sim[[1]])),
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
