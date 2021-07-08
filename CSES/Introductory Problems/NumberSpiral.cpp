//Problem: https://cses.fi/problemset/task/1071/

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
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 2e5+5;
int T;
ll y, x;
ll dist(ll x1, ll y1, ll x2, ll y2){
    return abs(x1-x2)+abs(y1-y2);
}
void solve(){
    cin >> y >> x;
    ll t;
    if(x>y){
        if(x%2==0){
            t = dist(1, x, x, y);
        }else{
            t = dist(x, 1, x, y);
        }
    }else{
        if(y%2==0){
            t = dist(1, y, x, y);
        }else{
            t = dist(y, 1, x, y);
        }
    }
    cout << max(x, y)*max(x, y)-t << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}