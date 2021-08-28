//Problem: https://dmoj.ca/problem/ecoo21p2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 1e5+2;
string S;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> S;
    string ans = "";
    for(int i = 0;i<S.size();i++){
        ans+=S[i];
        if(i+1<S.size()&&S[i]=='A'&&S[i+1]!='A'){
            continue;
        }else if(i+1<S.size()&&S[i]!='A'&&S[i+1]=='A'){
            continue;
        }else{
            ans+=' ';
        }
    }
    cout << ans << nl;
    return 0;
}