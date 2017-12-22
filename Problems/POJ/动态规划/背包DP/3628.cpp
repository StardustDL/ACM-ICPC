/*
Bookshelf 2
题意：N只奶牛，每只奶牛拥有属性（height），书架高度B。求令奶牛叠加高度正好能够超过书架，并且超过值最小的那个excess高度。
分析：01背包。总体积变为b+max{h} 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=20,MAXV=1000000*(MAXN+1);
int n,h[MAXN+3],b,v,ans;
bitset<MAXV+3> can;
int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++)scanf("%d",&h[i]);
	v=b+*max_element(h+1,h+n+1);
	can[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=v;j>=h[i];j--)can[j]=can[j]|can[j-h[i]];
	for(ans=0;ans<=v-b&&(!can[b+ans]);ans++);
	printf("%d\n",ans);
	return 0;
}

