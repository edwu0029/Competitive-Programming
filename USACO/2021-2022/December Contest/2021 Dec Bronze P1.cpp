/*
Lonely Photo
USACO 2021 December Contest, Bronze, Problem 1
http://usaco.org/index.php?page=viewproblem2&cpid=1155
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
int N;
string S;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> S;
    vector<int>diffG, diffH;
    int dG = 0, dH = 0;
    for(int i = 0;i<N;i++){
        if(S[i]=='G'){
            diffG.push_back(dG);
            dG = 0;
            dH++;
        }else{
            diffH.push_back(dH);
            dH = 0;
            dG++;
        }
    }
    diffG.push_back(dG);
    diffH.push_back(dH);
    ll ans = 0;
    for(int i = 1;i<diffG.size();i++){
        if(diffG[i-1]>=2) ans+=diffG[i-1]-1;
        if(diffG[i]>=2) ans+=diffG[i]-1;
        ans+=1LL*diffG[i-1]*diffG[i];
    }
    for(int i = 1;i<diffH.size();i++){
        if(diffH[i-1]>=2) ans+=diffH[i-1]-1;
        if(diffH[i]>=2) ans+=diffH[i]-1;
        ans+=1LL*diffH[i-1]*diffH[i];
    }
    cout << ans << nl;
    return 0;
}