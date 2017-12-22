/*
[Tjoi2013]����С����
��������̰�ģ���������(a+b)ǿ�Ŀ϶��Ƿ�������ߣ�Ȼ��dp��f[i]��ʾ����i���˺�ʣ�µ�������ߵĸ߶�
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
