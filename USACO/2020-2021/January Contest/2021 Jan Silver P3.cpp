/*
Spaced Out
USACO 2021 January Contest, Silver, Problem 3
http://usaco.org/index.php?page=viewproblem2&cpid=1088
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
const int MAXN = 1005;
int N, F[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            cin >> F[i][j];
        }
    }
    int cnt1 = 0;
    for(int i = 1;i<=N;i++){
        int c1 = 0, c2 = 0;
        for(int j = 1;j<=N;j++){
            if(j%2==0) c1+=F[i][j];
            else c2+=F[i][j];
        }
        cnt1+=max(c1, c2);
    }
    int cnt2 = 0;
    for(int i = 1;i<=N;i++){
        int c1 = 0, c2 = 0;
        for(int j = 1;j<=N;j++){
            if(j%2==0) c1+=F[j][i];
            else c2+=F[j][i];
        }
        cnt2+=max(c1, c2);
    }
    cout << max(cnt1, cnt2) << nl;
    return 0;
}