//Problem: https://dmoj.ca/problem/dmopc15c2p4

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
const int MAXN = 1e5+5, LOG = 16;
struct anime{
    ll s, e, w;
};
bool cmpA(anime A, anime B){
    return A.e<B.e;
}
int N;
ll dp[MAXN];
anime F[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        ll R, L, H;
        cin >> R >> L >> H;
        F[i] = {R, R+L-1, H};
    }
    sort(F+1, F+1+N, cmpA);
    for(int i = 1, l, r, b;i<=N;i++){
        ll start = F[i].s, send = F[i].e, weight = F[i].w;
        l = 0; r = i;
        while(l<=r){
            int mid = (l+r)/2;
            if(F[mid].e<start){
                l = mid+1;
                b = mid;
            }else{
                r = mid-1;
            }
        }
        dp[i] = max(dp[i-1], dp[b]+weight);
    }
    cout << dp[N] << nl;
    return 0;
}