/*
[SCOI2003]֩������
������ֱ�Ӱ�עˮʱ����ģ�� ����ϸ��ͼ�������������ڵ������޵�= = 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 30
#define MAXM 110
using namespace std;
int n,m,S,T,maxn,ans,top;
struct pipe{
    int x,y,h,v;
}s[MAXN];
int find(int x){for(int i=1;i<=n;i++)if (s[i].x==x)return i;return 0;}
struct edge{
    int to,w;
    edge *next;
}e[MAXM<<1],*prev[MAXN];
void insert(int u,int v,int w){e[++top].to=v;e[top].next=prev[u];prev[u]=&e[top];e[top].w=w;}
int main(){
    scanf("%d",&n);int x,y,w,t1,t2;
    for (int i=1;i<=n;i++)scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].h),s[i].h+=s[i].y;
    s[1].v=1;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)scanf("%d%d%d",&x,&y,&w),t1=find(x-1),t2=find(x+w),insert(t1,t2,y),insert(t2,t1,y);
    scanf("%d%d",&S,&T);
    while(1){
        for (x=1;x;){
            x=0;
            for(int i=1;i<=n;i++){//���п��ܱ�עˮ�Ĺܵ� 
                if(!s[i].v)continue;
                for(edge *t=prev[i];t;t=t->next)
                    if(s[i].h<=t->w&&!s[t->to].v)s[t->to].v=x=1;
            } 
        }
        maxn=0;
        for (int i=1;i<=n;i++)if(s[i].v)maxn=max(maxn,s[i].h);//�ҵ���ߵ� 
        if(s[S].v&&maxn==T){printf("%d\n",ans);return 0;}
        for(int i=1;i<=n;i++)
            if(s[i].v&&s[i].y==s[i].h&&s[i].h==maxn){puts("-1");return 0;}
        for(int i=1;i<=n;i++)//���͸߶ȣ���ʵ�������s[i].y 
            if(s[i].v&&s[i].h==maxn)s[i].h--,ans++;
    }
}
