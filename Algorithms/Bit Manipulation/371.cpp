// Sum of Two Integers

// https://leetcode.com/problems/sum-of-two-integers?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    -1000 <= a, b <= 1000
*/

#include <iostream>

using namespace std;

/*
int getSum(int a, int b) {
    while (b != 0) {
        int sum = a ^ b; // sum without carry
        int carry = (a & b) << 1; // carry shifted left
        a = sum;
        b = carry;
    }
    return a;
}
*/

int getSum(int a, int b) {      // bit by bit addition
    if (a == 0) return b;
    if (b == 0) return a;
    int aCopy = a, bCopy = b;
    int carry = 0;
    int total = 0;
    int bit = 1;
    while (a != 0 || b != 0 || carry) {
        int x = (a & bit) > 0;
        int y = (b & bit) > 0;

        int sum = x ^ y ^ carry;
        carry = (x & y) | (x & carry) | (y & carry);

        if (sum == 1)
            total |= bit;

        a = a & ~bit;
        b = b & ~bit;
        bit <<= 1;
    }
    if ((aCopy > 0 && bCopy < 0) || (aCopy < 0 && bCopy > 0)) {
        return ~(total ^ ~(1 << 31));
    }
    return total;
}


void printBinary(int num) {
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
//     int number = 5;
//     printf("Binary representation of %d: ", -88);
//     printBinary(number);

    for (int i = -1000; i <= 1000; ++i) {
        for (int j = -1000; j <= 1000; ++j) {
            if ((i + j) != getSum(i, j)) {
                cout<<i<<" "<<j<<endl;
            }
        }
        cout<<".";
    }
    cout<<"Done";

    return 0;
}