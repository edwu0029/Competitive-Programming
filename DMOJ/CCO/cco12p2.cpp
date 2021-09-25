/*
The Hungary Games
Canadian Computing Olympiad: 2012 Day 1, Problem 2
https://dmoj.ca/problem/cco12p2
*/

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
const int MAXN = 2e4+5, LOG = 16;
struct E{
    int v, w;
    bool friend operator<(const E &A, const E &B){
        return A.w>B.w;
    }
};
int N, M, dis[MAXN][2];
vector<E>adj[MAXN];
priority_queue<E>pq;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b, w;i<M;i++){
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1][0]=0;
    pq.push({1, 0});
    while(!pq.empty()){
        int curv = pq.top().v, curw = pq.top().w; pq.pop();
        for(E i:adj[curv]){
            if(dis[i.v][0]>curw+i.w){
                dis[i.v][1]=dis[i.v][0];
                dis[i.v][0]=curw+i.w;
                pq.push({i.v, curw+i.w});
            }else if(dis[i.v][1]>curw+i.w&&dis[i.v][0]!=curw+i.w){
                dis[i.v][1]=curw+i.w;
                pq.push({i.v, curw+i.w});
            }
        }
    }
    if(dis[N][1]==0x3f3f3f3f)cout << -1 << '\n';
    else cout << dis[N][1] << '\n';
    return 0;
}