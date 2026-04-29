#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
        
    for(int i=0; i<n; i++) {
        if(i>0 && arr[i] == arr[i-1]) continue;
        
        for(int j=i+1; j<n; j++) {
            int p = j+1, q = n-1;
            
            while(p<q) {
                int sum = arr[i]+arr[j]+arr[p]+arr[q];
                if(sum<tar) {
                    p++;
                } else if(sum>tar) {
                    q--;
                } else {
                    ans.push_back({arr[i], arr[j], arr[p],arr[q]});
                    p++; q--;

                    while(p<q && arr[p] == arr[q]) p++;
                }
            }

            j++;
            while(j<n && arr[j] == arr[j-1]) j++;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {-2, -1, -1, 1, 1, 2, 2};

    vector<vector<int>> ans = fourSum(arr, 0);
    for(auto i: ans) {
        for(int j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}