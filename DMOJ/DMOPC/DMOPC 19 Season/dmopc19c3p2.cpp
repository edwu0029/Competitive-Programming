//Prolbem: https://dmoj.ca/problem/dmopc19c3p2

#include <bits/stdc++.h>
using namespace std;
int N,K, cnt[26], t;
long long fact[16], fact2 = 1, ans;
string s;
long long calc(){
    long long tmp = 1;
    for(int i = 0;i<26;i++){
        tmp = tmp*fact[cnt[i]];
    }
    return fact[N]/tmp;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K >> s;
    for(int i = 0;i<N;i++){
        if(s[i]!='*'){
            cnt[s[i]-'a']++;
        }else{
            t++;
        }
    }
    fact[0]=1;
    fact[1]=1;
    for(int i = 2;i<=15;i++){
        fact[i]=fact[i-1]*i;
    }
    if(t==1){
        for(int i = 0;i<26;i++){
            cnt[i]++;
            ans+=calc();
            cnt[i]--;
        }
    }else if(t==2){
        for(int i = 0;i<26;i++){
            cnt[i]++;
            for(int j = i;j<26;j++){
                cnt[j]++;
                ans+=calc();
                cnt[j]--;
            }
            cnt[i]--;
        }
    }else{
        ans = calc();
    }
    cout << ans << '\n';
    return 0;
}