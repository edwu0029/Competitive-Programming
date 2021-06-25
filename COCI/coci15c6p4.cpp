//Problem: https://dmoj.ca/problem/coci15c6p4

#include <bits/stdc++.h>
using namespace std;
int N, dp[1<<20], mod = 1e9;
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
            dp[curr] = (dp[curr]+dp[pre])%mod;
        }
    }
    cout << dp[(1<<N)-1] << '\n';
    return 0;
}