/*
Geese vs. Hawks
Canadian Computing Olympiad: 2018 Day 1, Problem 1
https://dmoj.ca/problem/cco18p1
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
const int MAXN = 1005, LOG = 16;
int N, G[MAXN], H[MAXN];
string geese, hawks;
long long dp[MAXN][MAXN];
int check(int i, int j){
    if(geese[i-1]!=hawks[j-1]){
        if(G[i]>H[j]&&geese[i-1]=='W')return G[i]+H[j];
        else if(H[j]>G[i]&&hawks[j-1]=='W')return G[i]+H[j];
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    cin >> geese; for(int i = 1;i<=N;i++)cin >> G[i];
    cin >> hawks; for(int i = 1;i<=N;i++)cin >> H[i];
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            dp[i][j]=max(dp[i-1][j-1]+check(i, j), max(dp[i-1][j], dp[i][j-1]));
        }
    }
    cout << dp[N][N] << '\n';
}