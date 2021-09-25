/*
Photoshoot
USACO 2020 January Contest, Bronze, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=988
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
const int MAXN = 1005;
int N, b[MAXN], freq[MAXN];
int main(){
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N-1;i++) cin >> b[i];
    for(int i = 1;i<=N;i++){
        memset(freq, 0, sizeof(freq));
        bool check = true;
        int cur = i;
        freq[cur]++;
        vector<int>v = {i};
        for(int j = 1;j<=N-1;j++){
            int nxt = b[j]-cur;
            if(1<=nxt&&nxt<=N&&freq[nxt]==0){
                freq[nxt]++;
                cur = nxt;
                v.push_back(cur);
            }else{
                check = false;
                break;
            }
        }
        if(check){
            for(int j = 0;j<N;j++){
                cout << v[j];
                if(j==N-1) cout << nl;
                else cout << sp;
            }
            break;
        }
    }
    return 0;
}