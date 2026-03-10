// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

// --- sumPrime ---
TEST(SumPrime, LargeBound) {
    EXPECT_EQ(sumPrime(2000000), 142913828922ULL);
}

TEST(SumPrime, SmallBound) {
    EXPECT_EQ(sumPrime(10), 17ULL);
}

TEST(SumPrime, BoundaryZero) {
    EXPECT_EQ(sumPrime(2), 0ULL);
}

TEST(SumPrime, BoundaryOne) {
    EXPECT_EQ(sumPrime(3), 2ULL);
}

// --- checkPrime ---
TEST(CheckPrime, PrimeNumbers) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
    EXPECT_TRUE(checkPrime(97));
    EXPECT_TRUE(checkPrime(1000000007));
}

TEST(CheckPrime, CompositeNumbers) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(100));
}

// --- nPrime ---
TEST(NPrime, FirstPrimes) {
    EXPECT_EQ(nPrime(1), 2ULL);
    EXPECT_EQ(nPrime(2), 3ULL);
    EXPECT_EQ(nPrime(3), 5ULL);
    EXPECT_EQ(nPrime(10), 29ULL);
}

TEST(NPrime, LargerIndex) {
    EXPECT_EQ(nPrime(100), 541ULL);
}

// --- nextPrime ---
TEST(NextPrime, BasicCases) {
    EXPECT_EQ(nextPrime(4), 5ULL);
    EXPECT_EQ(nextPrime(11), 13ULL);
    EXPECT_EQ(nextPrime(2), 3ULL);
}

TEST(NextPrime, AfterComposite) {
    EXPECT_EQ(nextPrime(10), 11ULL);
    EXPECT_EQ(nextPrime(1), 2ULL);
}
