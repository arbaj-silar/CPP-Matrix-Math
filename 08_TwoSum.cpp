#include<iostream>
#include<vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Brute force
pair<int, int> pairSum(vector<int>& nums, int tar) {
    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[i]+nums[j] == tar) {
                return {nums[i], nums[j]};
            }
        }
    }

    return {-1, -1};
}

// Better
pair<int, int> twoSum(vector<int>& nums, int tar) {
    sort(nums.begin(), nums.end());
    int st = 0, end = nums.size()-1;

    while(st < end) {
        if(nums[st]+nums[end] == tar) {
            return {nums[st], nums[end]};
        } else if(nums[st]+nums[end] > tar) {
            end--;
        } else {
            st++;
        }
    }

    return {-1, -1};
}

// Optimized
pair<int, int> TwoSum(vector<int>& nums, int tar) {
    unordered_map<int, int> m;
    for(int i=0; i<nums.size(); i++) {
        int first = nums[i];
        int sec = tar-first;
        if(m.find(sec) != m.end()) {
            return {i, m[sec]};
        }

        m[first] = i;
    }

    return {-1, -1};
}

int main() {
    vector<int> nums = {5, 2, 11, 7, 15};

    pair<int, int> ans = TwoSum(nums, 9);
    cout<<"Pair of values: ("<<ans.first<<", "<<ans.second<<")"<<endl;
    return 0;
}