#include <iostream>
#include <cmath>
using namespace std;

/* Brute force recursive solution */
int balancedBTs(int h)
{
    if (h <= 1)
    {
        return 1;
    }

    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x) * y) % mod);
    int ans = (temp1 + temp2) % mod;

    return ans;
}

/* Memorization solution */
int balancedBTs2(int h, int *ans)
{
    if (h <= 1)
    {
        return 1;
    }

    if(ans[h] != -1) {
        return ans[h];
    }

    int mod = (int)(pow(10, 9)) + 7;
    int x = balancedBTs2(h - 1, ans);
    int y = balancedBTs2(h - 2, ans);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x) * y) % mod);
    int output = (temp1 + temp2) % mod;

    ans[h] = output;

    return output;
}

int balancedBTs2(int h) {
    int *ans = new int[h+1];
    for(int i = 0; i<=h; i++) {
        ans[i] = -1;
    }

    int a = balancedBTs2(h, ans);
    // for(int i = 0; i<=h; i++) {
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    return a;
}

/* Dynamic Programming */
int balancedBTs3(int h)
{
    int *ans = new int[h+1];
    ans[0] = 1;
    ans[1] = 1;

    for(int i = 2; i<=h; i++) {
        int mod = (int)(pow(10, 9)) + 7;
        int x = ans[i-1];
        int y = ans[i-2];

        int temp1 = (int)(((long)(x)*x) % mod);
        int temp2 = (int)((2 * (long)(x) * y) % mod);
        int output = (temp1 + temp2) % mod;

        ans[i] = output;
    }    

    for(int i = 0; i<=h; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return ans[h];
}

int main() {
    int h;
    cin>>h;
    cout<<balancedBTs(h)<<endl;
}