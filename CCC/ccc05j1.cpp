//Problem: https://dmoj.ca/problem/ccc05j1

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
int a, b, c;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> a >> b >> c;
    int planA = 0;
    if(a>100) planA+=(a-100)*25;
    planA+=15*b;
    planA+=20*c;
    cout << fixed << setprecision(2) << "Plan A costs " << planA/100.0 << nl;
    int planB = 0;
    if(a>250) planB+=(a-250)*45;
    planB+=35*b;
    planB+=25*c;
    cout << "Plan B costs " << planB/100.0 << nl;
    if(planA<planB) cout << "Plan A is cheapest." << nl;
    else if(planA>planB) cout << "Plan B is cheapest." << nl;
    else cout << "Plan A and B are the same price." << nl;
    return 0;
}