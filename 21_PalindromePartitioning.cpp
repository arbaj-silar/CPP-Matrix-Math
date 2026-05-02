#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool isPalin(string s) {
    string s1 = s;
    reverse(s1.begin(), s1.end());

    return s == s1;
}

void getAllParts(string s, vector<string>& partitions, vector<vector<string>> &ans) {
    if(s.length() == 0) {
        ans.push_back(partitions);
        return;
    }

    for(int i=0; i<s.length(); i++) {
        string part = s.substr(0, i+1);

        if(isPalin(part)) {
            partitions.push_back(part);
            getAllParts(s.substr(i+1), partitions, ans);
            partitions.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partitions;

    getAllParts(s, partitions, ans);

    return ans;
}
int main() {
    string s = "aab";

    vector<vector<string>> ans = partition(s);
    for(auto i: ans) {
        for(string j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}