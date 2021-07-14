//Problem: https://dmoj.ca/problem/ccc20s3

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
const ll MOD1 = 1e9+7, MOD2 = 1e9+9;
const ll MODll = 4000004479;
const int MAXN = 2e5+5, LOG = 16;
string A, B;
int freqA[26], freqB[MAXN][26];
ll po1[MAXN], po2[MAXN], hshA1[MAXN], hshA2[MAXN], hshB1[MAXN], hshB2[MAXN];
set<pair<ll, ll>>ans;
ll gethsh(ll hsh[], ll po[], int l, int r, ll MOD){
    return (hsh[r]-((po[r-l+1]*hsh[l-1])%MOD)+MOD)%MOD;
}
bool check(int l, int r){
    for(int i = 0;i<26;i++){
        int t = freqB[r][i]-freqB[l-1][i];
        if(freqA[i]!=t) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> A >> B;
    int N = A.size(), M = B.size();
    ll seed1 = 131, seed2 = 139;
    po1[0] = po2[0] = 1;
    for(int i = 1;i<=N;i++){
        po1[i] = (po1[i-1]*seed1)%MOD1;
        po2[i] = (po2[i-1]*seed2)%MOD2;
    }
    for(int i = 1;i<=N;i++) freqA[A[i-1]-'a']++;
    for(int i = 1;i<=M;i++){
        for(int j = 0;j<26;j++) freqB[i][j]+=freqB[i-1][j];
        freqB[i][B[i-1]-'a']++;
        hshB1[i] = ((hshB1[i-1]*seed1)%MOD1+1LL*B[i-1])%MOD1;
        hshB2[i] = ((hshB2[i-1]*seed2)%MOD2+1LL*B[i-1])%MOD2;
    }
    for(int i = N;i<=M;i++){
        if(!check(i-N+1, i)) continue;
        ll hsh1 = gethsh(hshB1, po1, i-N+1, i, MOD1);
        ll hsh2 = gethsh(hshB2, po2, i-N+1, i, MOD2);
        ans.insert(mp(hsh1, hsh2));
    }
    cout << ans.size() << nl;
    return 0;
}