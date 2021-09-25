/*
Nukit
Canadian Computing Competition: 2008 Stage 1, Senior #5
https://dmoj.ca/problem/ccc08s5
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
int N, A, B, C, D;
bool dp[31][31][31][31][2], done[31][31][31][31][2];
int reactions[5][4] = {{-2, -1, 0, -2},
                       {-1, -1, -1, -1},
                       {0, 0, -2, -1},
                       {0, -3, 0, 0},
                       {-1, 0, 0, -1}};
void rec(int a, int b, int c, int d, int turn){
    if(done[a][b][c][d][turn]) return;
    bool can_move = false, possible_win = false;
    for(int i = 0;i<5;i++){
        int na = reactions[i][0]+a;
        int nb = reactions[i][1]+b;
        int nc = reactions[i][2]+c;
        int nd = reactions[i][3]+d;
        if(na>=0&&nb>=0&&nc>=0&&nd>=0){
            can_move = true;
            rec(na, nb, nc, nd, turn^1);
            if(!dp[na][nb][nc][nd][turn^1]){
                possible_win = true;
            }
        }
    }
    done[a][b][c][d][turn] = true;
    if(!can_move||!possible_win){
        dp[a][b][c][d][turn] = false;
    }else{
        dp[a][b][c][d][turn] = true;
    }
}
void solve(){
    memset(dp, 0, sizeof(dp));
    memset(done, 0, sizeof(done));
    cin >> A >> B >> C >> D;
    rec(A, B, C, D, 0);
    if(dp[A][B][C][D][0]){
        cout << "Patrick" << nl;
    }else{
        cout << "Roland" << nl;
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    while(N--){
        solve();
    }
    return 0;
}