#include<iostream>
using namespace std;

string isPrime(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%2 == 0) {
            return "Non Prime";
        }
    }

    return "Prime";
}

int main() {
    int n = 42;

    cout<<isPrime(n);
    return 0;
}