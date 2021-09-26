/*
Core Drill
DMOPC '14 Contest 6 P1
https://dmoj.ca/problem/dmopc14c5p1
*/

#include <bits/stdc++.h>
using namespace std;
int r, h;
double v = 0;
int main(){
    scanf("%d%d",&r,&h);
    v = 3.1415926*r*r*h/3;
    printf("%.2f\n",v);
    
}