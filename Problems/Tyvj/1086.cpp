/*
Elevator
分析：首先，很明显，要让高度尽可能高，高度限制低的箱子在底下，即按照a[i]排序
		然后，用f[i,j]表示前i个箱子,能否到达j高度..
		如果能够到达就为true,不能到达为false
		那么方程就是if f[i-1,j] then f[i,j+h[i]]:=true;
		其实是多重背包，但由于只是可行性，而不是最优性，直接01背包 
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

