/*
Pizza Bag
DMPG '16 S5
https://dmoj.ca/problem/dmpg16s5
*/

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 1e5+5, LOG = 16;
int N, K;
ll F[MAXN], psa[MAXN], ans = -(0x3f3f3f3f);
ll sparse[65][MAXN];
ll query(int l, int r){
    int len = r-l+1, lpo = 0;
    for(int i = 0;i<31;i++)if((1<<i)&len)lpo = i;
    return max(sparse[lpo][l], sparse[lpo][r-(1<<lpo)+1]);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N  >> K;
    for(int i = 1;i<=N;i++){ cin >> F[i]; psa[i]=psa[i-1]+F[i];}
    for(int i = 0;i<31;i++){
        for(int j = 1;j+(1<<i)-1<=N;j++){
            if(i==0)sparse[i][j]=psa[j];
            else sparse[i][j]=max(sparse[i-1][j], sparse[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i = 1, j;i<=N;i++){
        ll cur = 0; j = i+K-1;
        if(i+1>N){
            cur = query(1, j%N)+F[i];
        }else if(j<=N){
            cur = query(i, j)-psa[i-1];
        }else{
            cur = max(query(i, N)-psa[i-1], psa[N]-psa[i-1]+query(1, j%N));
        }
        ans = max(ans, cur);
    }
    cout << ans << nl;
    return 0;
}