#include<iostream>
using namespace std;

// Recursive solution
int maxSum(int *arr, int s, int n) {
    // Base case
    if(s == n) {
        return arr[s];
    }
    if(s > n) {
        return 0;
    }

    //recursive call
    int including = maxSum(arr, s+2, n) + arr[s];
    int excluding = maxSum(arr, s+1, n);

    return max(including, excluding); // small calculation and return
}

// Using memorization
int maxSumM(int *arr, int s, int n, int *ans) {
    // Base case
    if(s == n) {
        ans[s] = arr[s];
        return arr[s];
    }
    if(s > n) {
        return 0;
    }

    if(ans[s] != -1) {
        return ans[s];
    }

    //recursive call
    int including = maxSumM(arr, s+2, n, ans) + arr[s];
    int excluding = maxSumM(arr, s+1, n, ans);

    int a = max(including, excluding); 

    ans[s] = a;

    return a;
}

// DP
int maxSumDP(int *arr, int n) {
    int *ans = new int[n];

    ans[0] = arr[0];
    ans[1] = max(arr[1], arr[0]);
    for(int i = 2; i < n; i++) {
        ans[i] = max(arr[i] + ans[i-2], ans[i-1]);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }cout<<endl;
    
    return ans[n-1];
}

int main() {
    int arr[6] = {10,2,30,20,3,50};
    int ans[6] = {-1,-1,-1,-1,-1,-1};
    cout << maxSumDP(arr, 6) <<endl; 
    // for(int i = 0; i < 6; i++){
    //     cout << ans[i] << " ";
    // }
}