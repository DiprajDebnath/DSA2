#include<iostream>
using namespace std;

int largestPiece(int **arr, int n, int sr, int sc, bool **visited) {
    
    // Base cases
    if(sr < 0 || sr >= n || sc < 0 || sc >= n){
        return 0;
    }

    if(arr[sr][sc] == 0) {
        return 0;
    }

    if(visited[sr][sc] == true){
        return 0;
    }

    visited[sr][sc] = true;

    // Recursive calls
    int left , right, top, bottom;
    left = largestPiece(arr, n, sr, sc-1, visited);
    right = largestPiece(arr, n, sr, sc+1, visited);
    top = largestPiece(arr, n, sr-1, sc, visited);
    bottom = largestPiece(arr, n, sr+1, sc, visited);

    return left + right + top + bottom + 1;
}

int largestPiece(int **arr, int n) {

    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++) {
        visited[i] = new bool[n];
        for(int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    } 

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = max(ans, largestPiece(arr, n, i, j, visited));
        }
    }

    for(int i = 0; i < n; i++){
        delete []visited[i];
    }
    delete []visited;
    return ans;
}

int main() {
    int n;
    cin >> n;

    int **arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << largestPiece(arr,n);

    for(int i = 0; i < n; i++){
        delete []arr[i];
    }
    delete []arr;
}