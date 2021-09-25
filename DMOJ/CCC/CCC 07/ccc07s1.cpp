/*
Federal Voting Age
Canadian Computing Competition: 2007 Stage 1, Senior #1
https://dmoj.ca/problem/ccc07s1
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
int N;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, y, m, d;i<N;i++){
        cin >> y >> m >> d;
        int yt = 2007-y-1;
        if(m<2||(m==2&&d<=27)) yt++;
        if(yt>=18) cout << "Yes" << nl;
        else cout << "No" << nl;
    }
    return 0;
}