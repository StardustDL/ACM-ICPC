/*
[Usaco2007 Nov]Milking Time 挤奶时间
分析： 结束时间不挤奶，类似线段覆盖，按起点排序然后DP
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=1000;
struct segment{
	int l,r,w;
	segment(int l,int r,int w):l(l),r(r),w(w){}
	bool operator <(const segment &s)const{
		return l<s.l;
	}
};
vector<segment> ss;
int n,m,r,opt[MAXN+3];
int main(){
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1,a,b,c;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		ss.push_back(segment(a,b,c));
	}
	sort(ss.begin(),ss.end());
	for(int i=0;i<m;i++)opt[i]=ss[i].w;
	for(int i=0;i<m;i++)
		for(int j=0;j<i;j++)
			if(ss[j].r+r<=ss[i].l)
				opt[i]=max(opt[i],opt[j]+ss[i].w);
	printf("%d\n",*max_element(opt,opt+m));
	return 0;
}

