/*
[Poi2010]Intelligence test
分析：就是判断一个序列是否是另一个的子序列，暴力O(nm)：
		由于不能直接二分确定位置，那么每个数字建vector，每次询问，依次处理每个数字，在其vector中二分出对应位置 。只要每次都能找到匹配的就行。
		这样暴力可以过= = 
*/
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; 
const int MAXN=1000000;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int>	a[MAXN+3];
int b[MAXN+3],p[MAXN+3],n,m;
bool check(){
	int L=read(),now=0;
	for(int i=1;i<=L;i++)p[b[i]=read()]=0;
	for(int i=1;i<=L;i++){
		p[b[i]]=upper_bound(a[b[i]].begin()+p[b[i]],a[b[i]].end(),now)-a[b[i]].begin();
		if(p[b[i]]==a[b[i]].size())return false;
		now=a[b[i]][p[b[i]]];
	}
	return true;
}
int main(){
	m=read();
	for(int i=1;i<=m;i++)a[read()].push_back(i);
	n=read();
	while(n--){
		if(check())puts("TAK");
		else puts("NIE");
	}
	return 0;
}
