//Problem: http://usaco.org/index.php?page=viewproblem2&cpid=987

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
int N, K;
int main(){
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    string line; cin >> line;
    int line_ch = line.size();
    line_ch = line.size();
    for(int i = 0;i<N-1;i++){
        string word; cin >> word;
        if(line_ch+word.size()<=K){
            line+=" "+word;
            line_ch+=word.size();
        }else{
            cout << line << nl;
            line = word;
            line_ch = word.size();
        }
    }
    cout << line << nl;
    return 0;
}