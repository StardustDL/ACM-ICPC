/*
Yogurt factory
���⣺��n�ܣ���i�ܣ���Ҫ���⹩��yi������1��λ�ɱ�ci�����Ǳ��������Ļ��ﲻ�ڱ������ۣ���Ҫ���أ�1��λ����һ����Ҫ����s��ע�ⲻ����ʡ���n�ܹ������軨�Ѷ���Ǯ���ɱ������طѣ���
���������ڲ�����ʣ�����򵥵ö̰࣬�ģ�������mn��¼��ǰ����С���ۣ�Ȼ������С�������룬�����С���ۣ�Ҫô�����ڵĵ��ۣ�Ҫô��֮ǰ����С���ۣ����طѡ�mn�б��滻����ֵ�ǲ��������Ժ����С���۵ġ���Ϊ���ڱ��滻��ͬʱ�������ɸ�s֮�������ǻ�������滻�����Ǹ�ֵ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL; 
int n,c,y,s,mn=INF;
LL ans=0; 
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c,&y);
		mn=min(mn,c);
		ans+=((LL)mn*y);
		mn+=s;
	}
	printf("%lld",ans);
	return 0;
}

