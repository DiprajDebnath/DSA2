#include<iostream>
using namespace std;

void print(int *arr, int size) {
    for(int i = 0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int fibo_helper(int n, int *ans) {
    // For 0th and 1st directly return no need to check the array
    if(n <= 1){
        return n;
    }

    // Check if output already exist
    if(ans[n] != -1) {
        return ans[n];
    }

    // Calculate output
    int a = fibo_helper(n-1, ans);
    int b = fibo_helper(n-2, ans);

    // Save the output for future use
    ans[n] = a + b;

    // Return the final output
    return ans[n];
}

int fibo(int n) {
    int *ans = new int[n+1];
    
    // Set default value to -1
    for(int i = 0; i<n+1; i++){
        ans[i] = -1;
    }

    int a = fibo_helper(n, ans);
    print(ans, n+1);
    return a;
}

int main() {
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}