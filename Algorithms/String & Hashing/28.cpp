// Find the Index of the First Occurance in a String

// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= haystack.length, needle.length <= 10^4
    haystack and needle consist of only lowercase English characters
*/

#include<bits/stdc++.h>

using namespace std;

int strStr(string haystack, string needle) {
    return haystack.find(needle);
}