/*
[HNOI2004]树的计数
分析：ans=(n-2)!/((d[1]-1)!(d[2]-1)!(...)(d[n]-1)!)
	  答案在long long内，先分解质因数 
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<iostream>
using namespace std;
#define MAXN 400
int cnt[MAXN]={0};
int d[MAXN]={0};
int n,sum;
inline void toprime(int x, int key){//key：对答案的影响 
    for(int i=2;i<=x;i++)
        if(x%i==0)while(x%i==0&&x>0)cnt[i]+=key,x/=i;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d", &d[i]);
        sum+=d[i];
        if(d[i]==0&&n>1){puts("0");return 0;}
    }
    if(sum!=n*2-2){puts("0");return 0;}
    if(n==1){puts("1");return 0;}
    for(int i=2;i<=n-2;i++)toprime(i,1);
    for(int i=1;i<=n;i++)
        for(int j=2;j<=d[i]-1;j++)toprime(j, -1);
    long long ans=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=cnt[i];j++)ans*=i;
    printf("%lld\n", ans);
}

