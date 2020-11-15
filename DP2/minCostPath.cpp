#include<iostream>
using namespace std;

int minCostPath(int **input, int m, int n, int r, int c) {
    if(r == m-1 && c == n-1) {
        return input[r][c];
    }

    if(r >= m || c >= n) {
        return INT32_MAX;
    }

    int x = minCostPath(input, m, n, r, c+1);
    int y = minCostPath(input, m, n, r+1, c);
    int z = minCostPath(input, m, n, r+1, c+1);

    int ans = min(x, min(y, z)) + input[r][c];

    return ans;
}

int minCostPath(int **input, int m, int n) {
    return(input, m, n, 0, 0);
}

int main() {
    int m,n;
    cin >>m>>n;
    int **input = new int*[m];
    for(int i = 0; i < m; i++) {
        input[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin>>input[i][j];
        }
    }

    cout << minCostPath(input, m, n);
}