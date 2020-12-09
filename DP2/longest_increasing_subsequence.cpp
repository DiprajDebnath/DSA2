#include<iostream>
using namespace std;

int lis(int *arr, int n) {
    int *dp = new int[n];

    for(int i = 0; i < n; i++) {
        int a = 0;
        for(int j = i-1; j >= 0; j--){
            if(arr[j] < arr[i]) {
                a = max(a, dp[j]);
            }
        }
        dp[i] = a + 1;
    }

    int best = 0;
    for(int i = 0; i < n; i++) {
        cout << dp[i] << " ";
        if(best < dp[i]){
            best = dp[i];
        }
    }
    cout << endl;
    delete []dp;
    return best;
}

int main() {
    int arr[6] = {5,4,11,1,16,8};
    
    int a = lis(arr, 6);
    cout << a;
}