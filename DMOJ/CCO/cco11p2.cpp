//Problem: https://dmoj.ca/problem/cco11p2

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
// #define f first
// #define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 2e4+5, LOG = 16;
struct path{
	int v, d, s;
	friend bool operator<(const path &a, const path &b){
		return a.d>b.d;
	}
};
int S, N, E, dis[1601][3601], ans = inf;
vector<path>adj[1601];
priority_queue<path>pq;
int main(){
    scanf("%d%d%d", &S, &N, &E);
	for(int i = 0, s, t, d, u;i<E;i++){
		scanf("%d%d%d%d", &s, &t, &d, &u);
		if(u==1){u=d;}
		else u = 0;
		adj[s].push_back({t, d, u});
		adj[t].push_back({s, d, u});
	}
	memset(dis, 0x3f, sizeof(dis));
	pq.push({0, 0, 0}); dis[0][0]=0;
	while(!pq.empty()){
		int v = pq.top().v, d = pq.top().d, s = pq.top().s;
		if(v==N-1)break;
		pq.pop();
		for(path i:adj[v]){
			if(s+i.s<=S&&dis[i.v][s+i.s]>dis[v][s]+i.d){
				dis[i.v][s+i.s]=dis[v][s]+i.d;
				pq.push({i.v, dis[i.v][s+i.s], s+i.s});
			}
		}
	}
	for(int i = 0;i<=S;i++)ans = min(ans, dis[N-1][i]);
	if(ans==0x3f3f3f3f){printf("-1\n"); return 0;}
	printf("%d\n", ans);
}