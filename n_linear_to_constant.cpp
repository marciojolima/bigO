#include <iostream>
#include <chrono>

void somaInt_On(int);
void somaInt_O1(int);

int main(int argc, char **argv){
    int n = 0;
    
    if(argv[1] == nullptr){
        std::cout << "sem argumentos." << "\n";
        return 0;
    } else {
        n = atoi(argv[1]);
    }

    //std::cout << "argc: " << argc << "\n";
    //std::cout << "argv[0]: " << argv[0] << "\n"; //first command is the own exec
    std::cout << "argv[1]: " << argv[1] << "\n";

    somaInt_On(n);
    somaInt_O1(n);

    return 0;
}

void somaInt_On(int n){
    auto start = std::chrono::high_resolution_clock::now();
    int sum = 0;

    while(n > 0){
        sum += n;
        --n;
    }
    
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns -> ";
    std::cout << "Somatorio O(n): " << sum  << "\n";
}


void somaInt_O1(int n){
    auto start = std::chrono::high_resolution_clock::now();
    
    int sum = n * (n+1) / 2;

    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns -> ";
    std::cout << "Somatorio O(1): " << sum  << "\n";
}
