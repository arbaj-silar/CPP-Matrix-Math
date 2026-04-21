#include<iostream>
using namespace std;

int euclidsAlgo(int a, int b) {
    if(a == 0) {
        return b;
    }

    return euclidsAlgo(b%a, a);
}

int main() {
    cout<<euclidsAlgo(20, 28);
    return 0;
}