//Problem: https://dmoj.ca/problem/ecoo21p3

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 2e5+5;
int N, M, K, q[MAXN], prof[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i = 1, a, b, c;i<=K;i++){
        cin >> a >> b >> c;
        if(c>q[b]){
            q[b] = c;
            prof[b] = a;
        }
    }
    for(int i = 1;i<=N;i++){
        if(prof[i]==0) cout << -1 << sp;
        else cout << prof[i] << sp;
    }
    cout << nl;
    return 0;
}