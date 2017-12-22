/*
One-way Traffic
���⣺��һ�����ͼ���Ѿ����ܶ������߶���ʹ������ͼ����ǿ��ͨ�����ʣ���������ɴ���𰸱�֤�н⡣���������������յ���� 
������1��tarjan������ͼ�м�������ߣ���������ߣ���ô�Ȱ��������Ϊ������˫��ͨ���ţ�ֱ�������Ȼ��ɾ���ñ߼��ɣ���Ϊ��Ŀ��֤�н⣬������һ��������ߣ�
	  2����ôͼ�о�ֻʣ��һ������ͨ�飬����������ͨ�飨��ǰ�ǵ�����ȫΪ�������Ǳ�Ȼ�ܰ���������߶�����ΪҪʹ�ö��������ǿ��ͨ�����Զ��������u��low[u]ֵһ��<=dfn[u].
	  	1����ǰ������������->����ǰ��������ߣ����粻����õ�ʽ���򽫱߷���������������߷�����ȷ�������ֱ�������ɾ�ߣ�
	  	2����ǰ�������Ǻ����-> ����ȷ����Ϊ����߾�����߳�Ϊ����ߡ�
	  �������ǿ��԰�����߿�������ߣ�Ȼ�����˫��ͨ������������Щ�ţ�����ӱߣ�����ͬһ����ͨ�������ڷ��ʵ�ͬʱ���򣬶�������ߣ�������ʵķ����෴����ô�Ͳ����Է��ʣ�������ÿ����(������now -> v)������low�ĺ��������ʱ����ʵ�Ǽ���low[v]�������Ƕ�����һ���Ƿ����low[v] > low[now]�����������ϵʽ�������Ǿ�˵���������ڵĶ��򷽷���v�ǲ��ܷ��ʵ�����ǰ���ģ����Զ��ڵ�ǰ�ߣ��Ͷ���ȡ����������ǰ��v�ڵ�Ϳ��Է��ʵ�ǰ���ڵ��ˣ���Ϊ�����ͨ��֧ԭ������˫��ͨ�ģ�����ȫ����������ߣ������ԶԵ�ǰ�ߵĸı䣬����Ӱ��v��ǰ���ڵ㵽v����ͨ�ԣ�������ͼ�ͳ�ǿ��ͨ�ˡ�
	  ����ʵ�ֿ����ڱ��ϼ�¼һЩ��Ϣ������������� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000; 
struct edge{
    int u,v,next;
    bool isbridge,flag,isprint;
}es[MAXN*MAXN+3];
int n,m,tot,head[MAXN+3];
void insert(int u,int v,int flag){
    es[tot].u=u;
    es[tot].v=v;
    es[tot].isbridge=false;
    es[tot].flag=flag;
    es[tot].next=head[u];
    if(flag==2)es[tot].isprint=true;
    else es[tot].isprint=false;
    head[u]=tot++;
}
int low[MAXN+3],dfn[MAXN+3],cnt,_count;
bool mark[MAXN+3];
void tarjan(int u,int father){
    int flag=0;
    low[u]=dfn[u]=++cnt;
    mark[u]=true;
    for(int i=head[u];i!=-1;i=es[i].next){
        int v=es[i].v;
        if(v==father&&!flag){flag=1;continue; }
        if(dfn[v]==0){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){//��
                es[i].isbridge=true;
                es[i^1].isbridge=true;
            }
        }
		else if(mark[v])low[u]=min(low[u],dfn[v]);
    }
}
void dfs(int u,int father){
    int flag=0;
    low[u]=dfn[u]=++cnt;
    mark[u]=true;
    for(int i=head[u];i!=-1;i=es[i].next){
        int v=es[i].v;
        if(v==father||es[i].flag==0)continue;
        es[i].flag=1;
        es[i^1].flag=0;
        if(dfn[v]==0){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                es[i].flag=0;
                es[i^1].flag=1;
            }
        }
		else if(mark[v])low[u]=min(low[u],dfn[v]);
    }
}
void solve(){
    for(int i=0;i<tot;i+=2){
        if(es[i].isprint){
            if(es[i].isbridge)printf("%d %d 2\n",es[i].u,es[i].v);
            else if(es[i].flag)printf("%d %d 1\n",es[i].u,es[i].v);
            else printf("%d %d 1\n",es[i].v,es[i].u);
        }
    }
}
int main(){
    int u,v,flag;
    while(~scanf("%d%d",&n,&m)){
        tot=0;
        memset(head,-1,sizeof(head));
        while(m--){
            scanf("%d%d%d",&u,&v,&flag);
            if(flag==2){
                insert(u,v,2);
                insert(v,u,2);
            }else{//Ϊ���ܰ�����ߵ�������ߣ���������� 
                insert(u,v,1);
                insert(v,u,0);
            }
        }
        cnt=0;
        memset(dfn,0,sizeof(dfn));
        memset(mark,false,sizeof(mark));
        tarjan(1,-1);
        cnt=0;
        memset(dfn,0,sizeof(dfn));
        memset(mark,false,sizeof(mark));
        dfs(1,-1);
        solve();
    }
    return 0;
}
