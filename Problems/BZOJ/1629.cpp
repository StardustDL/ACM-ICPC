/*
[Usaco2007 Demo]Cow Acrobats
������̰�ġ�
		���ȣ�����һ�����У��������������������û��Ӱ�졣
		��������a under b����������Σ��ֵΪ w[b]+sum-s[a](1),sum-s[b](2)
			���b under a����������Σ��ֵΪ w[a]+sum-s[b](3),sum-s[a](4)
		ע��(2)<(3),(4)<(1)�����������ǱȽ�ǰ����������ab���������� w[a]+sum-s[b]<w[b]+sum-s[a]
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
struct data{
	int w,s;
	bool operator <(const data &t)const{
		return t.w-s<w-t.s;//cur��t��������� 
	}
}ds[MAXN+3];
int n,sum=0,ans=-INF;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&ds[i].w,&ds[i].s);
	sort(ds+1,ds+n+1);
	for(int i=n;i>=1;i--){
		ans=max(ans,sum-ds[i].s);
		sum+=ds[i].w;
	}
	printf("%d\n",ans);
	return 0;
}

