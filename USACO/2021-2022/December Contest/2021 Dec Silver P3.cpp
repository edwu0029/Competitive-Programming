/*
Convoluted Intervals
USACO 2021 December Contest, Silver, Problem 3
http://usaco.org/index.php?page=viewproblem2&cpid=1160
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
int N, M;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    vector<pii>intervals(N);
    for(int i = 0;i<N;i++){
        cin >> intervals[i].first >> intervals[i].second;
    }
    vector<ll>st(2*M+5), ed(2*M+5);
    vector<int>freq_st(M+1);
    for(int i = 0;i<N;i++) freq_st[intervals[i].first]++;
    for(int i = 0;i<=M;i++){
        for(int j = 0;j<=M;j++){
            st[i+j]+=1LL*freq_st[i]*freq_st[j];
        }
    }
    vector<int>freq_ed(M+1);
    for(int i = 0;i<N;i++) freq_ed[intervals[i].second]++;
    for(int i = 0;i<=M;i++){
        for(int j = 0;j<=M;j++){
            ed[i+j]+=1LL*freq_ed[i]*freq_ed[j];
        }
    }
    ll ans = 0;
    for(int i = 0;i<=2*M;i++){
        ans+=st[i];
        cout << ans << nl;
        ans-=ed[i];
    }
    return 0;
}