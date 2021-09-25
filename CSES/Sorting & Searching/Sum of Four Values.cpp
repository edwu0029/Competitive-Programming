/*
Sum of Four Values
https://cses.fi/problemset/task/1642/
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
const int MAXN = 1005, MAXM = 1e6+5;
int N, x, a[MAXN];
vector<tuple<int, int, int>>prs;
bool check(int i, int j, int k, int l){
    if(i==k||i==l) return false;
    if(j==k||j==l) return false;
    return true;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> x;
    for(int i = 1;i<=N;i++) cin >> a[i];
    for(int i = 1;i<=N;i++){
        for(int j = i+1;j<=N;j++){
            prs.push_back(make_tuple(a[i]+a[j], i, j));
        }
    }
    sort(prs.begin(), prs.end());
    int i = 0, j = prs.size()-1;
    while(i<j){
        int s1 = get<0>(prs[i]), p1 = get<1>(prs[i]), p2 = get<2>(prs[i]);
        int s2 = get<0>(prs[j]), p3 = get<1>(prs[j]), p4 = get<2>(prs[j]);
        int sum = s1+s2;
        if(sum<x){
            i++;
        }else if(sum>x){
            j--;
        }else{
            if(check(p1, p2, p3, p4)){
                cout << p1 << sp << p2 << sp << p3 << sp << p4 << nl;
                return 0; 
            }else if(i+1<j&&get<0>(prs[i+1])==s1){
                i++;
            }else{
                j--;
            }
        }
    }
    cout << "IMPOSSIBLE" << nl;
    return 0;
}