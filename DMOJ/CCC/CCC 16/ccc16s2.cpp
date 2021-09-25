/*
Tandem Bicycle
Canadian Computing Competition: 2016 Stage 1, Junior #5, Senior #2
https://dmoj.ca/problem/ccc16s2
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
const int MAXN = 1005;
int N, a, F[101], F2[101], ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> a >> N;
    for(int i = 0;i<N;i++)cin >> F[i];
    for(int i = 0;i<N;i++)cin >> F2[i];
    sort(F, F+N); sort(F2, F2+N);
    if(a==2)
        for(int i = 0;i<N;i++) ans+=max(F[i], F2[N-1-i]);
    else
        for(int i = 0;i<N;i++) ans+=max(F[i], F2[i]);
    cout << ans << nl;
    return 0;
}