//Problem: https://dmoj.ca/problem/ccc20s4

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
const int MAXN = 1005, LOG = 16;
string N;
int Nlen, A[MAXN], B[MAXN], C[MAXN], At, Bt, Ct, ans;
int q(int*z, int l, int r){
    return z[r]-z[l-1];
}
int check(int*x, int *y, int xt, int yt, int i){
    return (xt-q(x, i, i+xt-1))+(yt-q(y, i+xt, i+xt+yt-1))-min(q(y, i, i+xt-1), q(x, i+xt, i+xt+yt-1));
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >>  N; Nlen = ans = N.length();
    for(int i = 1;i<=Nlen;i++){
        if(N[i-1]=='A') A[i]++;
        else if(N[i-1]=='B') B[i]++;
        else if(N[i-1]=='C') C[i]++;
        A[i]+=A[i-1]; B[i]+=B[i-1]; C[i]+=C[i-1];
    }
    At = A[Nlen]; Bt = B[Nlen]; Ct = C[Nlen];
    for(int i = 1;i<=Nlen;i++){
        if(i+At+Bt-1<=Nlen){
            //A, B, C
            ans = min(ans, check(A, B, At, Bt, i));
            //B, A, C
            ans = min(ans, check(B, A, Bt, At, i));
        }
        if(i+Bt+Ct-1<=Nlen){
            //B, C, A
            ans = min(ans, check(B, C, Bt, Ct, i));
            //C, B, A
            ans = min(ans, check(C, B, Ct, Bt, i));
        }
        if(i+At+Ct<=Nlen){
            //A, C, B
            ans = min(ans, check(A, C, At, Ct, i));
            //C, A, B
            ans = min(ans, check(C, A, Ct, At, i));
        }
    }
    cout << ans << '\n';
    return 0;
}