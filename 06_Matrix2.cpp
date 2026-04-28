#include<iostream>
#include<vector>
using namespace std;

pair<int, int> search(vector<vector<int>>& mat, int tar) {
    int m = mat.size(), n = mat[0].size();
    int r = 0, c = n-1;

    while(r < m && c >= 0) {
        if(tar == mat[r][c]) {
            return {r, c};
        } else if(tar < mat[r][c]) {
            c--;
        } else {
            r++;
        }
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> mat = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
                                
    pair<int, int> ans = search(mat, 24);
    cout<<"Pair of Idx: ("<<ans.first<<", "<<ans.second<<")"<<endl;
    return 0;
}