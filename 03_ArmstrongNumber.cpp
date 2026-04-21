#include<iostream>
using namespace std;

bool isArmstrong(int n) {
    int copyN = n;
    int sumOfCube = 0;

    while(n != 0) {
        int dig = n%10;
        sumOfCube += (dig + dig + dig);

        n /= 10;
    }

    return sumOfCube == copyN;
}

int main() {
    int n = 153;

    cout<<isArmstrong(n);
    return 0;
}