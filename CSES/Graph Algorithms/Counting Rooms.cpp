//Problem: https://cses.fi/problemset/task/1192/

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
int N, M;
pii steps[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char m[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool bounds(int r, int c){
    return 1<=r&&r<=N&&1<=c&&c<=M;
}
void dfs(int r, int c){
    vis[r][c] = true;
    for(auto step:steps){
        int newR = r+step.first, newC = c+step.second;
        if(bounds(newR, newC)&&!vis[newR][newC]&&m[newR][newC]=='.'){
            dfs(newR, newC);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1;i<=N;i++){
        string s; cin >> s;
        for(int j = 1;j<=M;j++){
            m[i][j] = s[j-1];
        }
    }
    int ans = 0;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(m[i][j]=='.'&&!vis[i][j]){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << nl;
    return 0;
}