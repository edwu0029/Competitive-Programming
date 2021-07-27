//Problem: https://dmoj.ca/problem/ccc10j4

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
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    while(true){
        int N; cin >> N;
        if(N==0){
            break;
        }else if(N==1){
            int x; cin >> x;
            cout << 0 << nl;
            continue;
        }
        vector<int>dif(N-1);
        int p = 0; cin >> p;
        for(int i = 1, x;i<N;i++){
            cin >> x;
            dif[i-1] = x-p;
            p = x;
        }
        int ans = N-1;
        vector<int>cycle;
        for(int r = 0;r<N-1;r++){
            cycle.push_back(dif[r]);
            bool check = true;
            for(int i = 0;i<N-1;i++){
                if(cycle[i%(r+1)]!=dif[i]){
                    check = false;
                    break;
                }
            }
            if(check){
                ans = r+1;
                break;
            }
        }
        cout << ans << nl;
    }
    return 0;
}