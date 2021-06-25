//Problem: https://dmoj.ca/problem/coci18c1p3

#include <bits/stdc++.h>
using namespace std;
int N, M, l[100000], r[100000], low, high = 1e9, mid, cnt, ans;
int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0;i<N;i++)scanf("%d", &l[i]);
    for(int i = 0;i<M;i++)scanf("%d", &r[i]);
    sort(l, l+N);
    sort(r, r+M);
    while(low<=high){
        mid = (low+high)/2; cnt = 0;
        for(int i = 0, j = 0;i<N&&j<M;){
            if(abs(l[i]-r[j])<=mid){
                i++; j++; cnt++;
            }else if(l[i]>r[j]){
                j++;
            }else{
                i++;
            }
        }
        if(cnt==min(N, M)){
            ans = mid; high = mid-1;
        }else low = mid+1;
    }
    printf("%d\n", ans);
    return 0;
}