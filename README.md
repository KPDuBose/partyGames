
<!-- README.md is generated from README.Rmd. Please edit that file -->

# partyGames

<!-- badges: start -->
<!-- badges: end -->

The goal of partyGames is to simulate various party games and help you
devise a better strategy to win.

## Installation

You can install the development version of partyGames like so:

``` r
# install.package("devtools")
devtools::install_github("KPDuBose/partyGames")
```

## Example

Simulate 1500 White Elephant Games under different conditions.

``` r
library(partyGames)
games <- simulateElephant(15, dice = TRUE, coins = 1, iter = 1500, pheads = 0.5, sides = 6, numDice = 1)
summary.partyGames(games)
class(games)
plot.partyGames(games)
plot.partyGames(summary.partyGames(games))
```
