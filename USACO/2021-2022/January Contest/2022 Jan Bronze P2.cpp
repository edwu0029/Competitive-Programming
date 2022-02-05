/*
Non-Transitive Dice
USACO 2022 January Contest, Bronze, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=1180
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
void solve(){
    vector<int>diceA(4), diceB(4);
    for(int i = 0;i<4;i++) cin >> diceA[i];
    for(int i = 0;i<4;i++) cin >> diceB[i];
    int ca = 0, cb = 0;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(diceA[i]>diceB[j]) ca++;
            if(diceB[i]>diceA[j]) cb++;
        }
    }
    if(ca==cb){
        cout << "no" << nl;
        return;
    }
    for(int a = 1;a<=10;a++){
        for(int b = 1;b<=10;b++){
            for(int c = 1;c<=10;c++){
                for(int d = 1;d<=10;d++){
                    vector<int>diceC = {a, b, c, d};
                    int ca1 = 0, cc1 = 0, cb2 = 0, cc2 = 0;
                    for(int i = 0;i<4;i++){
                        for(int j = 0;j<4;j++){
                            if(diceA[i]>diceC[j]) ca1++;
                            if(diceC[i]>diceA[j]) cc1++;
                            if(diceB[i]>diceC[j]) cb2++;
                            if(diceC[i]>diceB[j]) cc2++;
                        }
                    }
                    if(ca>cb&&cc1>ca1&&cb2>cc2){
                        cout << "yes" << nl;
                        return;
                    }else if(ca<cb&&cb2<cc2&&cc1<ca1){
                        cout << "yes" << nl;
                        return;
                    }
                }
            }
        }
    }
    cout << "no" << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}