//Problem: https://dmoj.ca/problem/dmopc18c4p4

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
typedef tuple<int, int, int, int>tiiii;
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
const int MAXN = 2e5+5, LOG = 16;
int N, Q;
ll bit[MAXN], ans[MAXN];
pii values[MAXN];
tiiii queries[MAXN];
void update(int i, int val){
	for(;i<=N;i+=(i&-i))bit[i]+=val;
}
ll query(int i){
	ll sum = 0;
	for(;i>0;i-=(i&-i))sum+=bit[i];
	return sum;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
	for(int i = 1, x;i<=N;i++){cin >> x; values[i] = {x, i};}
	for(int i = 1, l, r, k;i<=Q;i++){cin >> l >> r >> k; queries[i] = {k, l, r, i};}
	sort(values+1, values+1+N); sort(queries+1, queries+1+Q);
	int curIndexV = N, maxV = values[N].first, curK, curL, curR, curI;
	for(int curIndexQ = Q;curIndexQ>=0;curIndexQ--){
		curK = get<0>(queries[curIndexQ]);
		curL = get<1>(queries[curIndexQ]);
		curR = get<2>(queries[curIndexQ]);
		curI = get<3>(queries[curIndexQ]);
		while(maxV>=curK&&curIndexV>=1){
			update(values[curIndexV].second, values[curIndexV].first);
			curIndexV--;
			if(curIndexV>=1)maxV = values[curIndexV].first;
		}
		ans[curI] = query(curR)-query(curL-1);
	}
	for(int i = 1;i<=Q;i++){
		curL = get<1>(queries[i]);
		curR = get<2>(queries[i]);
		curI = get<3>(queries[i]);
		ans[curI] = 2*ans[curI]-(query(curR)-query(curL-1));
	}
	for(int i = 1;i<=Q;i++)cout << ans[i] << nl;
    return 0;
}