// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

// checkPrime tests
TEST(CheckPrime, SmallPrimes) {
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
  EXPECT_TRUE(checkPrime(5));
  EXPECT_TRUE(checkPrime(7));
}

TEST(CheckPrime, SmallComposites) {
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(6));
  EXPECT_FALSE(checkPrime(8));
  EXPECT_FALSE(checkPrime(9));
}

TEST(CheckPrime, EdgeCases) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
}

TEST(CheckPrime, LargePrimes) {
  EXPECT_TRUE(checkPrime(97));
  EXPECT_TRUE(checkPrime(101));
  EXPECT_TRUE(checkPrime(1009));
}

// nPrime tests
TEST(NPrime, FirstThreePrimes) {
  EXPECT_EQ(2, nPrime(1));
  EXPECT_EQ(3, nPrime(2));
  EXPECT_EQ(5, nPrime(3));
}

TEST(NPrime, TenthPrime) {
  EXPECT_EQ(29, nPrime(10));
}

// nextPrime tests
TEST(NextPrime, BasicCases) {
  EXPECT_EQ(5, nextPrime(4));
  EXPECT_EQ(13, nextPrime(11));
  EXPECT_EQ(3, nextPrime(2));
}

TEST(NextPrime, FromPrimes) {
  EXPECT_EQ(5, nextPrime(3));
  EXPECT_EQ(7, nextPrime(5));
}

// sumPrime tests
TEST(st1, sumPrime1) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}

TEST(st1, sumPrime2) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17;
  EXPECT_EQ(expected, res);
}

TEST(SumPrime, SmallBounds) {
  EXPECT_EQ(0, sumPrime(2));
  EXPECT_EQ(2, sumPrime(3));
  EXPECT_EQ(5, sumPrime(4));
}
