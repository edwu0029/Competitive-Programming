/*
Duodecim Ferra
AtCoder Beginner Contest 185, Problem C
https://atcoder.jp/contests/abc185/tasks/abc185_c
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
const ll MODll = 4000004479;
const int MAXN = 205;
int L;
ll dp[MAXN][MAXN];
bool solved[MAXN][MAXN];
ll solve(int lft, int num){
    //dp[length left][number of cuts needed]
    if(solved[lft][num]) return dp[lft][num];
    if(num==1){
        solved[lft][num] = true;
        return dp[lft][num] = lft-1;
    }
    for(int i = 1;i<=lft-num;i++){
        dp[lft][num]+=solve(lft-i, num-1);
    }
    solved[lft][num] = true;
    return dp[lft][num];
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> L;
    cout << solve(L, 11) << nl;
    return 0;
}