/*
Money Sums
https://cses.fi/problemset/task/1745
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
const int MAXN = 1e5+5;
int N, cnt, sum;
bool dp[MAXN];
set<int>ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    dp[0] = true;
    for(int i = 0, x;i<N;i++){
        cin >> x;
        sum+=x;
        for(int j = sum;j>=x;j--){
            if(dp[j-x]){
                dp[j] = true;
                ans.insert(j);
            }
        }
    }
    cout << ans.size() << nl;
    for(int i:ans) cout << i << sp;
    cout << nl;
    return 0;
}