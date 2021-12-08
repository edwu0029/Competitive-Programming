/*
Elevator Rides
https://cses.fi/problemset/task/1653
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
const int MAXN = 22;
int N, X, w[MAXN];
pii dp[1<<MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> X;
    for(int i = 0;i<N;i++) cin >> w[i];
    dp[0] = {1, 0};
    for(int mask = 1;mask<(1<<N);mask++){
        dp[mask] = {inf, 0};
        for(int i = 0;i<N;i++){
            if(mask&(1<<i)){
                //Pick the last person who entered the elevator
                auto [cnt, cur_w] = dp[mask^(1<<i)];
                if(cur_w+w[i]<=X){
                    cur_w+=w[i];
                }else{
                    cnt++;
                    cur_w = w[i];
                }
                dp[mask] = min(dp[mask], {cnt, cur_w});
            }
        }
    }
    cout << dp[(1<<N)-1].first << nl;
 
    return 0;
}