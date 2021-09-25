/*
Gates
Canadian Computing Competition: 2015 Stage 1, Senior #3
https://dmoj.ca/problem/ccc15s3
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
const int MAXN = 1e6+5;
int G, P, ans;
bool all = true;
set<int>gates;
int main(){
    scanf("%d%d", &G, &P);
    for(int i = -1;i>=-G;i--) gates.insert(i);
    for(int i = 0, g; i<P;i++){
        scanf("%d", &g);
        auto tmp = gates.lower_bound(-g);
        if(tmp==gates.end()){
            ans = i; all = false;
            break;
        }
        gates.erase(tmp);
    }
    if(!ans) printf("%d\n", P);
    else printf("%d\n", ans);
    return 0;
}