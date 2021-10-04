/*
ABC Preparation
AtCoder Beginner Contest 185, Problem A
https://atcoder.jp/contests/abc185/tasks/abc185_a
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
int A, B, C, D;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> A >> B >> C >> D;
    cout << min(A, min(B, min(C, D))) << nl;
    return 0;
}