/*
Buy Tickets
���⣺����N(1 <= N <= 200000)��������(A,B)����ʾ��A(0<=A<i)�ұߵ�λ�ò���һ��B������N�β�����������B���е���������� 
�������������룬�Ȳ������һ��Ҫ����ģ��ڵ�A+1λ�ò���B������ĳ��λ��ǰҪ��A+1����ΪA��0��ʼ������λ�ã�����ά��λ���Ƿ���������״����ά��һ���㼰��֮ǰ�ж��ٸ���
	  ����ʱ������λ�ã�ֱ���ҵ�һ��λ��������֮ǰ��A+1����λ����B�ŵ����λ�ã�ͬʱ������״����
	  O(nlog^2n) 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define lowbit(x) ((x)&(-x)) 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200000;
struct value{
	int val,pos;
}vs[MAXN+3];
int c[MAXN+3],n,ans[MAXN+3];
void add(int x,int ad){for(;x<=n;x+=lowbit(x))c[x]+=ad;}
int sum(int x){int ans=0;for(;x>0;x-=lowbit(x))ans+=c[x];return ans;} 
int ef(int l,int r,int val){
	int ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(mid-sum(mid)>=val)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){scanf("%d%d",&vs[i].pos,&vs[i].val);vs[i].pos++;}
		memset(c,0,sizeof(c));memset(ans,0,sizeof(ans));
		for(int i=n;i>=1;i--){
			int p=ef(1,n,vs[i].pos);
			ans[p]=vs[i].val;
			add(p,1);
		}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}

