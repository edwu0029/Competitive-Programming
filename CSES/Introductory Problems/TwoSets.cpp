//Problem: https://cses.fi/problemset/task/1092

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
ll N;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    ll sum = N*(N+1)/2;
    if(sum%2==1){
        cout << "NO" << nl;
        return 0;
    }
    ll half = sum/2;
    vector<int>h1, h2;
    for(int i = N;i>=1;i--){
        if(half>=i){
            half-=i;
            h1.push_back(i);
        }else{
            h2.push_back(i);
        }
    }
    if(half!=0){
        cout << "NO" << nl;
        return 0;
    }
    cout << "YES" << nl;
    cout << h1.size() << nl;
    for(int i:h1){
        cout << i << sp;
    }
    cout << nl;
    cout << h2.size() << nl;
    for(int i:h2){
        cout << i << sp;
    }
    cout << nl;
    return 0;
}