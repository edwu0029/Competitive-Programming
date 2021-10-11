/*
Failing Grade
AtCoder Beginner Contest 222, Problem B
https://atcoder.jp/contests/abc222/tasks/abc222_b
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
int N, P;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> P;
    int cnt = 0;
    for(int i = 0, x;i<N;i++){
        cin >> x;
        if(x<P) cnt++;
    }
    cout << cnt << nl;
    return 0;
}