/*
Degrees Of Separation
Canadian Computing Competition: 2009 Stage 1, Junior #5, Senior #3
https://dmoj.ca/problem/ccc09s3
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
const int MAXN = 55;
int dis[MAXN][MAXN];
bool adj[MAXN][MAXN];
void bfs(int src){
    dis[src][src] = 0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0;i<MAXN;i++){
            if(adj[cur][i]&&dis[src][i]>dis[src][cur]+1){
                q.push(i);
                dis[src][i] = dis[src][cur]+1;
            }
        }
    }
}
void reset(){
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0;i<MAXN;i++){
        bfs(i);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    adj[1][6] = true; adj[6][1] = true;
    adj[2][6] = true; adj[6][2] = true;
    adj[3][6] = true; adj[6][3] = true;
    adj[4][6] = true; adj[6][4] = true;
    adj[5][6] = true; adj[6][5] = true;
    adj[3][4] = true; adj[4][3] = true;
    adj[4][5] = true; adj[5][4] = true;
    adj[3][5] = true; adj[5][3] = true;
    adj[6][7] = true; adj[7][6] = true;
    adj[7][8] = true; adj[8][7] = true;
    adj[8][9] = true; adj[9][8] = true;
    adj[9][10] = true; adj[10][9] = true;
    adj[10][11] = true; adj[11][10] = true;
    adj[11][12] = true; adj[12][11] = true;
    adj[9][12] = true; adj[12][9] = true;
    adj[12][13] = true; adj[13][12] = true;
    adj[13][14] = true; adj[14][13] = true;
    adj[13][15] = true; adj[15][13] = true;
    adj[15][3] = true; adj[3][15] = true;
    adj[16][17] = true; adj[17][16] = true;
    adj[17][18] = true; adj[18][17] = true;
    adj[16][18] = true; adj[18][16] = true;
    reset();
    while(true){
        char op; cin >> op;
        int x, y;
        if(op=='i'){
            cin >> x >> y;
            adj[x][y] = true;
            adj[y][x] = true;
            reset();
        }else if(op=='d'){
            cin >> x >> y;
            adj[x][y] = false;
            adj[y][x] = false;
            reset();
        }else if(op=='n'){
            cin >> x;
            int cnt = 0;
            for(int i = 0;i<MAXN;i++){
                if(adj[x][i]) cnt++;
            }
            cout << cnt << nl;
        }else if(op=='f'){
            cin >> x;
            int cnt = 0;
            for(int i = 0;i<MAXN;i++){
                if(dis[x][i]==2) cnt++;
            }
            cout << cnt << nl;
        }else if(op=='s'){
            cin >> x >> y;
            if(dis[x][y]==inf){
                cout << "Not connected" << nl;
            }else{
                cout << dis[x][y] << nl;
            }
        }else{
            break;
        }
    }
    return 0;
}