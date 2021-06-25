//Problem: https://dmoj.ca/problem/dwite11c1p2

#include <bits/stdc++.h>
using namespace std;
int N, sum, ans;
int main(){
    for(int i = 0;i<5;i++){
        scanf("%d",&N); int F[N]; ans = sum = 0;
        for(int i = 0;i<N;i++){
            scanf("%d",&F[i]); sum+=F[i];
        }
        sum/=N;
        for(int i = 0;i<N;i++){if(F[i]>sum)ans+=(F[i]-sum);}
        printf("%d\n",ans);
    }
}