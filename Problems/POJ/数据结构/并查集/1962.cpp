/*
题意：给定n台电脑，初始都是以自己作为中心。然后一些询问，E x，问x距离中心多远。 I x y 建立一条x到y的长度为|x-y|(mod 1000)的边，且使得原来x机群的中心转移到y机群上。
分析：并查集，+维护路径长：a[x]=a[fa[x]]+a[x] 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=30000;
int fa[MAXN+3],dist[MAXN+3];
int find(int x){
    if(x==fa[x])return x;
    else{
		int fx=find(fa[x]);
        dist[x]+=dist[fa[x]];//%1000;
        return fa[x]=fx;
    }
}
void uniset(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)return;
    else{
        fa[fx]=x;
        dist[fx]=dist[x];
        fa[x]=y;
        dist[x]=abs(y-x)%1000;
    }
}
int main(){
	int T;
    for(scanf("%d",&T);T;T--){
        int n,x,y;char s[2];
        scanf("%d",&n);
        for(int i=1;i<=n;i++)fa[i]=i,dist[i]=0;
        while(scanf("%s",s),s[0]!='O'){
            if(s[0]=='E'){
                scanf("%d",&x);
                find(x);
                printf("%d\n",dist[x]);
            }
            else{
                scanf("%d%d",&x,&y);
                uniset(x,y);
            }
        }
    }
    return 0;
}
