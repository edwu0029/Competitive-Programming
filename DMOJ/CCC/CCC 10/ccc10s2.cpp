/*
Huffman Encoding
Canadian Computing Competition: 2010 Stage 1, Senior #2
https://dmoj.ca/problem/ccc10s2
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
const int MAXN = 25;
int N;
string msg, ans;
pair<char, string>F[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> F[i].first >> F[i].second;
    }
    cin >> msg;
    int l = 0;
    for(int i = 0;i<msg.size();i++){
        string sub = "";
        for(int j = l;j<=i;j++) sub+=msg[j];
        for(int j = 0;j<N;j++){
            if(sub==F[j].second){
                ans+=F[j].first;
                l = i+1;
                break;
            }
        }
    }
    cout << ans << nl;
    return 0;
}