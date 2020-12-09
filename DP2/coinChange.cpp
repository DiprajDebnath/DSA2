#include<iostream>
using namespace std;

int countWaysToMakeChange(int arr[], int n, int value) {
    if(value <= 0) {
        return 0;
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int value;
    cin >> value;
    cout << countWaysToMakeChange(arr, n, value);
    delete []arr;
}