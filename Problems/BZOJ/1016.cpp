/*
[JSOI2008]��С����������
���������ǲ�ͬ����С������������ÿ��Ȩֵ�ıߵ�������ȷ���ģ�ÿ��Ȩֵ�ıߵ�������ȷ����
		�����Ժ�����һ����С���������ó�ÿ��Ȩֵ�ı�ʹ�õ�����x
		Ȼ�����ÿһ��Ȩֵ�ı��������ó�ÿһ��Ȩֵ�ı�ѡ�񷽰�
		Ȼ��˷�ԭ�� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100,MAXM=1000,MOD=31011;
struct edge{
	int u,v,w;
	bool operator <(const edge &e)const{
		return w<e.w;
	}
}es[MAXM+3];
struct uniset{
	int pa[MAXN+3];
	int find(int x){return pa[x]==x?x:find(pa[x]);}
	void init(int n){
		for(int i=1;i<=n;i++)pa[i]=i;
	}
	bool issame(int a,int b){return find(a)==find(b);}
	void unite(int a,int b){pa[find(a)]=find(b);}
}S;
struct data{
	int l,r,cnt;
	data(){l=0,r=0,cnt=0;}
}ds[MAXM+3];
int n,m,dcnt=0,cursum;
int aa[MAXM+3],tp;
void dfs(int i,int cur,int cnt){
	if(cur==ds[i].r+1){
		//for(int i=1;i<=tp;i++)printf("%d ",aa[i]);puts("");
		//cout<<cnt<<" "<<"!!"<<endl;
		if(cnt==ds[i].cnt){cursum++;}
		return;
	}
	int a=S.find(es[cur].u),b=S.find(es[cur].v);
	//if(aa[1]==1&&aa[2]==2&&cur==4)printf("@@@%d %d\n",a,b);
	if(a!=b){
		S.pa[a]=b;
		aa[++tp]=cur;
		dfs(i,cur+1,cnt+1);
		S.pa[a]=a;S.pa[b]=b;
		tp--;
	}
	dfs(i,cur+1,cnt);
}
int sel=0,ans=1;
int main(){
	scanf("%d%d",&n,&m);
	S.init(n);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].w);
	sort(es+1,es+m+1);
	//cout<<es[4].u<<" "<<es[4].v<<endl;
	for(int i=1;i<=m;i++){
		//cout<<es[i].u<<" "<<es[i].v<<" "<<es[i].w<<endl;
		//cout<<es[i].w<<endl;
		if(es[i].w!=es[i-1].w){
			ds[dcnt].r=i-1;
			ds[++dcnt].l=i;
		}
		if(S.issame(es[i].u,es[i].v))continue;
		S.unite(es[i].u,es[i].v);
		ds[dcnt].cnt++;
		sel++;
	}
	ds[dcnt].r=m;
	if(sel!=n-1){
		puts("0");
		return 0;
	}
	S.init(n);
	for(int i=1;i<=dcnt;i++){
		//printf("%d %d %d %d\n",i,ds[i].l,ds[i].r,ds[i].cnt);
		cursum=0;
		dfs(i,ds[i].l,0);
		//cout<<cursum<<endl;
		ans=(ans*cursum)%MOD;
		for(int j=ds[i].l;j<=ds[i].r;j++){
			if(S.issame(es[j].u,es[j].v))continue;
			S.unite(es[j].u,es[j].v);
		}//puts("!!");
	}
	printf("%d\n",ans);
	return 0;
}
