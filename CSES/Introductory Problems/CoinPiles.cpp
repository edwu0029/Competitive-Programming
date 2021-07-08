//Problem: https://cses.fi/problemset/task/1754/

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
int T, a, b;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
    while(T--){
        cin >> a >> b;
        if((a+b)%3||a>2*b||b>2*a){
            cout << "NO" << nl;
        }else{
            cout << "YES" << nl;
        }
    }
    return 0;
}