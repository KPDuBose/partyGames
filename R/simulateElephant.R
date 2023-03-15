#' Simulates many white elephant games
#'
#' A general function to simulate various types of White Elephant games.
#'
#' @param n Number of party people
#' @param dice Logical indicating if dice should be used in the game
#' @param coins Number of coins to be used. Should be a value of 0, 1, or 2
#' @param iter Number of times to simulate the game.
#' @param pheads Probability of heads for the first coin used
#' @param pheads2 Probability of heads for the second coin
#' @param sides Number of sides on dice
#' @param numDice Number of dice rolled
#'
#' @return A list of clas `elphList`
#'
#' @export


simulateElephant <- function(n,
                             dice = FALSE,
                             coins = 1,
                             iter = 1000,
                             pheads = 0.5,
                             pheads2 = 0.5,
                             sides = 6,
                             numDice = 1){
  if(dice == FALSE & coins == 0){
    stop("This doesn't seem like a very fun game")
  }

  if(dice == FALSE){
    if(coins == 1){
      cl <- parallel::makeCluster(2)
      ans <- parallel::parSapply(cl, 1, function(i) replicate(iter, leftRightElephant(n, pheads), simplify = FALSE))
      parallel::stopCluster(cl)
    }

    if(coins == 2){
      cl <- parallel::makeCluster(2)
      ans <- parallel::parSapply(cl, 1, function(i) replicate(iter, twoCoinElephant(n, pheads1 = pheads, pheads2 = pheads2), simplify = FALSE))
      parallel::stopCluster(cl)
    }
  }

  if(dice == TRUE){
    if(coins == 0){
      cl <- parallel::makeCluster(2)
      ans <- parallel::parSapply(cl, 1, function(i) replicate(iter, dieElephant(n, sides = sides, numDice = numDice), simplify = FALSE))
      parallel::stopCluster(cl)
    }

    if(coins == 1){
      cl <- parallel::makeCluster(2)
      ans <- parallel::parSapply(cl, 1, function(i) replicate(iter, lrDieElephant(n, pheads = pheads, sides = sides, numDice = numDice), simplify = FALSE))
      parallel::stopCluster(cl)
    }

    if(coins == 2){
      cl <- parallel::makeCluster(2)
      ans <- parallel::parSapply(cl, 1, function(i) replicate(iter, twoCoinDieElephant(n, pheads1 = pheads, pheads2 = pheads2, sides = sides, numDice = numDice), simplify = FALSE))
      parallel::stopCluster(cl)
    }
  }

class(ans) <- c("elphList", "list")

return(ans)

}
