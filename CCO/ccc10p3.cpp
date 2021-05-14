//Problem: https://dmoj.ca/problem/cco10p3

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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
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
ordered_set t;
int N, cnt, F[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i=1;i<=N;i++){
        char c; cin >> c;
        if(c=='N'){
            int X, R; cin >> X >> R;
            F[X] = R;
            t.insert({R, X});
            cnt++;
        }else if(c=='M'){
            int X, R; cin >> X >> R;
            t.erase({F[X], X});
            F[X] = R;
            t.insert({R, X});
        }else if(c=='Q'){
            int K; cin >> K;
            int Q = t.find_by_order(cnt-K)->s;
            cout << Q << nl;
        }
    }
    return 0;
}