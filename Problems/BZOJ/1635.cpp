/*
[Usaco2007 Jan]Tallest Cow ��ߵ�ţ
�������е���˼���Ƚ����и߶���ΪH������һ����ϵ(a,b)��
	  �ϸ�С�ڣ��൱�� ����(a,b)-1
	  �������˵㣺ע��˵������ȣ������һ������
	  �����������飬ʹ���������ΪO(1) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
struct segment{
	int l,r;
	bool operator <(const segment &t)const{
		return l<t.l||l==t.l&&r<t.r;
	}
}ss[MAXN+3];
int c[MAXN+3],n,I,H,r; 
int main(){
	scanf("%d%d%d%d",&n,&I,&H,&r);
	for(int i=1;i<=r;i++){scanf("%d%d",&ss[i].l,&ss[i].r);if(ss[i].l>ss[i].r)swap(ss[i].l,ss[i].r);}
	sort(ss+1,ss+r+1);
	for(int i=1;i<=r;i++){
		if(ss[i].l==ss[i-1].l&&ss[i].r==ss[i-1].r)continue;
		c[ss[i].l+1]--,c[ss[i].r]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=c[i];
		printf("%d\n",sum+H);
	}
	return 0;
}

