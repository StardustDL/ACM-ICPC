/*
Elevator
���������ȣ������ԣ�Ҫ�ø߶Ⱦ����ܸߣ��߶����Ƶ͵������ڵ��£�������a[i]����
		Ȼ����f[i,j]��ʾǰi������,�ܷ񵽴�j�߶�..
		����ܹ������Ϊtrue,���ܵ���Ϊfalse
		��ô���̾���if f[i-1,j] then f[i,j+h[i]]:=true;
		��ʵ�Ƕ��ر�����������ֻ�ǿ����ԣ������������ԣ�ֱ��01���� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int MAXN=400,MAXH=40000,INF=0x3f3f3f3f;
struct data{
	int a,c,h;
	bool operator < (const data &t)const{
		return a<t.a;
	}
}ds[MAXN+3];
bitset<MAXH+3> can=0;
int n,ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&ds[i].h,&ds[i].a,&ds[i].c);
	sort(ds+1,ds+n+1);
	can[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=ds[i].c;j++){
			for(int k=ds[i].a;k>=ds[i].h;k--){
				can[k]=can[k]|can[k-ds[i].h];
			}
		}
	}
	for(ans=ds[n].a;ans>0&&can[ans]==0;ans--);
	printf("%d\n",ans); 
	return 0;
}

