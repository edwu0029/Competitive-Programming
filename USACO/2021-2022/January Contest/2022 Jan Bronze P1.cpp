/*
Herdle
USACO 2022 January Contest, Bronze, Problem 1
http://usaco.org/index.php?page=viewproblem2&cpid=1179
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
int G, Y;
char good[3][3], guess[3][3];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    vector<int>f1(26), f2(26);
    for(int i = 0;i<3;i++){
        string t; cin >> t;
        for(int j = 0;j<3;j++){
            good[i][j] = t[j];
            f1[good[i][j]-'A']++;
        }
    }
    for(int i = 0;i<3;i++){
        string t; cin >> t;
        for(int j = 0;j<3;j++){
            guess[i][j] = t[j];
            if(guess[i][j]!=good[i][j]){
                f2[guess[i][j]-'A']++;
            }else{
                G++;
                f1[good[i][j]-'A']--;
            }
        }
    }
    for(int i = 0;i<26;i++){
        Y+=min(f1[i], f2[i]);
    }
    cout << G << nl << Y << nl;
    return 0;
}