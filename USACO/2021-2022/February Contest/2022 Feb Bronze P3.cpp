/*
Blocks
USACO 2022 February Contest, Bronze, Problem 3
http://usaco.org/index.php?page=viewproblem2&cpid=1205
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
const int MAXN = 15;
int N;
map<char, bool>blocks[4];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<4;i++){
        string s; cin >> s;
        for(int j = 0;j<s.size();j++) blocks[i][s[j]] = true;
    }
    for(int i = 0;i<N;i++){
        string s; cin >> s;
        bool c = false;
        vector<int>t = {0, 1, 2, 3};
        do{
            bool check = true;
            for(int j = 0;j<s.size();j++){
                if(!blocks[t[j]][s[j]]){
                    check = false;
                    break;
                }
            }
            if(check){
                c = true;
                break;
            }
        }while(next_permutation(t.begin(), t.end()));
        if(c) cout << "YES" << nl;
        else cout << "NO" << nl;
    }
    return 0;
}