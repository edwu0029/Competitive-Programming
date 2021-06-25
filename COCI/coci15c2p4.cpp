//Problem: https://dmoj.ca/problem/coci15c2p4

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, ans, mod = 1e9;
map<ll, int>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        string s; cin >> s;
        ll pre = 0, suf = 0;
        int best = 0;
        for(int j = 0;j<s.length();j++){
            pre = pre*131+s[j];
            suf = suf*131+s[s.length()-j-1];
            if(pre==suf)best = max(best, m[pre*mod+suf]);
        }
        ans = max(ans, best+1);
        m[pre*mod+suf]=best+1;
    }
    cout << ans << '\n';
    return 0;
}