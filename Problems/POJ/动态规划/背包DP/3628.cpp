/*
Bookshelf 2
���⣺Nֻ��ţ��ÿֻ��ţӵ�����ԣ�height������ܸ߶�B��������ţ���Ӹ߶������ܹ�������ܣ����ҳ���ֵ��С���Ǹ�excess�߶ȡ�
������01�������������Ϊb+max{h} 
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

