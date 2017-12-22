/*
[Tjoi2013]拯救小矮人
分析：先贪心，逃生能力(a+b)强的肯定是放在最后走，然后dp，f[i]表示逃跑i个人后剩下的人梯最高的高度
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000; 
int n,H;
struct Node{ 
    int a,b;
    bool operator < (const Node &rhs) const{
        return a+b<(rhs.a+rhs.b);    
    }
}t[MAXN+3];
int f[MAXN+3];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&t[i].a,&t[i].b);scanf("%d",&H);
    sort(t+1,t+n+1); 
    int ans=0;
    memset(f,-1,sizeof(f));f[0]=0;
    for(int i=1;i<=n;i++)f[0]+=t[i].a; 
    for(int i=1;i<=n;i++)
        for(int j=n;j>=0;j--)
            if(f[j]+t[i].b>=H)
                f[j+1]=max(f[j+1],f[j]-t[i].a); 
    for(int i=n;i>=0;i--) if(f[i]>=0) { ans=i; break;}
    printf("%d\n",ans);
    return 0;
}
