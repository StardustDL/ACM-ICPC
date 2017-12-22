/*
[SDOI2009]HH������
���⣺��һ������Ĳ�ͬ���ĸ�����50000������200000��ѯ��
���������ݺܴ������������ȼ�¼��ÿ����ɫ����һ����ɫ���ڵ�λ�ã���������ɫ�ĵ�һ����x a[x]++ 
	  ������ѯ�ʰ�����˵��������Ȼ���������ɨ
	  ɨ��һ����x��a[next[x]]++������һ��ѯ��l,r���sum[r]-sum[l-1]
	  ��״����ά�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define lowbit(x) (x&-x)
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50000,MAXM=200000,MAXID=1000000;
int c[MAXN+3],n,id[MAXN+3],nxt[MAXN+3],p[MAXID+3],md=0,m,rd[MAXM+3];
struct query{int l,r,ans;}qs[MAXM+3];
bool cmp(int i,int j){return qs[i].l<qs[j].l;}
void add(int x,int val){
	for(;x<=n;x+=lowbit(x))c[x]+=val;
}
int sum(int x){
	int ans=0;
	for(;x>0;x-=lowbit(x))ans+=c[x];
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&id[i]);
		md=max(md,id[i]);
	}
	for(int i=n;i>0;i--){
		nxt[i]=p[id[i]];p[id[i]]=i;
	}
	for(int i=1;i<=md;i++)if(p[i])add(p[i],1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&qs[i].l,&qs[i].r);rd[i]=i;
	}
	sort(rd+1,rd+m+1,cmp);
	for(int l=1,i=1;i<=m;i++){
		while(l<qs[rd[i]].l){
			if(nxt[l])add(nxt[l],1);
			l++;
		}
		qs[rd[i]].ans=sum(qs[rd[i]].r)-sum(qs[rd[i]].l-1);
	}
	for(int i=1;i<=m;i++)printf("%d\n",qs[i].ans);
	return 0;
}

