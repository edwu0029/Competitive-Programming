/*
Two Sets II
https://cses.fi/problemset/task/1093
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
const int MAXN = 1e5+5;
int N;
ll dp[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    int sum = N*(N+1)/2;
    if(sum&1){
        cout << 0 << nl;
        return 0;
    }
    int half = sum/2;
    dp[0] = 1;
    //Use elements 1, 2, ... N-1 to force N into the second set
    //Prevents counting each combo twice
    for(int i = 1;i<=N-1;i++){
        for(int j = half;j>=i;j--){
            if(dp[j-i]>0){
                dp[j] = (dp[j]+dp[j-i])%MOD;
            }
        }
    }
    cout << dp[half] << nl;
    return 0;
}