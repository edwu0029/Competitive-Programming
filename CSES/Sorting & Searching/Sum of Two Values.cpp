/*
Sum of Two Values
https://cses.fi/problemset/task/1640/
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
const int MAXN = 2e5+5;
int N, X;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> X;
    vector<pii>a(N);
    for(int i = 0;i<N;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for(int i = 0;i<N;i++){
        int v = X-a[i].first;
        auto p = lower_bound(a.begin(), a.end(), mp(v, 0));
        if(p==a.end()) continue;
        int pos = p-a.begin();
        if(a[pos].first==v&&a[pos].second!=a[i].second){
            cout << a[i].second+1 << sp << a[pos].second+1 << nl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << nl;
    return 0;
}