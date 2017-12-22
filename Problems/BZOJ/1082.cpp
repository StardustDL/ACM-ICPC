/*
[SCOI2005]դ��
��������������+��֦
		��ľ�����򣬶��ֿ����г�ľ�������
		��Ȼ������С��ans��
		����ÿ��ľ�����ĸ�ľ����
		��֦���ǵ�ľ�Ĵ�СС����С��ľ������
		��¼��ǰ������ľ������������ans��ľ�� > ���е�ľ�� �򲻺Ϸ� 
	  ������Ŀ�У����ڵ��ϰ��ṩ�ĺ�Լ����Ҫ��ÿ��ľ�壬��ֻ��ʹ��һ�Ρ���仰��ʲô��˼��һ��ľ��ֻ����һ�Σ�����������WA��= = 
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; 
const int MAXN=1000;
int v[MAXN+3], w[MAXN+3], sum[MAXN+3], c[MAXN+3], tot, rest, n, m;
bool dfs(int dep, int last) {
	if(!dep) return true;
	if(rest+sum[dep]>tot) return false;
	for(int i=last;i<=n;i++) {
		if(c[i]>=w[dep]) {
			c[i]-=w[dep];
			if(c[i]<w[1]) rest+=c[i];
			if(w[dep]==w[dep-1]) { if(dfs(dep-1, i)) return true; }
			else if(dfs(dep-1, 1)) return true;
			if(c[i]<w[1]) rest-=c[i];
			c[i]+=w[dep];
		}
	}
	return false;
}
bool check(int d) {
	memcpy(c,v,sizeof(int)*(n+1));
	rest=0;
	return dfs(d, 1);
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&v[i]);tot+=v[i];}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	sort(w+1,w+m+1);
	sort(v+1,v+n+1);
	for(int i=1;i<=m;i++) sum[i]=sum[i-1]+w[i];
	while(sum[m]>tot)--m;
	int l=0,r=m,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}

