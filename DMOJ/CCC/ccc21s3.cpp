//Problem: https://dmoj.ca/problem/ccc21s3

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
const int MAXN = 2e5+5, LOG = 16;
int N, p[MAXN], w[MAXN], d[MAXN], l[2*MAXN], r[2*MAXN];
ll lft[2*MAXN], rht[2*MAXN];
set<int>positions;
vector<int>pos;
unordered_map<int, int>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> p[i] >> w[i] >> d[i];
        positions.insert(p[i]-d[i]);
        positions.insert(p[i]+d[i]);
    }
    pos.pb(0);
    int cnt = 1;
    for(int i:positions){
        pos.pb(i);
        m[i] = cnt++;
    }
    for(int i = 1;i<=N;i++){
        int p1 = p[i]-d[i];
        int p2 = p[i]+d[i];
        l[m[p2]+1]+=1LL*w[i];
        r[m[p1]-1]+=1LL*w[i];
    }
    ll lsum = 0;
    for(int i = 1;i<pos.size();i++){
        lsum+=1LL*l[i];
        lft[i]+=lft[i-1]+lsum*1LL*(pos[i]-pos[i-1]);
    }
    ll rsum = 0;
    for(int i = pos.size()-1;i>=1;i--){
        rsum+=1LL*r[i];
        rht[i]+=rht[i+1]+rsum*1LL*(pos[i+1]-pos[i]);
    }
    ll ans = infll;
    for(int i = 1;i<pos.size();i++) ans = min(ans, lft[i]+rht[i]);
    cout << ans << nl;
    return 0;
}