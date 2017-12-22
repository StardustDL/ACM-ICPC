/*
[SCOI2011]糖果
分析：差分约束，有一个点是一条链，若S->[1..n]会T，要S->[n..1]才行= =，或许从中间就可以了 
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=100005;
int n,k,cnt,q[MAXN+3],head[MAXN+3],cir[MAXN+3],dis[MAXN+3];
long long ans;
bool inq[MAXN+3];
struct edge{int v,nxt,w;}e[4*MAXN+3];
void addedge(int u,int v,int w){e[++cnt].v=v;e[cnt].nxt=head[u];e[cnt].w=w;head[u]=cnt;}
bool spfa(){
	int t=0,w=1;
    q[0]=0;inq[0]=1;cir[0]=1;
    while(t!=w){
		int u=q[t];t++;inq[u]=0;if(t==MAXN)t=0;
        for(int i=head[u];i;i=e[i].nxt){
            if(dis[u]+e[i].w>dis[e[i].v]){
				dis[e[i].v]=dis[u]+e[i].w;
				cir[e[i].v]=cir[u]+1;
				if(cir[e[i].v]>n+1)return false;
				if(!inq[e[i].v]){
					inq[e[i].v]=1;q[w++]=e[i].v;
                    if(w==MAXN)w=0;
				}
			}
		}
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&k);int x,a,b;
    while(k--){
    	scanf("%d%d%d",&x,&a,&b);
    	switch(x){
			case 1:
				addedge(a,b,0);addedge(b,a,0);break;
			case 2:
				if(a==b){printf("-1");return 0;}
                addedge(a,b,1);break;
			case 3:
				addedge(b,a,0);break;
			case 4:
				if(a==b){printf("-1");return 0;}
            	addedge(b,a,1);break;
			case 5:
				addedge(a,b,0);break;
		}
	}
    for(int i=n;i;i--)addedge(0,i,1);
    if(!spfa()){printf("-1");return 0;}
    for(int i=1;i<=n;i++)ans+=dis[i];
    printf("%lld\n",ans);
    return 0;
}
