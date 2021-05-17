//Problem: https://dmoj.ca/problem/ccc20s2

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
int M, N, F[MAXN][MAXN];
bool vis[MAXN][MAXN], numvis[MAXN*MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> M >> N;
    for(int i = 1;i<=M;i++)
        for(int j = 1;j<=N;j++)
            cin >> F[i][j];
    queue<pii>q;
    q.push(mp(1, 1));
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        vis[cur.f][cur.s] = true;
        int x = F[cur.f][cur.s];
        if(numvis[x]) continue;
        for(int i = 1;i*i<=x;i++){
            if(x%i!=0) continue;
            int j = x/i;
            if(i<=M&&j<=N&&!vis[i][j]){
                q.push(mp(i, j));
                vis[i][j] = true;
            }
            if(j<=M&&i<=N&&!vis[j][i]){
                q.push(mp(j, i));
                vis[j][i] = true;
            }
        }
        numvis[x] = true;
    }
    if(vis[M][N]) cout << "yes" << nl;
    else cout << "no" << nl;
    return 0;
}