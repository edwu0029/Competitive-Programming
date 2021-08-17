//Problem: http://usaco.org/index.php?page=viewproblem2&cpid=1061

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
int N, ans[55];
bool done[55];
vector<tuple<int, int, int>>h, v;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        char dir; int x, y;
        cin >> dir >> x >> y;
        if(dir=='E') h.push_back({x, y, i});
        else v.push_back({x, y, i});
    }
    //Sort verticals by x
    sort(v.begin(), v.end(), 
    [](tuple<int, int, int>a, tuple<int, int, int>b)->int{
        return get<0>(a)<get<0>(b);
    });
    //Sort horizontals by y
    sort(h.begin(), h.end(), 
    [](tuple<int, int, int>a, tuple<int, int, int>b)->int{
        return get<1>(a)<get<1>(b);
    });
    for(auto i:h){
        int xi = get<0>(i), yi = get<1>(i), a = get<2>(i);
        for(auto j:v){
            int xj = get<0>(j), yj = get<1>(j), b = get<2>(j);
            if(xi>xj||yi<yj) continue;
            int dx = xj-xi, dy = yi-yj;
            if(done[b]){
                if(dx>dy&&dy<=ans[b]){
                    done[a] = true;
                    ans[a] = dy;
                }
            }else{
                if(dx<dy){
                    done[b] = true;
                    ans[b] = dy;
                }else if(dx>dy){
                    done[a] = true;
                    ans[a] = dx;
                    break;
                }
            }
        }
    }
    for(int i = 1;i<=N;i++){
        if(ans[i]==0) cout << "Infinity" << nl;
        else cout << ans[i] << nl;
    }
    return 0;
}
