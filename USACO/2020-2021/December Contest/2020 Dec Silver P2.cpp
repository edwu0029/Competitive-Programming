/*
Rectangular Pasture
USACO 2020 December Contest, Silver, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=1063
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
const int MAXN = 2505;
int N, sum[MAXN][MAXN];
ll ans;
pii F[MAXN];
vector<int>vx, vy;
map<int, int>mx, my;
ll qry(int x1, int y1, int x2, int y2){
    return 1LL*sum[x2+1][y2+1]-sum[x2+1][y1]-sum[x1][y2+1]+sum[x1][y1];
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        int x, y;
        cin >> x >> y;
        F[i] = mp(x, y);
        vx.push_back(x); vy.push_back(y);
    }
    sort(vx.begin(), vx.end());
    for(int i = 0;i<vx.size();i++) mx[vx[i]] = i+1;
    sort(vy.begin(), vy.end());
    for(int i = 0;i<vy.size();i++) my[vy[i]] = i+1;
    for(int i = 0;i<N;i++){
        int nx = mx[F[i].first], ny = my[F[i].second];
        F[i] = mp(nx, ny);
        sum[nx][ny]++;
    }
    sort(F, F+N, [](pii a, pii b)->int{
        return a.second<b.second;
    });
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    ans = 1;
    for(int i = 0;i<N;i++){
        for(int j = i;j<N;j++){
            int a = min(F[i].first, F[j].first), b = max(F[i].first, F[j].first);
            ans+=qry(b-1, i, N-1, j)*qry(0, i, a-1, j);
        }
    }
    cout << ans << nl;
    return 0;
}