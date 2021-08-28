//Problem: https://dmoj.ca/problem/ccc06s1

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
int N;
bool mother[2][5], father[2][5];
int check(char l){
    if('a'<=l&&l<='z') return 0;
    else return 1;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    string m, f;
    cin >> m >> f;
    for(int i = 0;i<m.size();i+=2){
        mother[check(m[i])][i/2] = mother[check(m[i+1])][i/2] = true;
    }
    for(int i = 0;i<f.size();i+=2){
        father[check(f[i])][i/2] = father[check(f[i+1])][i/2] = true;
    }
    cin >> N;
    for(int i = 0;i<N;i++){
        string b; cin >> b;
        bool ans = true;
        for(int j = 0;j<b.size();j++){
            int t = check(b[j]);
            if(t==0&&(!mother[t][j]||!father[t][j])){
                ans = false;
                break;
            }else if(t==1&&(!mother[t][j]&&!father[t][j])){
                ans = false;
                break;
            }
        }
        if(ans) cout << "Possible baby." << nl;
        else cout << "Not their baby!" << nl;
    }
    return 0;
}