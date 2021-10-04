/*
Smartphone Addiction
AtCoder Beginner Contest 185, Problem B
https://atcoder.jp/contests/abc185/tasks/abc185_b
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
int N, M, T, pre;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M >> T;
    int curb = N;
    for(int i = 0, a, b;i<M;i++){
        cin >> a >> b;
        curb-=(a-pre);
        if(curb<=0) break;
        curb = min(N, curb+b-a);
        pre = b;
    }
    if(curb>T-pre) cout << "Yes" << nl;
    else cout << "No" << nl;
    return 0;
}