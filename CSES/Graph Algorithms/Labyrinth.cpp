/*
Labyrinth
https://cses.fi/problemset/task/1193/
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
const int MAXN = 1005;
int N, M, dis[MAXN][MAXN];
char m[MAXN][MAXN];
bool vis[MAXN][MAXN];
pii steps[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char moves[4] = {'R', 'L', 'D', 'U'}, pre[MAXN][MAXN];
bool bounds(int r, int c){
    return 1<=r&&r<=N&&1<=c&&c<=M;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    int str, stc, edr, edc;
    for(int i = 1;i<=N;i++){
        string s; cin >> s;
        for(int j = 1;j<=M;j++){
            m[i][j] = s[j-1];
            if(m[i][j]=='A'){
                str = i; stc = j;
            }else if(m[i][j]=='B'){
                edr = i; edc = j;
            }
        }
    }
    queue<pii>q;
    q.push(mp(str, stc));
    vis[str][stc] = true;
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        int r = cur.first, c = cur.second;
        if(cur.first==edr&&cur.second==edc) break;
        for(int i = 0;i<4;i++){
            pii step = steps[i];
            int newR = r+step.first, newC = c+step.second;
            if(bounds(newR, newC)&&!vis[newR][newC]&&m[newR][newC]!='#'){
                q.push(mp(newR, newC));
                dis[newR][newC] = dis[r][c]+1;
                vis[newR][newC] = true;
                pre[newR][newC] = moves[i];
            }
        }
    }
    if(vis[edr][edc]){
        cout << "YES" << nl;
        cout << dis[edr][edc] << nl;
    }else{
        cout << "NO" << nl;
        return 0;
    }
    pii p = mp(edr, edc);
    vector<char>ans;
    while(p.first!=str||p.second!=stc){
        char mo = pre[p.first][p.second];
        if(mo=='L') p = mp(p.first, p.second+1);
        else if(mo=='R') p = mp(p.first, p.second-1);
        else if(mo=='U') p = mp(p.first+1, p.second);
        else p = mp(p.first-1, p.second);
        ans.push_back(mo);
    }
    reverse(ans.begin(), ans.end());
    for(auto i:ans) cout << i;
    return 0;
}