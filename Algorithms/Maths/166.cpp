// Fraction to Recurring Decimal

// https://leetcode.com/problems/fraction-to-recurring-decimal?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    -2^31 <= numerator, denominator <= 2^31 - 1
    denominator != 0
*/

#include<bits/stdc++.h>

using namespace std;

int lower_bound(vector<long long>& table, long long val) {
    int l = 0, r = 10;
    int lb = 10;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        long long mid = table[m];

        if (mid <= val) {
            l = m + 1;
            lb = m;          
        }
        else {   
            r = m - 1;
        }
    }
    return lb;
}

string fractionToDecimal(int numerator, int denominator) {
    long long n = abs(1LL * numerator);
    long long d = abs(1LL * denominator);

    bool negative = false;

    if ((denominator > 0 && numerator < 0) || (denominator < 0 && numerator > 0)) negative = true;

    if (d == n) return negative ? "-1" : "1";
    if (n % d == 0) {
        long long ans = n / d;
        if (negative) return to_string(-1 * ans);
        return to_string(ans);
    }

    long long whole = n / d;
    // cout<<"Whole : "<<whole<<endl;
    long long rem = n % d;
    // cout<<"Remainder : "<<rem<<endl;
    string fraction = "";

    vector<long long> table(11, 0);
    for (int i = 1; i <= 10; ++i) {
        table[i] = i * d;
    }

    unordered_map<long long, int> hash;
    int idx = 0;

    while (rem > 0 && hash.count(rem) == 0) {
        hash[rem] = idx;
        rem = rem * 10;
        // cout<<rem<<" ";
        int i = lower_bound(table, rem);
        // cout<<i<<" ";
        fraction.push_back(i + '0');
        rem = rem - i * d;
        // cout<<rem<<endl;
        idx++;
    }
    cout<<"\n\n\n";
    string ans = "";
    if (negative)
        ans.push_back('-');
    ans += to_string(whole) + ".";
    if (rem == 0)
        ans += fraction;
    else
        ans += fraction.substr(0, hash[rem]) + "(" + fraction.substr(hash[rem]) + ")";
    return ans;
}

int main() {
    int num, den;
    cin>>num>>den;

    // int n = 2147483647;
    // int d = -2147483648;


    string decimal = fractionToDecimal(num, den);
    cout<<"Returned Value : "<<decimal;

    // 9999999995343387126922607421875
    // 9999999995343387126922607421874(9)
}