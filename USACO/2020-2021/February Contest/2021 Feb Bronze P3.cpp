/*
Clockwise Fence
USACO 2021 February Contest, Bronze, Problem 3
http://usaco.org/index.php?page=viewproblem2&cpid=1109
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
int N;
map<char, int>m;
int nxt(char a, char b){
	int t1 = m[a], t2 = m[b];
	if((t1+90)%360==t2) return 90;
	else if(t1==t2) return 0;
	else if((t1+270)%360==t2) return -90;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    m['E'] = 0;
    m['N'] = 90;
    m['W'] = 180;
    m['S'] = 270;
    cin >> N;
    for(int i = 0, x, y;i<N;i++){
        string s; cin >> s;
        int tot = 0;
        for(int j = 1;j<s.size();j++){
            tot+=nxt(s[j-1], s[j]);
        }
        tot+=nxt(s[s.size()-1], s[0]);
        if(tot==360) cout << "CCW" << nl;
        else cout << "CW" << nl;
    }
    return 0;
}