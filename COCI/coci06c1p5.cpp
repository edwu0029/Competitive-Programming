//Problem: https://dmoj.ca/problem/coci06c1p5

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
int N;
double F[21][21], dp[1<<21];
int main(){
    scanf("%d", &N);
    for(int i = 0;i<N;i++){
        for(int j  = 0;j<N;j++){
            scanf("%lf", &F[i][j]);
            F[i][j]*=0.01;
        }
    }
    dp[0]=1.0;
    for(int bitmask = 0;bitmask<(1<<N);bitmask++){
        for(int i = 0;i<N;i++){
            if(!(bitmask&(1<<i))){
                int newbitmask = bitmask|(1<<i);
                dp[newbitmask]=max(dp[newbitmask], dp[bitmask]*F[__builtin_popcount(bitmask)][i]);
            }
        }
    }
    printf("%.6f\n", dp[(1<<N)-1]*100);
    return 0;
}