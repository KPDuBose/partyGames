% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/simulateElephant.R
\name{simulateElephant}
\alias{simulateElephant}
\title{Simulates many white elephant games}
\usage{
simulateElephant(
  n,
  dice = FALSE,
  coins = 1,
  iter = 1000,
  pheads = 0.5,
  pheads2 = 0.5,
  sides = 6,
  numDice = 1
)
}
\arguments{
\item{n}{Number of party people}

\item{dice}{Logical indicating if dice should be used in the game}

\item{coins}{Number of coins to be used. Should be a value of 0, 1, or 2}

\item{iter}{Number of times to simulate the game.}

\item{pheads}{Probability of heads for the first coin used}

\item{pheads2}{Probability of heads for the second coin}

\item{sides}{Number of sides on dice}

\item{numDice}{Number of dice rolled}
}
\value{
A list of clas `elphList`
}
\description{
A general function to simulate various types of White Elephant games.
}
