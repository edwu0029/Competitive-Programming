/*
Maze
Canadian Computing Competition: 2008 Stage 1, Senior #3
https://dmoj.ca/problem/ccc08s3
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
int T, R, C, dis[25][25];
char m[25][25];
pii moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool bounds(int r, int c){
    return 1<=r&&r<=R&&1<=c&&c<=C;
}
void solve(){
    memset(dis, 0x3f, sizeof(dis));
    cin >> R >> C;
    for(int i = 1;i<=R;i++){
        string s; cin >> s;
        for(int j = 1;j<=C;j++){
            m[i][j] = s[j-1];
        }
    }
    queue<pii>q;
    q.push({1, 1});
    dis[1][1] = 1;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        int r = cur.first, c = cur.second, lft, rht;
        if(r==R&&c==C) break;
        if(m[r][c]=='-'){
            lft = 2, rht = 4;
        }else if(m[r][c]=='|'){
            lft = 0, rht = 2;
        }else if(m[r][c]=='+'){
            lft = 0, rht = 4;
        }
        for(int i = lft;i<rht;i++){
            int nr = r+moves[i].first, nc = c+moves[i].second;
            if(bounds(nr, nc)&&m[nr][nc]!='*'&&dis[nr][nc]>dis[r][c]+1){
                q.push(mp(nr, nc));
                dis[nr][nc] = dis[r][c]+1;
            }
        }
    }
    if(dis[R][C]==inf){
        cout << -1 << nl;
    }else{
        cout << dis[R][C] << nl;
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}