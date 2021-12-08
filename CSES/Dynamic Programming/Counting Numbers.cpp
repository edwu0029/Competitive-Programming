/*
Counting Numbers
https://cses.fi/problemset/task/2220
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
ll A, B, dp[20][10][2][2];
ll traverse(vector<int>& digits, int p, int prev_digit, bool leading_zeros, bool tight){
    if(p==0) return 1;
    if(dp[p][prev_digit][leading_zeros][tight]>0) return dp[p][prev_digit][leading_zeros][tight];
    int r = 9;
    if(tight) r = digits[digits.size()-p];
    for(int i = 0;i<=r;i++){
        if(!leading_zeros&&i==prev_digit) continue;
        bool a = leading_zeros&&(i==0), b = tight&&(i==r);
        dp[p][prev_digit][leading_zeros][tight]+=traverse(digits, p-1, i, a, b);
    }
    return dp[p][prev_digit][leading_zeros][tight];
}
ll solve(ll X){
    if(X<0) return 0;
    memset(dp, 0, sizeof(dp));
    vector<int>digits;
    while(X>0){
        digits.push_back(X%10);
        X/=10;
    }
    reverse(digits.begin(), digits.end());
    return traverse(digits, digits.size(), -1, true, true);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> A >> B;
    cout << solve(B)-solve(A-1) << nl;
    return 0;
}