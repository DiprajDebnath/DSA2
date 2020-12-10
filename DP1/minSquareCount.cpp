#include<iostream>
#include<cmath>
using namespace std;

/* Recursion */
int minCount(int n) {
    if(n == 0) {
        return 0;
    }

    int a = INT32_MAX;
    for(int i = 1; i <= sqrt(n); i++) {
        a = min(a, minCount(n - pow(i,2)));
    }

    return a + 1;
}

void print(int n, int *ans){
    for(int i = 0;i<=n; i++){
        cout<<ans[i] << " ";
    }
    cout<<endl;
}

/* Memorization */
int minCount2(int n, int *ans) {
    if(n == 0) {
        return 0;
    }

    if(ans[n] != -1) {
        return ans[n];
    }

    int output = INT32_MAX;
    for(int i = 1; i <= sqrt(n); i++) {
        output = min(output, minCount2(n-pow(i,2), ans));
    }

    ans[n] = output+1;
    return output+1;
}

int minCount2(int n) {
    int *ans = new int[n+1];
    for(int i = 0; i<=n; i++){
        ans[i] = -1;
    }
    int a = minCount2(n, ans);
    print(n, ans);
    return a;
}
 
/* Dynamic Programming */
int minCount3(int n) {
    int output;
    int *ans = new int[n+1];
    ans[0] = 0;
    
    for(int i = 1; i<=n;i++){
        output = ans[i - 1];
        if(i >= 4){
            output = min(output, ans[i - 4]);
        }
        if(i >= 9) {
            output = min(output, ans[i-9]);
        }
        ans[i] = output + 1;
    }
    print(n,ans);
    return ans[n];
}

int main() {
    int n;
    cin>>n;
    cout << minCount2(n);
}