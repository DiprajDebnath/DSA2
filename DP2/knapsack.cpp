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

    cout << "n :" << n << " W:" << W << endl;

    if(n == 0){
        ans[n][W] = 0;
        return 0;
    }

    if(W == 0){
        ans[n][W] = 0;
        return 0;
    }
    
    // if w[0] > W call the function without including it
    if(w[0] > W) { 
        cout << "direct" << endl;
        int t = knapsackM(w+1, v+1, n-1, W, ans);
        ans[n][W] = t;
        return t;
    }

    // Check if ans already exist
    if(ans[n][W] != -1){
        return ans[n][W];
    }

    // recusive calls
    cout << "x" << endl;
    int x = knapsackM(w+1, v+1, n-1, W-w[0], ans) + v[0]; // Including 1st item
    cout << "y" << endl;
    int y = knapsackM(w+1, v+1, n-1, W, ans); // Without including 1st item
    int result = max(x, y);

    // Save result for future use and return
    ans[n][W] = result;

    cout << endl << "n :" << n << " M:" << W << endl;
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

// DP solution
int knapsackDP(int wt[], int val[], int n, int W) { 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++)  
    { 
        for (w = 0; w <= W; w++)  
        { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= W; j++) {
            cout << K[i][j] << " ";
        }
        cout<<endl;
    }
  
    return K[n][W]; 
} 

int main() {
    int w[4] = {1,2,3,5};
    int v[4] = {1,6,10,16};
    int W = 7;

    cout << knapsackDP(w, v, 4 , W);
}
