//Problem: https://dmoj.ca/problem/ecoo20p2

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
#include <stack>
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
const int MM = 1e4+2;
void solve(){
    int N, K, tmp = 0, ans = 0;
    map<string, int>names;
    vector<pii>items[MM]{};
    cin >> N;
    for(int n = 1;n<=N;n++){
        int M; cin >> M;
        for(int m = 1, id;m<=M;m++){
            string name; int P, Q;
            cin >> name >> P >> Q;
            if(names[name]==0){
                names[name] = ++tmp;
            }
            id = names[name];
            items[id].push_back({P, Q});
        }
    }
    cin >> K;
    for(int k = 1, id;k<=K;k++){
        string name; int Q;
        cin >> name >> Q;
        id = names[name];
        sort(items[id].begin(), items[id].end());
        for(pii i:items[id]){
            if(i.second>=Q){
                ans+=(Q*i.first);
                break;
            }else{
                ans+=(i.second*i.first);
                Q-=(i.second);
            }
        }
    }
    cout << ans << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    for(int t = 1;t<=T;t++)
        solve();
    return 0;
}