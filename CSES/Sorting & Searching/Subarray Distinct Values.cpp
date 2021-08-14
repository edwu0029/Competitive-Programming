//Problem: https://cses.fi/problemset/task/2428

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 2e5+5;
int N, K, x[MAXN], cnt;
ll ans;
map<int, int>m;
void add(int v){
    if(!m[v]) cnt++;
    m[v]++;
}
void del(int v){
    if(m[v]==1) cnt--;
    m[v]--;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 1;i<=N;i++) cin >> x[i];
    int l = 1, r = 1;
    m[x[1]] = cnt = 1;
    while(l<=r&&r<=N){
        if(cnt>K){
            do{
                del(x[l++]);
            }while(cnt>K&&l<=r&&l<=N);
        }else{
            //Add subarrays that end at index r
            ans+=r-l+1;
            if(r<N) add(x[++r]);
            else break;
        }
    }
    cout << ans << nl;
    return 0;
}