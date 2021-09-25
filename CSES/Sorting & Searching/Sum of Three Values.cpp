/*
Sum of Three Values
https://cses.fi/problemset/task/1641
*/

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
const int MAXN = 5005;
int N, x;
pii a[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> x;
    for(int i = 1, t;i<=N;i++){
        cin >> t;
        a[i] = mp(t, i);
    }
    sort(a+1, a+N+1);
    for(int i = 1;i<=N-2;i++){
        int t = x-a[i].first;
        if(t<=0) continue;
        int j = i+1, k = N;
        bool flag = false;
        while(j<k){
            int sum = a[j].first+a[k].first;
            if(sum<t){
                j++;
            }else if(sum>t){
                k--;
            }else{
                flag = true;
                break;
            }
        }
        if(flag){
            cout << a[i].second << sp << a[j].second << sp << a[k].second << nl;
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << nl;
    return 0;
}