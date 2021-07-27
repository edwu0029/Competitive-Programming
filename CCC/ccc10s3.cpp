//Problem: https://dmoj.ca/problem/ccc10s3

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
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1005, CUR = 1e6;
int H, K, houses[MAXN], ans = 0;
int lengthto(int st, int ed){
    if(ed<st) swap(st, ed);
    return min(ed-st, st+CUR-ed);
}
bool check(int start, int hose){
    int pre = (houses[start]+hose)%CUR;
    int idx = start, cnt = 0, used = 1;
    bool possible = true;
    while(cnt<H){
        if(used>K){
            possible = false;
            break;
        }
        if(idx>H) idx = 1;
        cnt++;
        if(lengthto(houses[idx], pre)>hose){
            used++;
            pre = (houses[idx]+hose)%CUR;
        }
        idx++;
    }
    if(possible&&used<=K) return true;
    possible = true;
    pre = (houses[start]-hose+CUR)%CUR;
    idx = start, cnt = 0, used = 1;
    while(cnt<H){
        if(used>K){
            possible = false;
            break;
        }
        if(idx<1) idx = H;
        if(lengthto(houses[idx], pre)>hose){
            used++;
            pre = (houses[idx]-hose+CUR)%CUR;
        }
        idx--;
    }
    if(possible&&used<=K) return true;
    return false;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> H;
    for(int i = 1;i<=H;i++) cin >> houses[i];
    sort(houses+1, houses+1+H);
    cin >> K;
    int l = 0, r = CUR;
    while(l<=r){
        int hose = (l+r)/2;
        bool possible = false;
        for(int i = 1;i<=H;i++){
            if(check(i, hose)){
                possible = true;
                break;
            }
        }
        if(possible){
            ans = hose;
            r = hose-1;
        }else{
            l = hose+1;
        }
    }
    cout << ans << nl;
    return 0;
}
