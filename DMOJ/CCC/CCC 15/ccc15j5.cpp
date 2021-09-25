/*
π-day
Canadian Computing Competition: 2015 Stage 1, Junior #5
https://dmoj.ca/problem/ccc15j5
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
const int MAXN = 1e6+5;
int N, K, dp[251][251];
int rec(int n, int k){
    if(dp[n][k]!=0)return dp[n][k];
    if(n==k||k==1){
        return dp[n][k] = 1;
    }else if(n<k){
        return dp[n][k] = 0;
    }else{
        dp[n][k] = rec(n-1, k-1)+rec(n-k, k);
    }
    return dp[n][k];
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    cout << rec(N, K) << nl;
    return 0;
}