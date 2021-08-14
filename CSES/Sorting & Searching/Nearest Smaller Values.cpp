//Problem: https://cses.fi/problemset/task/1645

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
int N;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    deque<pii>t;
    for(int i = 1, x;i<=N;i++){
        cin >> x;
        while(!t.empty()&&t.back().first>=x) t.pop_back();
        if(t.empty()) cout << 0 << sp;
        else cout << t.back().second << sp;
        t.push_back({x, i});
    }
    return 0;
}