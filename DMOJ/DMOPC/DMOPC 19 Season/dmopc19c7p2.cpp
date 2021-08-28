//Problem: https://dmoj.ca/problem/dmopc19c7p2

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INFI = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1e6+2;
int N, F[MAXN], tmp[MAXN], sum;
bool check(){
    for(int i = 0;i<N;i++)tmp[i] = F[i];
    for(int i = 0;i<N-1;i++){
        tmp[i+1]-=tmp[i];
        tmp[i] = 0;
        if(tmp[i+1]<0)return false;
    }
    return tmp[N-1]==0;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> F[i]; sum+=F[i];
    }
    for(int i = 0;i<=min(F[0], F[N-1]);i++){
        F[0]-=i; F[N-1]-=i;
        if(check()){
            cout << "YES" << nl;
            cout << sum/2 << nl;
            for(int j = 1;j<=i;j++)cout << 0 << " " << N-1 << '\n';
            for(int j = 0;j<N-1;j++){
                for(int k = 1;k<=F[j];k++)cout << j << " " << j+1 << nl;
                F[j+1]-=F[j];
                F[j] = 0;
            }
            return 0;
        }
        F[0]+=i; F[N-1]+=i;
    }
    cout << "NO" << nl;
    return 0;
}