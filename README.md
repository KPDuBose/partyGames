
<!-- README.md is generated from README.Rmd. Please edit that file -->

# partyGames

<!-- badges: start -->

[![R-CMD-check](https://github.com/UofUEpiBio/partyGames/workflows/R-CMD-check/badge.svg)](https://github.com/UofUEpiBio/partyGames/actions)
<!-- badges: end -->

The goal of partyGames is to simulate various party games and help you
devise a better strategy to win.

## Installation

You can install the development version of partyGames like so:

``` r
# install.packages("devtools")
devtools::install_github("KPDuBose/partyGames")
```

## White Elephant Games

Simulate 1500 White Elephant Games under different conditions.

``` r
library(partyGames)
games <- simulateElephant(15, dice = TRUE, coins = 1, iter = 1500, pheads = 0.5, sides = 6, numDice = 1)
summary.partyGames(games)
#> $winner
#> winner
#>   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15 
#>  97  84 101  99 105 106 120 103  93  88  85  98 111 110 100 
#> 
#> $moves
#> moves
#>   -6   -5   -4   -3   -2   -1    1    2    3    4    5    6 
#> 1917 1807 1812 1893 1862 1909 1881 1920 1865 1902 1864 1868 
#> 
#> attr(,"class")
#> [1] "elphSum" "list"
class(games)
#> [1] "elphList" "list"
plot.partyGames(games)
```

<img src="man/figures/README-example-monopoly-1.png" width="100%" />

``` r
plot.partyGames(summary.partyGames(games))
```

## Monopoly Simulation

Additionally, you can simulate Monopoly games based on the 2008 US
version of the game.

``` r

library(partyGames)
monopolyGame <- simulateMonopoly()
monopolyGame
#> [[1]]
#>  [1] 22 12 16 11 11 14 15 17 20 16 25 17 15 17 12 13 11 17 15 17 21 13 13  9 12
#> [26] 16  9 15 15 19  9 11 22 17  9 16  9 21  8 15
#> 
#> [[2]]
#>  [1] 15 11 17 13 10 18 16 17 11 14 23 12 19 15 12 14  9 20 15 21 10 22 14 17 12
#> [26] 10 16 13 20 13 13 22 18 12 13 12 16 13 16 12
#> 
#> [[3]]
#>  [1] 18 11 17 10 14  7 15 13 14 13 29 15 17 11 13 12 18 15 18 14 16 15 13 15 12
#> [26] 17 17 10 19  8 15 16 15 21 12 10 12 10 15 17
#> 
#> [[4]]
#>  [1]  9 11 16 14 15 15 13 14  7 22 22 10 15 13 21 18 16  9 21 11 12 23 16 15 17
#> [26] 14 16 15 18 12  9 18  9 22 18 11 18 14 17  6
#> 
#> [[5]]
#>  [1] 11 15 14 15  6 23 16 12 18 15 23 14 12 18 12 10 13 18 12 23 13 12 13 16 15
#> [26] 13 18 20 17  5 15 15 13 13 16 13 15 10 15 17
#> 
#> [[6]]
#>  [1] 11 21  9 15 17 17 10 18 17 10 26 13 15 12  9 18 19  5 19 19 21 17 17 14  9
#> [26] 13 21 15 17  9 19 12 13 18 16 18 19  9 13  8
#> 
#> [[7]]
#>  [1] 13 13 13 17 12 16 15 16 14 14 22 10 14 14 22 11 13 21 19 11 18 17 12 14 16
#> [26] 17 13 17 15  9 17 16 16 12 15 14 16 17 16 11
#> 
#> [[8]]
#>  [1] 20  7 15 13 12 14 15  8 17 12 26  7 20 12 17 11  8 15 17 22  8 10 16 19 13
#> [26] 15 16 12 16  7 11 16 14 13 15 22 17  7 16 13
#> 
#> [[9]]
#>  [1] 19 12 18 10 14 14 13 17 14 15 23 13 16 15 12 15 16 20 11 19 16  7 15 17 12
#> [26] 13 14 15 13 19 13 17 15  9  8 19 16 14 18 14
#> 
#> [[10]]
#>  [1] 12 11 13 18 14 15 13 10 13  9 27 11 19 10 13 15 17 14 14 17 16 14 21 21 12
#> [26] 10 11 22 12 14 11 14 15 15 16 15 18 13 18  9
#> 
#> attr(,"class")
#> [1] "monopoly" "list"
summary.monopoly(monopolyGame)
#>   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20 
#> 150 124 148 136 125 153 141 142 145 140 246 122 162 137 143 137 140 154 161 174 
#>  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40 
#> 151 150 150 157 130 138 151 154 162 115 132 157 150 152 138 150 156 128 152 122 
#> attr(,"class")
#> [1] "monoSum" "numeric"
plot.monopoly(monopolyGame)
```

<img src="man/figures/README-unnamed-chunk-2-1.png" width="100%" />

Parallel computing (made possible in this case through Open MP) is also
possible for this.

``` r
monoParallel <- simulateMonopoly(numGames = 20, 
                                 maxTurns = 500, 
                                 sides    = 6, 
                                 numDice  = 2, 
                                 cores    = 3)

summary.monopoly(monoParallel)
#>   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20 
#> 282 275 251 264 276 273 283 296 283 303 423 283 286 274 292 292 306 292 317 321 
#>  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40 
#> 312 306 309 313 332 271 264 276 322 269 308 288 260 295 306 296 284 275 278 284 
#> attr(,"class")
#> [1] "monoSum" "numeric"
plot.monopoly(monoParallel)
```

<img src="man/figures/README-unnamed-chunk-3-1.png" width="100%" />
