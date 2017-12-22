/*
[HNOI2008]玩具装箱toy
分析：斜率优化DP 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAXN=50000;
#define S(a,b) (f[a]-f[b]<<1)
#define G(x,y) (opt[x]-opt[y]+(f[x]+c)*(f[x]+c)-(f[y]+c)*(f[y]+c))
typedef long long LL;
int n,q[MAXN+3];
LL c,sum[MAXN+3],f[MAXN+3],opt[MAXN+3];
void input(){
    scanf("%d%lld",&n,&c);c++;
    for(int i=1;i<=n;i++){
        scanf("%lld",&sum[i]);
        sum[i]+=sum[i-1];
        f[i]=sum[i]+(LL)i;
    }
}
LL dp(){
    int h=1,t=2;
    q[1]=0;
    for(int i=1;i<=n;i++){
        while(h<t-1&& G(q[h+1],q[h]) <= S(q[h+1],q[h]) * f[i] ) h++;
        opt[i]=opt[q[h]]+(f[i]-f[q[h]]-c)*(f[i]-f[q[h]]-c);
        while(h<t-1&& G(i,q[t-1]) * S(q[t-1],q[t-2]) <= G(q[t-1],q[t-2]) * S(i,q[t-1]) ) t--;
        q[t++]=i;
    }
    return opt[n];
}
int main(){
    input();
    printf("%lld\n",dp());
    return 0;
}

