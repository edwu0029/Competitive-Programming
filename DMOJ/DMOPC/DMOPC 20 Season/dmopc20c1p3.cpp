/*
Victor's Algorithm
DMOPC '20 Contest 1 P3
https://dmoj.ca/problem/dmopc20c1p3
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
#include <stack>
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
const int MAXN = 1e6+5;
int N, F[MAXN], mxx=-(1e9-10), idx;
ll ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> F[i];
        if(F[i]>mxx){
            mxx = F[i]; idx = i;
        }
    }
    int curmax = F[1];
    for(int i = 1;i<idx;i++){
        if(F[i]>=curmax){curmax = F[i];}
        else{
            ans+=(1LL)*(curmax-F[i]);
        }
    }
    curmax = F[N];
    for(int i = N;i>idx;i--){
        if(F[i]>=curmax){curmax = F[i];}
        else{
            ans+=(1LL)*(curmax-F[i]);
        }
    }
    cout << ans << nl;
    return 0;
}