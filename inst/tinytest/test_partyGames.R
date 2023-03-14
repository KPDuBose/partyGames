
set.seed(123)
ans1 <- diceSum(6, 2)

expect_equal(
  7,
  ans1
)

set.seed(123)
ans2 <- dieElephant(10, 6, 1)
expect_equal(
  1,
  ans2[[2]]
)

set.seed(123)
ans3 <- leftRightElephant(10, 0.5)
expect_equal(
  9,
  ans3[[2]]
)

set.seed(123)
ans4 <- lrDieElephant(10, 0.5, 6, 1)
expect_equal(
  2,
  ans4[[2]]
)

set.seed(123)
ans5 <- twoCoinDieElephant(10, 0.5, 0.7, 6, 1)
expect_equal(
  4,
  ans5[[2]]
)
