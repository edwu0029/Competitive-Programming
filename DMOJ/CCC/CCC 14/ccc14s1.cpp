/*
Party Invitation
Canadian Computing Competition: 2014 Stage 1, Junior #4, Senior #1
https://dmoj.ca/problem/ccc14s1
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
int K, M;
vector<int>ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K >> M;
    for(int i = 1;i<=K;i++) ans.push_back(i);
    for(int i = 0, x;i<M;i++){
        cin >> x;
        vector<int>n;
        for(int j = 0;j<ans.size();j++){
            if((j+1)%x!=0){
                n.push_back(ans[j]);
            }
        }
        ans = n;
    }
    for(int i:ans){
        cout << i << nl;
    }
    return 0;
}