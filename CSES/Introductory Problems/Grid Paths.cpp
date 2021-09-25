/*
Grid Paths
https://cses.fi/problemset/task/1625/
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
string path;
ll ans;
bool vis[10][10];
bool bounds(int r, int c){
    return 1<=r&&r<=7&&1<=c&&c<=7;
}
void rec(int idx, int r, int c){
    if(idx==48){
        if(r==7&&c==1) ans++;
        return;
    }
    if(r==7&&c==1) return;
    if(abs(7-r)+abs(1-c)>48-idx) return;
    //If sandwiched from top and bottom by visited, you will be trapped
    if(vis[r+1][c]&&vis[r-1][c]&&!vis[r][c+1]&&!vis[r][c-1]) return;
    //If sandwiched from left and right by visited, you will be trapped
    if(vis[r][c+1]&&vis[r][c-1]&&!vis[r+1][c]&&!vis[r-1][c]) return;
    vis[r][c] = true;
    if(path[idx]=='?'||path[idx]=='R'){
        int newR = r, newC = c+1;
        if(bounds(newR, newC)&&!vis[newR][newC]){
            rec(idx+1, newR, newC);
        }
    }
    if(path[idx]=='?'||path[idx]=='L'){
        int newR = r, newC = c-1;
        if(bounds(newR, newC)&&!vis[newR][newC]){
            rec(idx+1, newR, newC);
        }
    }
    if(path[idx]=='?'||path[idx]=='D'){
        int newR = r+1, newC = c;
        if(bounds(newR, newC)&&!vis[newR][newC]){
            rec(idx+1, newR, newC);
        }
    }
    if(path[idx]=='?'||path[idx]=='U'){
        int newR = r-1, newC = c;
        if(bounds(newR, newC)&&!vis[newR][newC]){
            rec(idx+1, newR, newC);
        }
    }
    vis[r][c] = false;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> path;
    for(int i = 0;i<=8;i++){
        for(int j = 0;j<=8;j++){
            if(i==0||i==8||j==0||j==8){
                vis[i][j] = true;
            }
        }
    }
    rec(0, 1, 1);
    cout << ans << nl;
}