/*
It's tough being a teen!
Canadian Computing Competition: 2006 Stage 1, Junior #4
https://dmoj.ca/problem/ccc06j4
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
int in[8] = {0, 1, 0, 0, 2, 1, 0, 1};
bool vis[8], done[8];
vector<int>adj[8], ord;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    adj[1].push_back(7);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[3].push_back(5);
    adj[3].push_back(4);
    while(true){
        int x, y; cin >> x >> y;
        if(x==0&&y==0) break;
        adj[x].push_back(y);
        in[y]++;
    }
    for(int i = 0;i<=7;i++){
        for(int j = 1;j<=7;j++){
            if(!done[j]&&in[j]==0){
                ord.push_back(j);
                done[j] = true;
                for(int k:adj[j]) in[k]--;
                break;
            }
        }
    }
    if(ord.size()!=7){
        cout << "Cannot complete these tasks. Going to bed." << nl;
        return 0;
    }
    for(int i:ord) cout << i << sp;
    return 0;
}