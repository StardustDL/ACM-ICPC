/*
GF弹钢琴
分析：题目看似很复杂，让我们来简化一下：
	  我们不需要考虑某个键具体是哪根手指按下的。
	  如果左手大拇指在L，右手大拇指在R，那么在[L-8,L]之间的键就能被左手按到，在[R,R+8]之间的键就能被右手按到。
	  所以我们只需要知道两个手大拇指的位置。
	  其次，虽然题目中给了手指不能交叉等限制，但是可以发现，这些限制都是没用的。
	  因为显然存在一种不交叉的方案比交叉的要优。
	  又注意到每次实际上只能移动一只手。 
	  方程为：
	  F[i,j,k]表示弹完第i个音符时，左手大拇指在j位置，右手大拇指在k位置的最小体力花费。
	  转移：对于第i+1个音符，如果需要按第p个键，
	  那么F[i,j,k]可以转移到F[i+1,l,k] (p<=l<=p+8)和F[i+1,j,r] (p-8<=r<=p)，
	  相应的计算花费就可以了，但注意距离要加绝对值。 
*/ 
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int opt[MAXN+3][52+3][52+3],l,r,n,a[MAXN+3],ml,mr; 
void input(){
	cin>>l>>r>>n;
	memset(opt,INF,sizeof(opt));
	for(int i=1;i<=n;i++)cin>>a[i];
}
int dp(){
	opt[0][l][r]=0;
	for(int i=0;i<n;i++){//i执行到n-1 
		for(int j=0;j<52;j++){
			for(int k=0;k<52;k++){
				for(int l=a[i+1];l<=min(a[i+1]+8,51);l++){//移动左手 
					opt[i+1][l][k]=
						min(opt[i+1][l][k],
							opt[i][j][k]+(int)sqrt(abs(j-l)));
				}
				for(int r=max(a[i+1]-8,0);r<=a[i+1];r++){//移动右手 
					opt[i+1][j][r]=
						min(opt[i+1][j][r],
							opt[i][j][k]+(int)sqrt(abs(r-k)));
				}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<52;i++)
		for(int j=0;j<52;j++)
			ans=min(ans,opt[n][i][j]);
	return ans;
}
int main(){
	input();
	cout<<dp(); 
	return 0;
}
