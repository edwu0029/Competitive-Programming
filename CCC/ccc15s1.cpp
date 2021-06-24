//Problem: https://dmoj.ca/problem/ccc15s1

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
int K;
deque<int>dq;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K;
    for(int i = 0, x;i<K;i++){
        cin >> x;
        if(x==0) dq.pop_back();
        else dq.pb(x);
    }
    int sum = 0;
    while(!dq.empty()){
        sum+=dq.front();
        dq.pop_front();
    }
    cout << sum << nl;
    return 0;
}