//Problem: https://cses.fi/problemset/task/1091/

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
int N, M;
multiset<int>h;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, x;i<N;i++){
        cin >> x;
        h.insert(-x);
    }
    for(int j = 0, t;j<M;j++){
        cin >> t;
        auto p = h.lower_bound(-t);
        if(p==h.end()){
            cout << -1 << nl;
        }else{
            cout << -(*p) << nl;
            h.erase(p);
        }
    }
    return 0;
}