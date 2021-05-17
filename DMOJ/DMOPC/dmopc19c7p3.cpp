//Problem: https://dmoj.ca/problem/dmopc19c7p3

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
const int MAXN = 1e6+5, LOG = 16;
int N;
ll K, w[MAXN], sum;
bool vis[MAXN], done;
vector<int>adj[MAXN], ans;
void dfs(int cur, int pre){
	ans.push_back(cur); vis[cur] = true; sum+=w[cur];
	if(sum>=K&&sum<=2*K){
		done = true; return;
	}
	for(int i:adj[cur]){
		if(i==pre||vis[i]||sum+w[i]>2*K)continue;
		dfs(i, cur);
		if(done)return;
	}
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
	for(int i = 1;i<=N;i++){
		cin >> w[i]; if(w[i]>K)vis[i] = true;
	}
	for(int i = 1, x, y;i<=N-1;i++){
		cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	for(int i = 1;i<=N;i++){
		if(!vis[i]){
			ans.clear(); done = false; sum = 0;
			dfs(i, -1);
			if(done)break;
		}
	}
	if(done){
		cout << ans.size() << nl;
		for(int i:ans) cout << i << " ";
		cout << nl;
	}else cout << "-1" << nl;
    return 0;
}