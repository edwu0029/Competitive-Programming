//Problem: https://cses.fi/problemset/task/2165/

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
const int MAXN = 20;
int N;
void solve(int n, int from, int to, int aux){
    if(n==1){
        cout << from << sp << to << nl;
        return;
    }
    solve(n-1, from, aux, to);
    cout << from << sp << to << nl;
    solve(n-1, aux, to, from);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    cout << (1<<N)-1 << nl;
    solve(N, 1, 3, 2);
    return 0;
}