/*
[Usaco2005 Mar]Yogurt factory
������̰�ģ���֮ǰ����Сֵ�Ƚϣ�ѡ���ŵ� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,c,y,s;
LL ans,l;
int main(){
	scanf("%d%d",&n,&s);
	l=INF-s;
	while(n--){
		scanf("%d%d",&c,&y);
		l=min(l+s,(LL)c);//����֧�ּӶ��s 
		ans+=(LL)l*y;
	}
	printf("%lld\n",ans); 
	return 0;
}

