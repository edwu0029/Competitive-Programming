//Problem: https://cses.fi/problemset/task/1084/

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
int N, M, K, a[MAXN], b[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i = 0, x;i<N;i++){
        cin >> a[i];
    }
    for(int i = 0, x;i<M;i++){
        cin >> b[i];
    }
    sort(a, a+N);
    sort(b, b+M);
    int point = 0, ans = 0;
    for(int i = 0;i<N&&point<M;i++){
        while(b[point]<a[i]-K&&point<M){
            point++;
        }
        if(point>=M) break;
        if(a[i]-K<=b[point]&&b[point]<=a[i]+K){
            ans++;
            point++;
        }
    }
    cout << ans << nl;
    return 0;
}