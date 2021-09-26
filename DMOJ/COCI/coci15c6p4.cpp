/*
Parovi
COCI '15 Contest 6 #4
https://dmoj.ca/problem/coci15c6p4
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
int N, dp[1<<20];
vector<pair<int, int>>v;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        for(int j = i+1;j<=N;j++){
            if(__gcd(i, j)==1){v.push_back(make_pair(i-1, j-1));}
        }
    }
    dp[0]=1; N--;
    for(pair<int, int>cur : v){
        for(int pre = (1<<N)-1;pre>=0;pre--){
            int mask = ((1<<cur.second)-1)-((1<<cur.first)-1), curr = mask|pre;
            dp[curr] = (dp[curr]+dp[pre])%MOD;
        }
    }
    cout << dp[(1<<N)-1] << '\n';
    return 0;
}