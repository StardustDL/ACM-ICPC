/*
[Noi2014]ħ��ɭ��
��������̬�ӱ����·��
		���Ƕ�a����ö��a������ÿһ��ö����bȨ���ֵ����Сֵ����
		��M�����·�϶���ʱ���� ���Ϻܶ���д��LInk-Cut-Treeά����̬��С������������ʵ 
		����Ҫ�õ����·�Ķ�̬�ӵ㣨�ߣ��� ����ÿ��һ���� �Ͱѱߵ����˵���� ����dijkstra ���ö�f�������memset
		�ⷽ���ǳ��� ��LCT��д�˲�֪���� Ȼ�����ﻹ�м�֦
		��֦1 ÿ��һ���߾�dijkstra��Ȼ���˷ѣ����ǰ�aֵ��ͬ�ĵ�ͳͳ������У�Ȼ��dijkstraһ�ν��
		��֦2 ����һ��˫��� ���ǲ���������м������㣬ֱ�����������и���fֵ��ģ��ܸ��¾ͼ������
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue> 
using namespace std;
const int MAXN=50000,MAXM=100000,INF=0x3f3f3f3f;
struct edge{
	int u,v,a,b;
}E[MAXM*2+100],es[MAXM+3];
bool cmp(edge x,edge y){
	return x.a<y.a;
}
struct node{
	int p,d;
	bool operator <(const node &t)const{
		return d>t.d;
	}
	node(int p,int d):p(p),d(d){}
};
int head[MAXN+3],nxt[2*MAXM+100],cnt=1;//ע��next���鿪����M 
void addedge(int id){
	E[++cnt]=es[id];
	nxt[cnt]=head[E[cnt].u];
	head[E[cnt].u]=cnt;
	E[++cnt]=es[id];
	swap(E[cnt].u,E[cnt].v);
	nxt[cnt]=head[E[cnt].u];
	head[E[cnt].u]=cnt;
}
priority_queue<node> q;
int f[MAXN+3];
void dijkstra(){
	while(!q.empty()){
		node u=q.top();q.pop();
		if(u.d>f[u.p])continue;
		for(int i=head[u.p];i;i=nxt[i]){
			if(f[E[i].v]>max(E[i].b,f[E[i].u])){
				f[E[i].v]=max(E[i].b,f[E[i].u]);
				q.push(node(E[i].v,f[E[i].v]));
			}
		}
	}
}
int ans=INF,n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&es[i].u,&es[i].v,&es[i].a,&es[i].b);
	}
	sort(es+1,es+m+1,cmp);
	memset(f,INF,sizeof(f));
	f[1]=0;
	for(int i=1;i<=m;i++){
		addedge(i);
		if(f[es[i].u]>f[es[i].v])  
            swap(es[i].u,es[i].v);  
        if(max(f[es[i].u],es[i].b)<f[es[i].v]){  
            f[es[i].v]=max(f[es[i].u],es[i].b);
			q.push(node(es[i].v,f[es[i].v]));  
		}
        if(es[i].a!=es[i+1].a)
            dijkstra();
        ans=min(ans,es[i].a+f[n]);
	}
	printf("%d\n",ans==INF?-1:ans); 
	return 0;
}

