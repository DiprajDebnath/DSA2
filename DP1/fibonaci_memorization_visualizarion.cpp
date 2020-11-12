#include<iostream>
using namespace std;

int position;

void print(int *arr) {
    for(int i = 0; i<position+1; i++) {
        cout << arr[i] << "  ";
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
    print(ans); // Print before returning
    return ans[n];
}

int fibo(int n) {
    int *ans = new int[n+1];
    
    // Set default value to -1
    for(int i = 0; i<n+1; i++){
        ans[i] = -1;
    }

    int a = fibo_helper(n, ans);
    return a;
}

int main() {
    cin >> position;
    cout << fibo(position) << endl;
}