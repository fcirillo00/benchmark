#include <iostream>
#include <cassert>
#include "functions.h"
#include <thread>

using namespace std;

int main() {
    cout<<"~~~~~~ FACTORIZATION IN PRIME NUMBERS ~~~~~~\n\n";
    const auto processor_count = std::thread::hardware_concurrency();
    cout<<"Use default settings? (automatic number of threads and 30 seconds length)\n0: no\n1: yes"<<endl;
    int automatico;
    cin>>automatico;
    int time_seconds;
    int n_threads;
    if (automatico == 1) {
        cout<<"Number of threads detected: "<<processor_count<<endl;
        n_threads = processor_count;
        time_seconds = 30;
    } else {
        cout<<"Insert number of threads: "<<endl;
        cin>>n_threads;
        assert(n_threads > 0);
        cout<<"Insert bench time (seconds): \n";
        cin>>time_seconds;
        assert(time_seconds > 0);
    }

    uint64_t left_boundary  =  50000000;
    uint64_t right_boundary =  51000000;
    

    bench(left_boundary, right_boundary, time_seconds, n_threads);

    // system("PAUSE");
}