/*
[Hnoi2010]City ���н���
��������̬��С��������CDQ���Σ���������Сͼ�Ĺ�ģ
	  �����ؼ��Ĳ�����
  		Reduction(ɾ�����ñ�)��
  		�Ѵ��޸ĵı߱�ΪINF����һ��MST�����������MST�еķ�INF��ɾȥ����Ϊ��Щ����ԭͼ������¿϶���������ѡ��MST�ı߼��������ñߣ���
  		Contraction(�������)��
  		�Ѵ��޸ĵı߱�Ϊ-INF����һ��MST����MST�еķ�-INF��Ϊ����ߣ���Ϊ��Щ����ԭͼ�������Ҳһ���ᱻѡ��MST�������㡣 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=20000,MAXQ=50000,MAXM=50000,INF=0x3f3f3f3f;
typedef long long LL;
struct query{int x,y;}q[MAXQ+3];
struct edge{
	int pos,u,v,w;
	bool operator <(const edge &e)const{
		return w<e.w;
	}
}e[25][MAXM+3],d[MAXM+3],t[MAXM+3];
int n,m,Q;
LL ans[MAXQ+3];
int pa[MAXN+3],sz[MAXN+3],cnt[25+3];//cntά��ÿһ��ͼ�ı��� 
int epos[MAXM+3],val[MAXM+3];//val���ݱߵ�ֵ���Ա��ع�ͼ��epos������ͼ��ʱ���޸ģ�����һ��ݹ�ʱ���������ع�ͼ 
void init_set(edge *es,int n){
	for(int i=1;i<=n;i++)pa[es[i].u]=es[i].u,sz[es[i].u]=1,pa[es[i].v]=es[i].v,sz[es[i].v]=1;
}
int find_pa(int x){
	return x==pa[x]?x:pa[x]=find_pa(pa[x]);
}
void unite(int x,int y){
	if(sz[x]>sz[y])swap(x,y);
	sz[y]+=sz[x];pa[x]=y;
}
void contraction(int &etot,LL &sum){//��Ҫ�޸ĵı�Ȩֵ��Ϊ-INF�����ñ��������õ����б���ߣ�sum�����б���ߵ�Ȩֵ�� ��Ŀ�ģ�ͨ������ʹ��ͼ��С 
	int tmp=0;init_set(d,etot);//tmpά��ʣ����ٱߣ�t�洢ʣ�µı� 
	sort(d+1,d+etot+1);
	for(int i=1;i<=etot;i++){//��һ��MST��������-INF�� 
		int a=find_pa(d[i].u),b=find_pa(d[i].v);
		if(a!=b){unite(a,b);t[++tmp]=d[i];} 
	}
	init_set(t,tmp);
	for(int i=1;i<=tmp;i++){//�ڶ���MST��������-INF�ߣ���Ȩֵ�� ��ע�������Ƕ�t��ı���MST 
		int a=find_pa(t[i].u),b=find_pa(t[i].v);
		if(a!=b&&t[i].w!=-INF){unite(a,b);sum+=t[i].w;}
	}
	tmp=0;//��ԭͼ����
	for(int i=1;i<=etot;i++){
		int a=find_pa(d[i].u),b=find_pa(d[i].v);
		if(a!=b){
			t[(epos[d[i].pos]=++tmp)]=d[i];//���������ߣ�����¼������λ��epos 
			t[tmp].u=a,t[tmp].v=b;
		}
	}
	etot=tmp;
	for(int i=1;i<=etot;i++)d[i]=t[i];
}
void reduction(int &etot){//��Ҫ�޸ĵı�Ȩֵ��ΪINF�����ñ�������ȥ���������ñ� 
	int tmp=0;init_set(d,etot);
	sort(d+1,d+etot+1);
	//�����Ҫ�ı�ı߶���Ϊ���ֵ��Ҳ�ò�����i����ô��iΪ�ϱ�
	for(int i=1;i<=etot;i++){
		int a=find_pa(d[i].u),b=find_pa(d[i].v);
		if(a!=b){
			unite(a,b);
			t[epos[d[i].pos]=++tmp]=d[i];
		} 
		else if(d[i].w==INF)t[epos[d[i].pos]=++tmp]=d[i];//�޸ıߵ������Ѿ���Ϊһ����ͨ�飬������������ �޸ı� ��Ȩֵ��������ʵֵ������INF�����Ի�Ҫ�������� 
	}
	etot=tmp;
	for(int i=1;i<=etot;i++)d[i]=t[i];
}
void solve(int l,int r,int cur,LL sum){//cur��ͼ�ı�� 
	int tot=cnt[cur];
	if(l==r)val[q[l].x]=q[l].y;
	for(int i=1;i<=tot;i++)e[cur][i].w=val[e[cur][i].pos];//�ؽ�����ͼ���޸�Ȩֵ��
	for(int i=1;i<=tot;i++){d[i]=e[cur][i];epos[d[i].pos]=i;}//����ǰͼ���ƣ�������������������²㹹ͼ 
	if(l==r){
		init_set(d,tot);
		ans[l]=sum;sort(d+1,d+tot+1);
		for(int i=1;i<=tot;i++){
			int a=find_pa(d[i].u),b=find_pa(d[i].v);
			if(a!=b){
				unite(a,b);ans[l]+=d[i].w;
			}
		}
		return;
	}
	for(int i=l;i<=r;i++)d[epos[q[i].x]].w=-INF;
	contraction(tot,sum);
	for(int i=l;i<=r;i++)d[epos[q[i].x]].w=INF;
	reduction(tot);
	for(int i=1;i<=tot;i++)e[cur+1][i]=d[i];//�浽��һ���ͼ�У�����Ȩֵ��û�иĻ� 
	int mid=(l+r)>>1;
	cnt[cur+1]=tot;
	solve(l,mid,cur+1,sum); 
	solve(mid+1,r,cur+1,sum);
}
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&e[0][i].u,&e[0][i].v,&val[i]);
		e[0][i].w=val[i];
		e[0][i].pos=i;
	}
	for(int i=1;i<=Q;i++)scanf("%d%d",&q[i].x,&q[i].y);
	cnt[0]=m;
	solve(1,Q,0,0);
	for(int i=1;i<=Q;i++)printf("%lld\n",ans[i]);
	return 0;
}

