/*
A Romantic Dinner
DMOPC '13 Contest 3 P5
https://dmoj.ca/problem/dmopc13c3p5
*/

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 1005, LOG = 16;
int M, U, R, dp[305][102], ans;
bool vis[305][102];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> M >> U >> R;
    vis[0][0]=true;
    for(int i = 1, v, t, f;i<=R;i++){
        cin >> v >> t >> f;
        for(int m = M;m>=t;m--){
            for(int u = U;u>=f;u--){
                if(vis[m-t][u-f]){
                    vis[m][u]=true;
                    dp[m][u]=max(dp[m][u], dp[m-t][u-f]+v);
                    ans = max(ans, dp[m][u]);
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}