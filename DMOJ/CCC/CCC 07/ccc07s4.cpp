/*
Waterpark
Canadian Computing Competition: 2007 Stage 1, Senior #4
https://dmoj.ca/problem/ccc07s4
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
const int MAXN = 1e4+5;
int N, dp[MAXN];
vector<int>adj[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    while(true){
        int x, y; cin >> x >> y;
        if(x==0&&y==0) break;
        adj[x].push_back(y);
    }
    dp[1] = 1;
    for(int i = 1;i<=N;i++){
        for(int j:adj[i]){
            dp[j]+=dp[i];
        }
    }
    cout << dp[N] << nl;
    return 0;
}