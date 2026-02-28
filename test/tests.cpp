// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

TEST(PrimeCheckerTest, HandlesVerySmallNumbers) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
}

TEST(PrimeCheckerTest, HandlesEvenNumbers) {
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(8));
    EXPECT_FALSE(checkPrime(100));
}

TEST(PrimeCheckerTest, HandlesOddComposites) {
    EXPECT_FALSE(checkPrime(9));
    EXPECT_FALSE(checkPrime(15));
    EXPECT_FALSE(checkPrime(21));
    EXPECT_FALSE(checkPrime(25));
    EXPECT_FALSE(checkPrime(27));
}

TEST(PrimeCheckerTest, HandlesPrimeNumbers) {
    EXPECT_TRUE(checkPrime(11));
    EXPECT_TRUE(checkPrime(13));
    EXPECT_TRUE(checkPrime(17));
    EXPECT_TRUE(checkPrime(19));
    EXPECT_TRUE(checkPrime(23));
}

TEST(PrimeCheckerTest, HandlesLargerPrimes) {
    EXPECT_TRUE(checkPrime(997));
    EXPECT_TRUE(checkPrime(1009));
    EXPECT_TRUE(checkPrime(1013));
    EXPECT_TRUE(checkPrime(7919));
}

TEST(NthPrimeTest, ReturnsCorrectFirstPrimes) {
    EXPECT_EQ(nPrime(1), 2);
    EXPECT_EQ(nPrime(2), 3);
    EXPECT_EQ(nPrime(3), 5);
    EXPECT_EQ(nPrime(4), 7);
    EXPECT_EQ(nPrime(5), 11);
}

TEST(NthPrimeTest, ReturnsCorrectLaterPrimes) {
    EXPECT_EQ(nPrime(6), 13);
    EXPECT_EQ(nPrime(7), 17);
    EXPECT_EQ(nPrime(8), 19);
    EXPECT_EQ(nPrime(9), 23);
    EXPECT_EQ(nPrime(10), 29);
}

TEST(NthPrimeTest, HandlesZero) {
    EXPECT_EQ(nPrime(0), 0);
}

TEST(NextPrimeFinderTest, FindsNextAfterComposite) {
    EXPECT_EQ(nextPrime(4), 5);
    EXPECT_EQ(nextPrime(6), 7);
    EXPECT_EQ(nextPrime(8), 11);
    EXPECT_EQ(nextPrime(9), 11);
    EXPECT_EQ(nextPrime(10), 11);
}

TEST(NextPrimeFinderTest, FindsNextAfterPrime) {
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(3), 5);
    EXPECT_EQ(nextPrime(5), 7);
    EXPECT_EQ(nextPrime(7), 11);
    EXPECT_EQ(nextPrime(11), 13);
}

TEST(NextPrimeFinderTest, HandlesBoundaryCases) {
    EXPECT_EQ(nextPrime(0), 2);
    EXPECT_EQ(nextPrime(1), 2);
    EXPECT_EQ(nextPrime(13), 17);
}

TEST(PrimeSumCalculatorTest, HandlesSmallBoundaries) {
    EXPECT_EQ(sumPrime(2), 0);
    EXPECT_EQ(sumPrime(3), 2);
    EXPECT_EQ(sumPrime(4), 5);
    EXPECT_EQ(sumPrime(5), 5);
    EXPECT_EQ(sumPrime(6), 10);  
}

TEST(PrimeSumCalculatorTest, HandlesMediumBoundaries) {
    EXPECT_EQ(sumPrime(10), 17);   
    EXPECT_EQ(sumPrime(15), 41);   
    EXPECT_EQ(sumPrime(20), 77);  
    EXPECT_EQ(sumPrime(30), 129); 
}

TEST(PrimeSumCalculatorTest, HandlesLargerBoundary) {
    uint64_t expectedSum100 = 1060; 
    EXPECT_EQ(sumPrime(100), expectedSum100);
    
    uint64_t result = sumPrime(1000);
    EXPECT_GT(result, 0);
    EXPECT_LT(result, 50000); 
}