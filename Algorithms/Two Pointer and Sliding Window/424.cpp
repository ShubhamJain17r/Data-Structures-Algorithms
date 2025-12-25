// Longest Repeating Character Replacement

// https://leetcode.com/problems/longest-repeating-character-replacement?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints:
    1 <= s.length <= 10^5
    s consists of only uppercase English letters.
    0 <= k <= s.length
*/

#include<bits/stdc++.h>

using namespace std;

/*
the length of longest substr is always:
    (max freq of element in substring) + k(unwanted characters in substring)

While finding maxLen we dont need to shrink the window size, as shrinking wont help in finding max window size. similarly since window len depends on frequency, we dont need to compute freq of all characters in window.
*/

int characterReplacement(string s, int k) {
    vector<int> freq(26, 0);                        // freq of Uppercase alphabets
    int maxLen = 0;
    int maxFreq = 0;
    int l = 0;
    for (int r = 0; r < s.length(); ++r) {
        freq[s[r] - 'A']++;                         // increment freq of curr character
        maxFreq = max(maxFreq, freq[s[r] - 'A']);   // check for max Freq
        if ((r - l + 1) - maxFreq > k) {            // if impurities exceed
            freq[s[l] - 'A']--;                     // reduce the freq of discarded character
            l++;
        }
        else
            maxLen = max(maxLen, r - l + 1);        // compute maxLen
    }
    return maxLen;
}