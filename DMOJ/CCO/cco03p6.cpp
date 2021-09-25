/*
Cheap Gas
Canadian Computing Olympiad: 2003 Day 2, Problem 3
https://dmoj.ca/problem/cco03p6
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
const int MAXN = 105, LOG = 16;
int t, M, N, F, K;
double cost[MAXN][MAXN][2*MAXN], gas[MAXN][MAXN];
bool ch[MAXN][MAXN];
int mover[4] = {1, -1, 0, 0}, movec[4] = {0, 0, 1, -1};
struct state{
    int r, c, ga; double co;
    state(int rs, int cs, int g, double coss){
        r = rs, c = cs, ga = g, co = coss;
    }
};
void solve(){
    fill_n(&cost[0][0][0], 2*MAXN*MAXN*MAXN, 1e9);
    fill_n(&gas[0][0], MAXN*MAXN, 1e9);
    memset(ch, 0, sizeof(ch));
    cin >> M >> N >> F >> K;
    for(int i = 1, a, b;i<=K;i++){
        double c;
        cin >> a >> b >> c;
        if(!ch[a][b]){gas[a][b] = c; ch[a][b] = true;}
        else gas[a][b] = min(gas[a][b], c);
    }
    F = min(F, M+N);
    queue<state>q;
    q.push(state(1, 1, F, 0.0));
    cost[1][1][F] = 0.0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int r = cur.r, c = cur.c, ga = cur.ga;
        double co = cur.co;
        if(cost[r][c][ga]<co) continue;
        if(ch[r][c]){
            for(int i = ga;i<=F;i++){
                int newga = i; double newco = co+gas[r][c]*(i-ga);
                for(int j = 0;j<4;j++){
                    int nxtr = r+mover[j], nxtc = c+movec[j];
                    if(nxtr<1||nxtr>M||nxtc<1||nxtc>N||newga==0) continue;
                    if(cost[nxtr][nxtc][newga-1]>newco){
                        cost[nxtr][nxtc][newga-1]=newco;
                        q.push(state(nxtr, nxtc, newga-1, newco));
                    }
                }
            }
        }else{
            for(int j = 0;j<4;j++){
                int nxtr = r+mover[j], nxtc = c+movec[j];
                if(nxtr<1||nxtr>M||nxtc<1||nxtc>N||ga==0) continue;
                if(cost[nxtr][nxtc][ga-1]>co){
                    cost[nxtr][nxtc][ga-1]=co;
                    q.push(state(nxtr, nxtc, ga-1, co));
                }
            }
        }
    }
    double ans = 1e9;
    for(int i = 0;i<=F;i++) ans = min(ans, cost[M][N][i]);
    if(ans<1e9) cout << fixed << setprecision(2) << ans << nl;
    else cout << "Stranded on the shoulder" << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}