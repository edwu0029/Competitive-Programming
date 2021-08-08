//Problem: https://cses.fi/problemset/task/2216/

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
const int MAXN = 2e5+5;
int N, M, idx[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, x;i<N;i++){
        cin >> x;
        idx[x] = i;
    }
    int cnt = 0;
    idx[0] = inf;
    for(int i = 1;i<=N;i++){
        if(idx[i]<idx[i-1]) cnt++;
    }
    cout << cnt << nl;
    return 0;
}