/*
Knight Hop
Canadian Computing Competition: 2010 Stage 1, Junior #5
https://dmoj.ca/problem/ccc10j5
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
queue<pii>Q;
pii st,ed;
int F[8][2]={{2,1},{2,-1},{1, 2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};
int dis[9][9];
bool vis[9][9];
int main(){
    scanf("%d%d%d%d",&st.f,&st.s,&ed.f,&ed.s);
    Q.push(st);
    vis[st.f][st.s]=true;
    while(!Q.empty()){
        int curR = Q.front().f, curC = Q.front().s;
        Q.pop();
        for(int i = 0;i<8;i++){
            int curR2 = curR+F[i][0], curC2 = curC+F[i][1];
            if(curR2>0&&curR2<9&&curC2>0&&curC2<9&&!vis[curR2][curC2]){
                dis[curR2][curC2]=dis[curR][curC]+1;
                vis[curR2][curC2]=true;
                Q.push(mp(curR2,curC2));
            }
        }
    }
    printf("%d\n",dis[ed.f][ed.s]);
}