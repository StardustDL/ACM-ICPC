/*
[Usaco2008 Nov]Buying Hay 购买干草
分析： 完全背包 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=100,MAXM=50000,R=5000+100;
int opt[MAXM+R+3],p[MAXN+3],c[MAXN+3],n,h;
int main(){
    scanf("%d%d",&n,&h);
    memset(opt,0x3f,sizeof(opt));
    opt[0]=0;
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i],&c[i]);
    for(int i=1;i<=n;i++){
        for(int j=p[i];j<=h+R;j++)opt[j]=min(opt[j-p[i]]+c[i],opt[j]);
    }
    printf("%d\n",*min_element(opt+h,opt+h+R+1));
    return 0;
}

