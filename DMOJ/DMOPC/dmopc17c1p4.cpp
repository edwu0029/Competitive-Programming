//Problem: https://dmoj.ca/problem/dmopc17c1p4

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
int N, H, pre = 0, cur = 1;
ll dp[5005][2];
int main(){
    scanf("%d%d", &N, &H);
    for(int i = 0, g, h, q, t;i<N;i++){
        scanf("%d%d%d%d", &g, &h, &q, &t);
        for(int j = 0;j<=H;j++) dp[j][cur]=0;
        for(int j = h;j<=H;j++) dp[j][cur]=dp[j-h][pre]+g;
        for(int j = h+t;j<=H;j++) dp[j][cur]=max(dp[j][cur], dp[j-t][cur]+q);
        for(int j = 0;j<=H;j++) dp[j][cur]=max(dp[j][cur], dp[j][pre]);
        swap(pre, cur);
    }
    printf("%lld\n", dp[H][pre]);
    return 0;
}