/*
No Time to Paint
USACO 2021 January Contest, Silver, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=1087
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
const int MAXN = 1e5+5;
int N, Q, F[MAXN], ansl[MAXN], ansr[MAXN], lasto[102];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    string s; cin >> s;
    for(int i = 0;i<=N;i++) F[i] = s[i-1];
    int pre = F[1];
    ansl[1] = 1;
    for(int i = 1;i<102;i++) lasto[i] = -1;
    lasto[F[1]] = ansl[1] = 1;
    for(int i = 2;i<=N;i++){
        ansl[i]+=ansl[i-1];
        int cur = F[i];
        if(cur>pre){
            ansl[i]++;
            lasto[cur] = i;
        }else if(cur==pre){
            pre = cur;
        }else if(cur<pre){
            for(int j = cur+1;j<='Z';j++) lasto[j] = -1;
            if(lasto[cur]==-1){
                ansl[i]++;
                lasto[cur] = i;
            }else{
                pre = cur;
            }
        }
        pre = cur;
    }
    for(int i = 1;i<102;i++) lasto[i] = -1;
    pre = F[N];
    ansr[N] = lasto[F[N]] = 1;
    for(int i = N-1;i>=1;i--){
        ansr[i]+=ansr[i+1];
        int cur = F[i];
        if(cur>pre){
            ansr[i]++; lasto[cur] = i;
        }else if(cur==pre){
            pre = cur;
        }else if(cur<pre){
            for(int j = cur+1;j<='Z';j++) lasto[j] = -1;
            if(lasto[cur]==-1){
                ansr[i]++;
                lasto[cur] = i;
            }else{
                pre = cur;
            }
        }
        pre = cur;
    }
    for(int i = 0, a, b;i<Q;i++){
        cin >> a >> b;
        cout << ansl[a-1]+ansr[b+1] << nl;
    }
    return 0;
}