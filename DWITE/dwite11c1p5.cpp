//Problem: https://dmoj.ca/problem/dwite11c1p5

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
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for(int c = 0;c<5;c++){
        string str; cin >> str;
        int N = str.size(), dp[N][N]{};
        for(int i = 1;i<=N;i++){
            for(int j = 0, endi; j+i-1<N;j++){
                if(i==1){dp[j][j]=1; continue;}
                else if(i==2){
                    if(str[j]==str[j+1])dp[j][j+1]=2;
                    else dp[j][j+1]=1;
                    continue;
                }
                endi = j+i-1;
                if(str[j]==str[endi]){
                    dp[j][endi]=dp[j+1][endi-1]+2;
                }else {
                    dp[j][endi]=max(dp[j+1][endi], dp[j][endi-1]);
                }
            }
        }
        cout << dp[0][N-1] << '\n';
    }
    return 0;
}