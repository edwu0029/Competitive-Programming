//Problem: https://dmoj.ca/problem/ccc18s3

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
const int MAXN = 1002;
int N, M, dis[MAXN][MAXN], mover[4] = {0, 0, 1, -1}, movec[4] = {1, -1, 0, 0};
char F[MAXN][MAXN];
bool blocked[MAXN][MAXN];
bool check(int r, int c){
    return 1<=r&&r<=N&&1<=c&&c<=M;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    int Sr, Sc;
    vector<pii>cameras;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            cin >> F[i][j];
            if(F[i][j]=='S') Sr = i, Sc = j;
            else if(F[i][j]=='W') blocked[i][j] = true; 
            else if(F[i][j]=='C'){blocked[i][j]= true; cameras.pb(mp(i, j));}
        }
    }
    for(pii cur: cameras){
        //Up
        for(int i = cur.f;i>=1;i--){
            if(F[i][cur.s]=='W') break;
            else if(F[i][cur.s]=='.'||F[i][cur.s]=='S') blocked[i][cur.s] = true;
        }
        //Down
        for(int i = cur.f;i<=N;i++){
            if(F[i][cur.s]=='W') break;
            else if(F[i][cur.s]=='.'||F[i][cur.s]=='S') blocked[i][cur.s] = true;
        }
        //Left
        for(int i = cur.s;i>=1;i--){
            if(F[cur.f][i]=='W') break;
            else if(F[cur.f][i]=='.'||F[cur.f][i]=='S') blocked[cur.f][i] = true;
        }
        //Right
        for(int i = cur.s;i<=M;i++){
            if(F[cur.f][i]=='W') break;
            else if(F[cur.f][i]=='.'||F[cur.f][i]=='S') blocked[cur.f][i] = true;
        }
    }
    memset(dis, inf, sizeof(dis));
    queue<pii>q;
    bool flag = false;
    if(blocked[Sr][Sc]) flag = true;
    q.push(mp(Sr, Sc));
    if(!flag) dis[Sr][Sc] = 0;
    while(!q.empty()&&!flag){
        pii cur = q.front(); q.pop();
        if(blocked[cur.f][cur.s]) break;
        char type = F[cur.f][cur.s];
        if(type=='.'||type=='S'){
            for(int i = 0;i<4;i++){
                int nxtr = mover[i]+cur.f, nxtc = movec[i]+cur.s;
                if(check(nxtr, nxtc)
                    &&dis[nxtr][nxtc]>dis[cur.f][cur.s]+1&&!blocked[nxtr][nxtc]){
                    q.push(mp(nxtr, nxtc));
                    dis[nxtr][nxtc] = dis[cur.f][cur.s]+1;
                }
            }
        }else if(type=='L'){
            int nxtr = cur.f, nxtc = cur.s-1;
            if(check(nxtr, nxtc)&&dis[nxtr][nxtc]>dis[cur.f][cur.s]&&!blocked[nxtr][nxtc]){
                q.push(mp(nxtr, nxtc));
                dis[nxtr][nxtc] = dis[cur.f][cur.s];
            }
        }else if(type=='R'){
            int nxtr = cur.f, nxtc = cur.s+1;
            if(check(nxtr, nxtc)&&dis[nxtr][nxtc]>dis[cur.f][cur.s]&&!blocked[nxtr][nxtc]){
                q.push(mp(nxtr, nxtc));
                dis[nxtr][nxtc] = dis[cur.f][cur.s];
            }
        }else if(type=='U'){
            int nxtr = cur.f-1, nxtc = cur.s;
            if(check(nxtr, nxtc)&&dis[nxtr][nxtc]>dis[cur.f][cur.s]&&!blocked[nxtr][nxtc]){
                q.push(mp(nxtr, nxtc));
                dis[nxtr][nxtc] = dis[cur.f][cur.s];
            }
        }else if(type=='D'){
            int nxtr = cur.f+1, nxtc = cur.s;
            if(check(nxtr, nxtc)&&dis[nxtr][nxtc]>dis[cur.f][cur.s]&&!blocked[nxtr][nxtc]){
                q.push(mp(nxtr, nxtc));
                dis[nxtr][nxtc] = dis[cur.f][cur.s];
            }
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=M;j++){
            if(F[i][j]!='.') continue;
            if(dis[i][j]==inf){
                cout << -1 << nl;
            }else{
                cout << dis[i][j] << nl;
            }
        }
    }
    return 0;
}