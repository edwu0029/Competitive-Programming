/*
Cow Gymnastics
USACO 2019 December Contest, Bronze, Problem 1
http://usaco.org/index.php?page=viewproblem2&cpid=963
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
int K, N, ranking[15][25], ans;
int main(){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K >> N;
    for(int i = 1;i<=K;i++){
        for(int j = 1, x;j<=N;j++){
            cin >> x;
            ranking[i][x] = j;
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if(i==j) continue;
            bool f = true;
            for(int k = 1;k<=K;k++){
                if(ranking[k][i]>ranking[k][j]) f = false;
            }
            if(f) ans++;
        }
    }
    cout << ans << nl;
    return 0;
}