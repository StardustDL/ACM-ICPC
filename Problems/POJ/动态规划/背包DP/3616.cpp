/*
Milking Time
���⣺����һͷ��ţ�����ܹ���һ����ʱ���Ｗ�̡����Ҽ�����Ҳ��ͬ��ÿ�μ���Ҫ��Ϣrʱ�䣬���������Լ������̡�
��������ʱ���dp��Ȼ���������for�����ˡ�ֻҪǰ��������������״̬�Ϳ���ת�ƹ�����Ȼ��ȡ��󣬲���Ҫ������
	  ת�ƣ�opt[i]=max{opt[j],j.y+r<=i.x} 
*/
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000;
struct data{
	int x,y,w;
	bool operator <(const data &d)const{
		return x<d.x||x==d.x&&y<d.y;
	}
}ds[MAXN+3];
int n,m,r,opt[MAXN+3];
int main(){
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&ds[i].x,&ds[i].y,&ds[i].w);
	sort(ds+1,ds+m+1);
	for(int i=1;i<=m;i++)opt[i]=ds[i].w;
	for(int i=1;i<=m;i++)
		for(int j=0;j<i;j++)
			if(ds[i].x>=ds[j].y+r)opt[i]=max(opt[i],opt[j]+ds[i].w);
	printf("%d\n",*max_element(opt+1,opt+m+1));
	return 0;
}
