#' Plot results of a White Elephant simulation
#'
#' A general function to plot the results of a White Elephant simulation.
#'
#' @param sim An object of class `elphList` or `elphSum` to be summarized
#'
#' @return A plot showing the distribution of each winning seat and how often they won.
#'
#' @export
#'
#'


plotElephant <- function(sim){
  if(!(is(sim, "elphList") | is(sim, "elphSum"))) stop("'sim' must be an 'elphList' or 'elphSum' class object")

  if(is(sim, "elphList")){
    sim <- summaryElephant(sim)
  }


  barplot(
    sim[[1]] / sum(sim[[1]]),
    ylim = c(0, max(sim[[1]] / sum(sim[[1]])) + 0.05),
    sub = sprintf("Distribution of %i simulated white elephant games", sum(sim[[1]])),
    main = "Who gets the present?",
    col = "cornflowerblue",
    border = "dimgray"
  )

}