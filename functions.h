#ifndef _FRANCESCO_FUNCTIONS_
#define _FRANCESCO_FUNCTIONS_

#include <cstdint>
#include <cassert>
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

//uint64_t nextPrime (uint64_t a);
//uint64_t previousPrime (uint64_t a);
//bool isPrime (uint64_t a);
//void calculate (uint64_t a);
void factorization(uint64_t n);
void bench (uint64_t begin, uint64_t end, int tempo_secondi, int n_threads);
void rangeThread(uint64_t begin, uint64_t end);

#endif