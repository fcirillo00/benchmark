#include "functions.h"

std::mutex n_mutex;
uint16_t n_factorizations = 0;
bool time_is_over = false;


/*  Example:
    a = 20
    1) i = 2, a%2 == 0, a = 10
    2) i = 2, a%2 == 0, a = 5
    3) i = 5, a%5 == 0, a = 1
    20 = 2*2*5
*/
void factorization (uint64_t a) {
    for (uint64_t i=2; i <= a && !time_is_over; ++i) {
        if (a%i == 0) {
            //std::cout<<i<<std::endl;
            a = a/i;
            i = 2;
        }
    }
    n_mutex.lock();
    if (!time_is_over)
        n_factorizations++;
    n_mutex.unlock();
}

void bench(uint64_t begin, uint64_t end, int time_seconds, int n_threads) {
    uint64_t offset = (end-begin)/n_threads;

    std::unique_ptr<std::thread[]> t (new std::thread[n_threads]);
    for (int i = 0; i < n_threads; i++) {
        t[i] = std::thread(rangeThread, begin+offset*i, begin+offset*(i+1));
    }

    std::cout<<"Benchmark started. Wait "<<time_seconds<<" seconds"<<std::endl;
    std::chrono::seconds timespan(time_seconds);
    std::this_thread::sleep_for(timespan);
    
    time_is_over = true;
    std::cout<<"Benchmark finished... waiting for threads\n";
    for (int i=0; i<n_threads; i++) {
        t[i].join();
    }
    std::cout<<"Score (number of factorizations): "<<n_factorizations<<std::endl;
}

void rangeThread(uint64_t begin, uint64_t end) {
    uint64_t i = begin;
    while (!time_is_over) {
        factorization(i++);
        if (i == end)
            i = begin;
    }
}





/*uint64_t nextPrime (uint64_t a) {
    assert(a > 0);
    for (uint64_t i = a; i<UINT32_MAX; ++i) {
        if (isPrime(i))
            return i;
    }
    return 0;
}

uint64_t previousPrime(uint64_t a) {
    assert(a<UINT32_MAX);
    for (uint64_t i = a; i>2; --i) {
        if (isPrime(i))
            return i;
    }
    return 0;
}

bool isPrime(uint64_t a) {
    for (uint64_t i = 2; i<a; i++) {
        if (a % i == 0)
            return false;
    }
    return true;
}

void calculate (uint64_t a) {
    for (uint64_t i = 2; i < a; ++i) {
        if (a % i == 0) {
            uint64_t b = a/i;
            if (isPrime(b)) {
                std::cout<<"Trovati: "<<i<<"*"<<b<<std::endl;
                return;
            }
        }
    }
}*/