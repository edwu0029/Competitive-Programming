/*
Photoshoot 2
USACO 2022 February Contest, Bronze, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=1204
*/

#include <bits/stdc++.h>
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
const int MAXN = 1e5+5;
int N, A[MAXN], B[MAXN];
map<int, int>pos;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> A[i];
    for(int i = 1;i<=N;i++){
        cin >> B[i];
        pos[B[i]] = i;
    }
    int maxp = 0, ans = 0;
    for(int i = 1;i<=N;i++){
        if(pos[A[i]]<maxp) ans++;
        maxp = max(maxp, pos[A[i]]);
    }
    cout << ans << nl;
    return 0;
}