//Problem: https://dmoj.ca/problem/dwite11c1p2

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
int N, sum, ans;
int main(){
    for(int i = 0;i<5;i++){
        scanf("%d",&N); int F[N]; ans = sum = 0;
        for(int i = 0;i<N;i++){
            scanf("%d",&F[i]); sum+=F[i];
        }
        sum/=N;
        for(int i = 0;i<N;i++){if(F[i]>sum)ans+=(F[i]-sum);}
        printf("%d\n",ans);
    }
}