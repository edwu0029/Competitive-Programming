//Problem: https://dmoj.ca/problem/coci06c1p4

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
int R, C, dis[51][51], sR, sC, moves[2][4]={{0, 0 , 1, -1}, {1, -1, 0, 0}}, ans = -1;
char m[51][51];
bool vis[51][51], floodvis[51][51], tmp;
queue<pair<int, int>>q, flood;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> R >> C;
    for(int i = 0;i<R;i++){
        string s; cin >> s;
        for(int j = 0;j<C;j++){
            m[i][j]=s[j];
            if(m[i][j]=='S'){
                sR = i; sC = j;
            }
            if(m[i][j]=='*'){
                flood.push(make_pair(i, j)); floodvis[i][j]=true;
            }
        }
    }
    q.push(make_pair(sR, sC));
    vis[sR][sC]=true;
    while(!q.empty()){
        int fSize = flood.size(), qSize = q.size(), curR, curC, newR, newC;
        for(int f = 0;f<fSize;f++){
            curR = flood.front().first; curC = flood.front().second;
            flood.pop();
            for(int i = 0;i<4;i++){
                newR = moves[0][i]+curR; newC = moves[1][i]+curC; 
                if(newR>=0&&newR<R&&newC>=0&&newC<C&&!floodvis[newR][newC]&&(m[newR][newC]=='.'||m[newR][newC]=='S')){
                    flood.push(make_pair(newR, newC));
                    floodvis[newR][newC]=true;
                }
            }
        }
        for(int g = 0;g<qSize;g++){
            curR = q.front().first; curC = q.front().second;
            q.pop();
            if(m[curR][curC]=='D'){ans = dis[curR][curC]; tmp = true; break;}
            for(int i = 0;i<4;i++){
                newR = moves[0][i]+curR; newC = moves[1][i]+curC;
                if(newR>=0&&newR<R&&newC>=0&&newC<C&&!floodvis[newR][newC]&&!vis[newR][newC]&&m[newR][newC]!='X'){
                    q.push(make_pair(newR, newC));
                    vis[newR][newC]=true;
                    dis[newR][newC]=dis[curR][curC]+1;
                }
            }
        }
        if(tmp) break;
    }
    if(ans==-1) cout << "KAKTUS" << nl;
    else cout << ans << nl;
    return 0;
}