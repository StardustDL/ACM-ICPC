/*
[Usaco2014 Open]Fair Photography
分析：把0看成-1，如果不考虑修改那么用last[x]记录前缀和为x的第一个位置，然后扫一遍
		加上修改就是： 设当前位置pos，前缀和为x，则pos-last[x]，pos-last[x+2]…都能更新答案
		则在这之前
		for(int i=2*n;i>=0;i–)
			last[i]=min(last[i+2],last[i]);
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
struct data{
	int p,v;
	bool operator <(const data &d)const{
		return p<d.p;
	}
}ds[MAXN+3];
int n,lst[2*MAXN+3],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s[5];scanf("%d %s",&ds[i].p,s);
		if(s[0]=='W')ds[i].v=-1;else ds[i].v=1;
	}
	sort(ds+1,ds+n+1);
	memset(lst,INF,sizeof(lst)); 
	int sum=n;lst[sum]=ds[1].p;
	for(int i=1;i<n;i++){
		sum+=ds[i].v;
		lst[sum]=min(lst[sum],ds[i+1].p);
	}
	for(int i=2*n;i>=0;i--)lst[i]=min(lst[i],lst[i+2]);
	sum=n;ans=0;
	for(int i=1;i<=n;i++){
		sum+=ds[i].v;
		ans=max(ans,ds[i].p-lst[sum]);
	}
	printf("%d\n",ans);
	return 0;
}

