/*
Hamming Problem
题意：求因子是{p1,p2,p3}的子集的数组成数列的第n项 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
long long dp[10003],p[4],a,b,c,n;
int main(){
    while(scanf("%d %d %d %d",&p[1],&p[2],&p[3],&n)==4){
        a=b=c=0;
        dp[0]=1;
        for(int i=1;i<=n;i++){
            long long t=min(min(p[1]*dp[a],p[2]*dp[b]),p[3]*dp[c]);
            if(t==p[1]*dp[a])a++;
            if(t==p[2]*dp[b])b++;
            if(t==p[3]*dp[c])c++;
            dp[i]=t;
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}

