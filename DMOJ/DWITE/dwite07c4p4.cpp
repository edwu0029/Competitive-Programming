/*
Shortest path around
DWITE Online Computer Programming Contest, January 2008, Problem 4
https://dmoj.ca/problem/dwite07c4p4
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
int dis[15][15];
pii moves[8] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
char m[15][15];
bool bounds(int r, int c){
    return 1<=r&&r<=10&&1<=c&&c<=10;
}
void solve(){
    int str = 0, stc = 0, edr = 0, edc = 0;
    for(int i = 1;i<=10;i++){
        string s; cin >> s;
        for(int j = 1;j<=10;j++){
            m[i][j] = s[j-1];
            if(m[i][j]=='X'){
                if(str==0){
                    str = i, stc = j;
                }else{
                    edr = i, edc = j;
                }
            }
        }
    }
    queue<pii>q;
    memset(dis, 0x3f, sizeof(dis));
    dis[str][stc] = 0;
    q.push(mp(str, stc));
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        int r = cur.first, c = cur.second;
        for(int i = 0;i<8;i++){
            int newR = r+moves[i].first, newC = c+moves[i].second;
            if(bounds(newR, newC)&&m[newR][newC]!='#'&&dis[newR][newC]>dis[r][c]+1){
                q.push(mp(newR, newC));
                dis[newR][newC] = dis[r][c]+1;
            }
        }
    }
    cout << dis[edr][edc] << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    string line;
    for(int i = 0;i<5;i++){
        solve();
        cin >> line;
    }
}