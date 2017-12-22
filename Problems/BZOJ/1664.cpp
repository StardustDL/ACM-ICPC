/*
[Usaco2006 Open]County Fair Events 参加节日庆祝
分析：按右端点排序，DP 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,R,f[200000+5];
struct data{
	int st,t,ed;
	bool operator <(const data &b)const{
		return ed<b.ed;
	}
}a[10000+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].st,&a[i].t);
		a[i].ed=a[i].st+a[i].t;R=max(R,a[i].ed);
	}
	sort(a+1,a+n+1);
	int cur=1;
	for(int i=1;i<=R;i++){
		f[i]=f[i-1];
		while(a[cur].ed==i){
			f[i]=max(f[i],f[a[cur].st]+1);
			cur++;
		}
	}
	printf("%d\n",f[R]);
	return 0;
}
