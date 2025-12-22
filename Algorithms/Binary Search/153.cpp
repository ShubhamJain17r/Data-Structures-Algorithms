// Find Minimum in Rotated Sorted Array

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array?envType=problem-list-v2&envId=vyrqwl9s

/*
Constraints : 
    n == nums.length
    1 <= n <= 5000
    -5000 <= nums[i] <= 5000
    all the integers of nums are unique
    nums is sorted and rotated between 1 and n times

Important : 
    return minimum element of the array
    You must write an algorithm that runs in O(log n) time.
*/

#include<bits/stdc++.h>
#include <chrono>
#include <limits>

using namespace std;

struct TimeStats {
    using clock = std::chrono::steady_clock;

    clock::duration total{};
    clock::duration min = clock::duration::max();
    clock::duration max = clock::duration::zero();
    std::size_t count = 0;

    void add(clock::duration d) {
        total += d;
        if (d < min) min = d;
        if (d > max) max = d;
        ++count;
    }

    double avg_us() const {
        return std::chrono::duration<double, std::micro>(total).count() / count;
    }
    double min_us() const {
        return std::chrono::duration<double, std::micro>(min).count();
    }
    double max_us() const {
        return std::chrono::duration<double, std::micro>(max).count();
    }
};


/*
At the middle index(m) of the array, either left half or the right half is sorted

{1,2,3,4,5,6,7,8,9,10,11,12}
if whole array is sorted
mini = arr[l]
return mini

{4,5,6,7,8,9,10,11,12,1,2,3}
if left half is sorted, mini = arr[l]

{10,11,12,1,2,3,4,5,6,7,8,9}
if right half is sorted mini = arr[m]


go to the opposite side of sorted area
*/

int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    int mini = INT_MAX;
    while (l <= r) {
        int m = l + ((r - l) >> 1);
        int mid = nums[m];

        // whole range is sorted
        if (nums[l] <= nums[r]) {
            mini = min(mini, nums[l]);
            return mini;
        }

        // left half is sorted
        if (mid >= nums[l]) {
            mini = min(mini, nums[l]);
            l = m + 1;
        }
        else {
            mini = min(mini, nums[m]);
            r = m - 1;
        }
    }
    return mini;
}

int main() {
    TimeStats stats;

    int n = 5000;
    for (int i = 0; i < n; ++i) {
        vector<int> nums;
        for (int right = i + 1; right < n; ++right)
            nums.push_back(right);
        for (int left = 0; left <= i; ++left)
            nums.push_back(left);
        auto start = TimeStats::clock::now();
        int mini = findMin(nums);
        auto end = TimeStats::clock::now();
        stats.add(end - start);
        if (mini != 0)
            cout<<"Test Case "<<i<<" : FAILED"<<endl;
    }
    cout << "Avg: " << stats.avg_us() << " us\n";
    cout << "Min: " << stats.min_us() << " us\n";
    cout << "Max: " << stats.max_us() << " us\n";
    cout<<"End of Program";
    return 0;
}