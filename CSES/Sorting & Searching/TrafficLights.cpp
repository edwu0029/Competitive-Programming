//Problem: https://cses.fi/problemset/task/1163/

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
multiset<int>s, dis;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> X >> N;
    s.insert(0);
    s.insert(X);
    dis.insert(X);
    for(int i = 0, p;i<N;i++){
        cin >> p;
        int prev = *(--s.lower_bound(p)), nxt = *s.upper_bound(p);
        dis.erase(dis.find(nxt-prev));
        dis.insert(nxt-p);
        dis.insert(p-prev);
        s.insert(p);
        cout << *(--dis.end()) << sp;
    }
    return 0;
}