//Problem: https://cses.fi/problemset/task/1662

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5+5;
int N, m[MAXN];
ll sum, ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    m[0]++;
    for(int i = 0, a;i<N;i++){
        cin >> a;
        sum+=a;
        int rem = ((sum%N)+N)%N;
        ans+=(m[rem]++);
    }
    cout << ans << nl;
    return 0;
}