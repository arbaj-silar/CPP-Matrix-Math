#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    int sRow = 0, eRow = m-1;
    int sCol = 0, eCol = n-1;
    vector<int> ans;

    while(sCol <= eCol && sRow <= eRow) {
        for(int i=sCol; i<=eCol; i++) {
            ans.push_back(mat[sRow][i]);
        }
        
        for(int j = sRow+1; j<=eRow; j++) {
            ans.push_back(mat[j][eCol]);
        }
        
        for(int i=eCol-1; i>=sCol; i--) {
            if(sRow == eRow) break;
            ans.push_back(mat[eRow][i]);
        }
        
        for(int j=eRow-1; j>=sRow+1; j--) {
            if(sCol == eCol) break;
            ans.push_back(mat[j][sCol]);
        }

        sRow++; eRow--;
        sCol++; eCol--;
    }

    return ans;
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3},{ 4, 5, 6},{ 7, 8, 9}};

    vector<int> ans = spiralMatrix(mat);

    for(int val: ans) {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}