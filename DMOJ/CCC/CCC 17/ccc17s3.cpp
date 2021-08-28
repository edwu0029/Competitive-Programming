//Problem: https://dmoj.ca/problem/ccc17s3

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
int N, a1, a2, b[2001], s[4001];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, x;i<N;i++){
        cin >> x;
        b[x]++;
    }
    for(int i = 1;i<2001;i++){
        if(b[i]>0){
            s[i*2]+=(b[i]/2);
            for(int j = i+1;j<2001;j++) s[i+j]+=min(b[j], b[i]);
        }
    }
    for(int i = 1;i<4001;i++){
        if(s[i]>a1){
            a1 = s[i];
            a2 = 0;
        }
        if(s[i]==a1) a2++;
    }
    cout << a1 << sp << a2 << endl;
    return 0;
}