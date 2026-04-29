#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += nums[j];
            if(sum == k) count++;
        }
    }

    return count;
}

int subArraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int count = 0;
    vector<int> preSum(n);

    preSum[0] = nums[0];
    for(int i=1; i<n; i++) {
        preSum[i] = preSum[i-1]+nums[i];
    }

    unordered_map<int, int> m;
    for(int i=0; i<n; i++) {
        if(preSum[i] == k) count++;

        int val = preSum[i]-k;
        if(m.find(val) != m.end()) {
            count += m[val];
        }

        if(m.find(preSum[i]) == m.end()) {
            m[preSum[i]] = 0;
        }
        m[preSum[i]]++;
    }

    return count;
}

int main() {
    vector<int> nums = {9, 4, 20, 3, 10, 5};

    cout<<subArraySum(nums, 33);
    return 0;
}
