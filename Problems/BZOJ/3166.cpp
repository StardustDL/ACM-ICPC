/*
[Heoi2013]Alo
�������Ȱ�ԭ˳�����ɳ־û�Trie��Ȼ��Ӵ�С����setά��λ�ã���֤set�е���ǰk�������λ�á��������ڵ�k����V������set����С�ģ�
	  ��set������ǰ����ǰ��Ϊx����̵ĺ��Ϊy����ô���Ǵδ�ֵ�����伴[x+1..V]��[V..y-1]������Ҫ�������������Trie����������ֵ��̰�ļ��ɡ�
	  ע������������Trie��ֻ����һ�Σ�[x+1..y-1]�� 
*/
#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
int ch[MAXN*(32+3)][2],tot=0,root[MAXN+3],bin[31],sum[MAXN*(32+3)];
int insert(int base,int val){
	int rt,cur;rt=cur=++tot;
	for(int i=30;i>=0;i--){
		int t=val>>i&1;
		ch[cur][0]=ch[base][0];ch[cur][1]=ch[base][1];
		base=ch[base][t];
		cur=ch[cur][t]=++tot;
		sum[cur]=sum[base]+1;
	}
	return rt;
}
int query(int val,int l,int r){
	int ans=0;
	for(int i=30;i>=0;i--){
		int t=val>>i&1;
		if(sum[ch[r][t^1]]-sum[ch[l][t^1]])l=ch[l][t^1],r=ch[r][t^1],ans+=bin[i];
		else l=ch[l][t],r=ch[r][t];
	}
	return ans;
}
set<int> S;
set<int>::iterator q,w;
struct data{
	int p,v;
	bool operator <(const data &d)const{
		return v<d.v;
	}
}ds[MAXN+3];
int n,ans=0;
int main(){
	bin[0]=1;for(int i=1;i<=30;i++)bin[i]=bin[i-1]<<1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&ds[i].v);ds[i].p=i;root[i]=insert(root[i-1],ds[i].v);}//ע�Ᵽ��� 
	sort(ds+1,ds+n+1);
	S.insert(-1);S.insert(-2);S.insert(INF);S.insert(INF+1);//���ϱ߽� 
	S.insert(ds[n].p);
	for(int i=n-1;i>=1;i--){
		int l,r,x;l=r=x=ds[i].p;
		q=S.lower_bound(x);w=q;
		w++;r=*w-1;
		q--;q--;l=*q+1;
		l=max(1,l);r=min(r,n);
		if(l!=r)ans=max(ans,query(ds[i].v,root[l-1],root[r]));//������õ��Ǹ� 
		S.insert(ds[i].p);
	}
	printf("%d\n",ans);
	return 0;
}

