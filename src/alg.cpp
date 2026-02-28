// Copyright 2025 UNN-CS
#include <cstdint>
#include <cmath>
#include <vector>
#include "alg.h"

bool checkPrime(uint64_t value) {
    if (value <= 1) return false;
    if (value <= 3) return true; 
    if (value % 2 == 0 || value % 3 == 0) return false;
    
    for (uint64_t i = 5; i * i <= value; i += 6) {
        if (value % i == 0 || value % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n < 1) return 0;
    
    uint64_t count = 1; 
    uint64_t candidate = 3;
    
    if (n == 1) return 2;
    
    while (count < n) {
        if (checkPrime(candidate)) {
            count++;
        }
        candidate += 2;
    }
    return candidate - 2;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t candidate = value;
    
    do {
        candidate++;
    } while (!checkPrime(candidate));
    
    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= 2) return 0;
    
    std::vector<bool> isPrime(hbound, true);
    isPrime[0] = isPrime[1] = false;
    
    for (uint64_t i = 2; i * i < hbound; i++) {
        if (isPrime[i]) {
            for (uint64_t j = i * i; j < hbound; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    uint64_t sum = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (isPrime[i]) {
            sum += i;
        }
    }
    return sum;
}