/*
Multiple Choice
Canadian Computing Competition: 2011 Stage 1, Senior #2
https://dmoj.ca/problem/ccc11s2
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
int N;
char sol[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++) cin >> sol[i];
    int cnt = 0;
    for(int i = 0;i<N;i++){
        char c; cin >> c;
        if(c==sol[i]) cnt++;
    }
    cout << cnt << nl;
    return 0;
}