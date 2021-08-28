//Problem: http://usaco.org/index.php?page=viewproblem2&cpid=989

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
int K, N;
void solve(){
    int X; cin >> X;
    int speed = 0, dis = 0, t = 0;
    for(;dis<K;t++){
        if(speed<X){
            speed++;
        }else if(speed==X){
            if(K-dis>X+1) speed++;
        }else{
            int desc = (speed-1+X)*(speed-X)/2-X;
            int rem = K-dis-desc;
            if(rem>2*speed+1){
                speed++;
            }else if(rem<=speed){
                speed--;
            }
        }
        dis+=speed;
    }
    cout << t << nl;
}
int main(){
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K >> N;
    for(int i = 0;i<N;i++){
        solve();
    }
    return 0;
}
