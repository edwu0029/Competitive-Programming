/*
Crazy Fencing
Canadian Computing Competition: 2021 Stage 1, Senior #1
https://dmoj.ca/problem/ccc21s1
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
const int MAXN = 1e4+5, LOG = 16;
int N, h[MAXN], w[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N+1;i++) cin >> h[i];
    for(int i = 1;i<=N;i++) cin >> w[i];
    int tot = 0;
    for(int i = 1;i<=N;i++) tot+=(h[i]+h[i+1])*w[i];
    if(tot%2==0) cout << tot/2 << nl;
    else cout << tot/2 << ".5" << nl;
    return 0;
}