/*
Mouse Journey
Canadian Computing Competition: 2012 Stage 1, Senior #5
https://dmoj.ca/problem/ccc12s5
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
int R, C, K, dp[30][30];
bool cat[30][30];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> R >> C >> K;
    for(int i = 0, a, b;i<K;i++){
        cin >> a >> b;
        cat[a][b] = true;
    }
    dp[1][1] = 1;
    for(int i = 1;i<=R;i++){
        for(int j = 1;j<=C;j++){
            if(i+1<=R&&!cat[i+1][j]){
                dp[i+1][j]+=dp[i][j];
            }
            if(j+1<=C&&!cat[i][j+1]){
                dp[i][j+1]+=dp[i][j];
            }
        }
    }
    cout << dp[R][C] << nl;
}