#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int findDuplicate(vector<int>& nums) {
    unordered_set<int> s;

    for(int val: nums) {
        if(s.find(val) != s.end()) {
            return val;
        }

        s.insert(val);
    }

    return -1;
}

int find(vector<int>& nums) {
    int slow = nums[0], fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

        slow = nums[0];

    while(slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main() {
    vector<int> nums = {1, 3, 2, 4, 2};

    cout<<"Duplicate Value: "<<find(nums);
    return 0;
}