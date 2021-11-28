/*
Comfortable Cows
USACO 2021 February Contest, Bronze, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=1108
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
int N, cnt;
vector<pii>adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool F[1005][1005];
bool check_bounds(int x, int y){
    return 0<=x&&x<1005&&0<=y&&y<1005;
}
int count(int x, int y){
    if(!F[x][y]) return 0;
    int res = 0;
    for(auto [dx, dy]: adj){
        if(!check_bounds(x+dx, y+dy)) continue;
        if(F[x+dx][y+dy]) res++;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, x, y;i<N;i++){
        cin >> x >> y;
        for(auto [dx, dy]: adj){
            if(!check_bounds(x+dx, y+dy)) continue;
            if(count(x+dx, y+dy)==3) cnt--;
        }
        F[x][y] = true;
        if(count(x, y)==3) cnt++;
        for(auto [dx, dy]: adj){
            if(!check_bounds(x+dx, y+dy)) continue;
            if(count(x+dx, y+dy)==3) cnt++;
        }
        cout << cnt << nl;
    }
    return 0;
}