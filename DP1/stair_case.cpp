#include<iostream>
using namespace std;

int steps(int stairs) {
    if(stairs < 0) {
        return 0;
    }
    if(stairs == 0) {
        return 1; // 0 steps
    }
    return steps(stairs-1) + steps(stairs-2) + steps(stairs-3);
}

int steps2_helper(int stairs, int *ans) {
    if(stairs < 0) {
        return 0;
    }
    if(stairs == 0) {
        return 1; // 0 steps
    }

    // Check if already exist
    if(ans[stairs] != -1) {
        return ans[stairs];
    }

    int a = steps2_helper(stairs-1, ans) + steps2_helper(stairs-2, ans) +steps2_helper(stairs-3, ans);

    // Save for future use
    ans[stairs] = a;
    return a;
}

int steps2(int stairs) {
    int *ans = new int[stairs+1];
    for(int i = 0; i < stairs+1; i++){
        ans[i] = -1;
    }

    return steps2_helper(stairs, ans);
}

int steps3(int stairs) {
    int *ans = new int[stairs+1];

    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;

    for(int i = 4; i<stairs+1; i++) {
        int a = ans[i-1] + ans[i-2] + ans[i-3];
        ans[i] = a;
    } 
    return ans[stairs];
}

int main() {
    int n;
    cin>>n;
    cout<<steps3(n);
}