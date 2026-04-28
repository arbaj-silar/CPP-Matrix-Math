#include<iostream>
#include<vector>
using namespace std;

pair<int, int> searchInRow(vector<vector<int>>& mat, int tar, int row) {
    int n = mat[0].size();
    int sCol = 0, eCol = n-1;

    while(sCol <= eCol) {
        int midCol = sCol+(eCol-sCol)/2;

        if(tar == mat[row][midCol]) {
            return {row, midCol};
        } else if(tar < mat[row][midCol]) {
            eCol = midCol-1;
        } else {
            sCol = midCol+1;
        }
    }

    return {-1, -1};
}

pair<int, int> search(vector<vector<int>>& mat, int tar) {
    int m = mat.size(), n = mat[0].size();
    int sRow = 0, eRow = m-1;

    while(sRow <= eRow) {
        int midRow = sRow + (eRow-sRow)/2;

        if(mat[midRow][0] <= tar && tar <= mat[midRow][n-1]) {
            return searchInRow(mat, tar, midRow);
        } else if(mat[midRow][n-1] < tar) {
            sRow = midRow+1;
        } else {
            eRow =midRow-1;
        }
    }

    return {-1, -1};
}

int main() {
    vector<vector<int>> mat = {{1, 3, 5, 8, 9},
                                {11, 14, 15, 19, 20},
                                {22, 25, 26, 30, 35},
                                {40, 49, 56, 67, 80}};

    pair<int, int> ans = search(mat, 30);
    cout<<"Pair of Idx: ("<<ans.first<<", "<<ans.second<<")"<<endl;    
    return 0;
}