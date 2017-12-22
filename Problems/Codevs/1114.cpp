/*
搭建双塔
分析：用can[i][j]表示两塔高度为i,j是否可行，然后背包即可
	  注意几个细节：内部循环必须要两重，然后选择一维进行转移，不能两维分别转移，会有后效性
	  最后求答案时循环到1，不要循环到0（0一定可行）
	  这样的复杂度是:n*sum^2，但是也能过
	  另一种状态表示：
	  用f[i,j]表示使用前i个水晶,建起高度差为j的双塔时,较矮的那个塔的最大高度是多少。
  		这样的话,对于每一块水晶都有三种决策,不使用,放到高塔上,放到矮塔上.而放到矮塔上会有两种情况,一是使矮塔的高度超过了高塔,二是没有超过。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
bool can[MAXN+3][MAXN+3];
int n,a[100+3],sum=0,ans=-1; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	can[0][0]=1;
	sum>>=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=0;j--){
			for(int k=sum;k>=0;k--){
				if(j>=a[i])can[j][k]|=can[j-a[i]][k];
				if(k>=a[i])can[j][k]|=can[j][k-a[i]];
			}
		}
	}
	for(int i=sum;i>=1;i--){
		if(can[i][i]){ans=i;break;}
	}
	if(ans==-1)puts("Impossible");
	else printf("%d\n",ans); 
	return 0;
}

