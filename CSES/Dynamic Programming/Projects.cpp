/*
Projects
https://cses.fi/problemset/task/1140
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
const int MAXN = 4e5+5;
int N, a[MAXN], b[MAXN], rewards[MAXN];
vector<pii>projects[MAXN];
ll dp[MAXN];
map<int, int>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    vector<int>times;
    for(int i = 1;i<=N;i++){
        cin >> a[i] >> b[i] >> rewards[i];
        times.push_back(a[i]);
        times.push_back(b[i]);
    }
    sort(times.begin(), times.end());
    for(int i = 1;i<=times.size();i++) m[times[i-1]] = i;
    for(int i = 1;i<=N;i++){
        projects[m[b[i]]].push_back(mp(a[i], rewards[i]));
    }
    for(int i = 1;i<=times.size();i++){
        int t = times[i-1];
        dp[i] = dp[i-1];
        for(auto [st, r]:projects[i]){
            dp[i] = max(dp[i], dp[m[st]-1]+r);
        }
    }
    cout << dp[times.size()] << nl;
    return 0;
}