//Problem: https://dmoj.ca/problem/ccc08s4

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
int N, ans;
char ops[4] = {'+', '-', '*', '/'};
int combine(int a, int b, char op){
    if(op=='+'){
        return a+b;
    }else if(op=='-'){
        return a-b;
    }else if(op=='*'){
        return a*b;
    }else{
        if(b==0||a%b!=0) return -inf;
        return a/b;
    }
}
void rec(vector<int>F){
    if(F.size()==1){
        if(F[0]<=24) ans = max(ans, F[0]);
        return;
    }
    for(int i = 0;i<F.size();i++){
        for(int j = 0;j<F.size();j++){
            if(i==j) continue;
            for(int op = 0;op<4;op++){
                int v = combine(F[i], F[j], ops[op]);
                if(v==-inf) continue;
                vector<int>newF;
                for(int k = 0;k<F.size();k++){
                    if(k==i||k==j) continue;
                    newF.push_back(F[k]);
                }
                newF.push_back(v);
                rec(newF);
            }
        }
    }
}
void solve(){
    ans = -inf;
    vector<int>F;
    for(int i = 0, x;i<4;i++){
        cin >> x;
        F.push_back(x);
    }
    rec(F);
    cout << ans << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    while(N--){
        solve();
    }
    return 0;
}