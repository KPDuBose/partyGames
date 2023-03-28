
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
#> $winner
#> winner
#>   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15 
#>  99 119 112  95 108 106 100 105  91  91  89  89 100 104  92 
#> 
#> $moves
#> moves
#>   -6   -5   -4   -3   -2   -1    1    2    3    4    5    6 
#> 1894 1883 1837 1847 1815 1866 1934 1907 1831 1950 1817 1919 
#> 
#> attr(,"class")
#> [1] "elphSum" "list"
class(games)
#> [1] "elphList" "list"
plot.partyGames(games)
plot.partyGames(summary.partyGames(games))
```

<img src="man/figures/README-example-1.png" width="100%" />
