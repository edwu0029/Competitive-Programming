/*
Rectangle Cutting
https://cses.fi/problemset/task/1744
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
int A, B, dp[505][505];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> A >> B;
    for(int i = 0;i<=A;i++){
        for(int j = 0;j<=B;j++){
            if(i==j) dp[i][j] = 0;
            else dp[i][j] = inf;
            for(int k = 1;k<i;k++){
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
            for(int k = 1;k<j;k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
        }
    }
    cout << dp[A][B] << nl;
    return 0;
}