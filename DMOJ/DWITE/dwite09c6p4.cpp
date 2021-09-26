/*
Time for Change
DWITE Online Computer Programming Contest, April 2010, Problem 4
https://dmoj.ca/problem/dwite09c6p4
*/

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
int m, n, c, coins[10], dp[101];
int main(){
    for(int g = 0;g<5;g++){
        scanf("%d%d", &m, &n);
        for(int i = 0;i<n;i++){
            scanf("%d", &coins[i]);
        }
        memset(dp, 0x3f3f3f, sizeof(dp));
        dp[0]=0;
        sort(coins, coins+n);
        for(int i = 0;i<101;i++){
            for(int j = 0;j<n;j++){
                if(i+coins[j]<101){
                    dp[i+coins[j]] = min(dp[i]+1, dp[i+coins[j]]);
                }
            }
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}