#include<iostream>
#include<string>
using namespace std;


// Recursive
int editDistance(string s1, string s2) {
    if(s1.size() == 0 || s2.size() == 0) {
        return max(s1.size(), s2.size());
    }

    if(s1[0] == s2[0]) {
        return editDistance(s1.substr(1), s2.substr(1));
    }
    else{
        int a = editDistance(s1.substr(1), s2) + 1; // insert
        int b = editDistance(s1, s2.substr(1)) + 1; // delete
        int c = editDistance(s1.substr(1), s2.substr(1)) + 1; // replace
        return min(a, min(b, c));
    }
}

// Memorization
int editDistanceM(string s1, string s2, int **ans) {
    int m = s1.size();
    int n = s2.size();
    int result;
    // Base case
    if(s1.size() == 0 || s2.size() == 0) {
        return max(s1.size(), s2.size());
    }

    if(s1[0] == s2[0]) {
        return editDistanceM(s1.substr(1), s2.substr(1), ans);
    }

    // Check if ans already exist
    if(ans[m][n] != -1) {
        return ans[m][n];
    }
    else{
        int a = editDistanceM(s1.substr(1), s2, ans) + 1; // insert
        int b = editDistanceM(s1, s2.substr(1), ans) + 1; // delete
        int c = editDistanceM(s1.substr(1), s2.substr(1), ans) + 1; // replace
        result = min(a, min(b, c));
    }

    // Save result for future use
    ans[m][n] = result;

    // Return ans
    return result;
}

int editDistanceM(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    int **ans = new int*[m+1];
    for(int i = 0; i < m + 1; i++) {
        ans[i] = new int[n+1];
        for(int j = 0; j < n+1; j++) {
            ans[i][j] = -1;
        }
    }
    return editDistanceM(s1, s2, ans);
}

// Dynamic Programming
int editDistanceDP(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    int **ans = new int*[m+1];
    for(int i = 0; i < m + 1; i++) {
        ans[i] = new int[n+1];
    }
    
    for(int i = 0; i < m+1; i++) {
        ans[i][0] = i; // column 0
    }
    for(int i = 1; i < n+1; i++) {
        ans[0][i] = i; // row 0
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[m-i] == s2[n-j]) {
                ans[i][j] = ans[i-1][j-1];
            }
            else {
                int a = ans[i-1][j] + 1;
                int b = ans[i][j-1] + 1;
                int c = ans[i-1][j-1] + 1;
                ans[i][j] = min(a, min(b,c));
            }
        }
    }

    // for(int i = 0; i <= m; i++) {
    //     for(int j = 0; j <= n; j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    return ans[m][n];
}

int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;

    cout << editDistanceDP(s1, s2);
}