//Problem: https://dmoj.ca/problem/ccc15s2

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
int J, A;
int jerseys[MAXN];
int getsize(char sz){
    if(sz=='S') return 0;
    else if(sz=='M') return 1;
    return 2;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> J >> A;
    for(int i = 1;i<=J;i++){
        char sz; cin >> sz;
        jerseys[i] = getsize(sz);
    }
    int ans = 0;
    for(int i = 0;i<A;i++){
        char sz; int n;
        cin >> sz >> n;
        if(jerseys[n]!=-1 && jerseys[n]>=getsize(sz)){
            jerseys[n] = -1;
            ans++;
        }
    }
    cout << ans << nl;
    return 0;
}