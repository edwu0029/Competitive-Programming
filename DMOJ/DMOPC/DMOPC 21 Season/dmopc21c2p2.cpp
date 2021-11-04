/*
Partial Game
DMOPC '21 Contest 1 P1
https://dmoj.ca/problem/dmopc21c1p1
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
int N;
ll even, odd;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, x;i<N;i++){
        cin >> x;
        if(x%2==0) even+=1LL*x/2;
        else odd+=1LL*(x/2+1);
    }
    if(even>odd) cout << "Duke" << nl;
    else cout << "Alice" << nl;
    return 0;
}