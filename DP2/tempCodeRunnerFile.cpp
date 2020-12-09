#include<iostream>
using namespace std;

// Recursive approach
int knapsack(int *w, int *v, int n, int W) {
    if(n == 0 || W == 0){
        return 0;
    }
    
    // if w[0] > W call the function without including it
    if(w[0] > W) { 
        return  knapsack(w+1, v+1, n-1, W);
    }

    // recusive calls
    int x = knapsack(w+1, v+1, n-1, W-w[0]) + v[0]; // Including 1st item
    int y = knapsack(w+1, v+1, n-1, W); // Without including 1st item

    return max(x, y);
}

// Memorization
int knapsackM(int *w, int *v, int n, int W, int **ans) {
    if(n == 0 || W == 0){
        return 0;
    }
    
    // if w[0] > W call the function without including it
    if(w[0] > W) { 
        return  knapsack(w+1, v+1, n-1, W);
    }

    // Check if ans already exist
    if(ans[n][W] != -1){
        return ans[n][W];
    }

    // recusive calls
    int x = knapsackM(w+1, v+1, n-1, W-w[0], ans) + v[0]; // Including 1st item
    int y = knapsackM(w+1, v+1, n-1, W, ans); // Without including 1st item
    int result = max(x, y);

    // Save result for future use and return
    ans[n][W] = result;

    cout<<endl;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 8 ; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout << endl;
    }
    
    return result;
}

int knapsackM(int *w, int *v, int n, int W) {
    int **ans = new int*[n];
    for(int i = 0; i < n+1; i++) {
        ans[i] = new int[W+1];
        for(int j = 0; j < W+1; j++) {
            ans[i][j] = -1;
        }
    }

    int a = knapsackM(w, v, n, W, ans);

    cout<<endl;
    for(int i = 0; i < n+1; i++) {
        for(int j = 0; j < W+1; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout << endl;
    }
    
    return a;
}

int main() {
    int w[4] = {1,2,3,5};
    int v[4] = {1,6,10,16};
    int W = 7;

    cout << knapsackM(w, v, 4 , W);
}
