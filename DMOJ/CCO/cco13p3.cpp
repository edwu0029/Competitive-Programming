/*
LHC
Canadian Computing Olympiad: 2013 Day 1, Problem 3
https://dmoj.ca/problem/cco13p3
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
const int MAXN = 4e5+5, LOG = 16;
int N, dis[MAXN], dist;
ll cnt[MAXN], num;
vector<int>adj[MAXN];
void dfs(int cur, int pa){
    cnt[cur]=1;
    for(int i:adj[cur]){
        if(i==pa) continue;
        dfs(i, cur);
        if(dis[cur]+dis[i]+1>dist){
            dist=dis[cur]+dis[i]+1;
            num=cnt[cur]*cnt[i];
        }else if(dis[cur]+dis[i]+1==dist){
            num+=cnt[cur]*cnt[i];
        }
        if(dis[i]+1>dis[cur]){
            dis[cur]=dis[i]+1;
            cnt[cur]=cnt[i];
        }else if(dis[i]+1==dis[cur]){
            cnt[cur]+=cnt[i];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i=1, a, b;i<=N-1;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    cout << dist+1 << sp << num << nl;
    return 0;
}