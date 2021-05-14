//Problem: https://dmoj.ca/problem/cco15p2

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
const int MAXN = 18, LOG = 16;
int n, m, dp[1<<MAXN][MAXN];
vector<pii>adj[MAXN];
bool process[1<<MAXN][MAXN];
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0, s, d, l;i<m;i++){
        scanf("%d%d%d", &s, &d, &l);
        adj[s].push_back({d, l});
    }
    process[1][0] = true;
    for(int mask = 1;mask<(1<<n)-1;mask++){
        for(int i = 0;i<n;i++){
            if(!(mask&(1<<i))||!process[mask][i])continue;
            for(pii j:adj[i]){
                if(mask&(1<<j.first))continue;
                int newmask = mask|(1<<j.first);
                process[newmask][j.first] = true;
                dp[newmask][j.first] = max(dp[newmask][j.first], dp[mask][i]+j.second);
            }
        }
    }
    int ans = 0;
    for(int mask = 1;mask<(1<<n);mask++){
        if((mask&1)&&(mask&(1<<(n-1))))ans = max(dp[mask][n-1], ans);
    }
    printf("%d\n", ans);
    return 0;
}