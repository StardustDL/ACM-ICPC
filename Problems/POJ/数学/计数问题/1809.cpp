/*
Regetni
题意：给出一些顶点均为整数坐标，问能构成多少个面积为整数的三角形。给出公式：A=|x1y2 - y1x2 + x2y3 - y2x3 + x3y1 - y3x1|/2
分析：面积是否为整数只需要看|x1y2 - y1x2 + x2y3 - y2x3 + x3y1 - y3x1|mod2是否为0，所以可以先对每个x,y都mod2，并不影响结果。所以总共有4种点，01，00，10，11。3重循环枚举三角形的3个顶点分别是哪种，并用公式计算其面积是否为整数，若为整数则用组合数学知识，通过每种顶点的个数计算能构成的三角形数。
	  本质上我们只要让x1y2 ，y1x2 ， x2y3，y2x3， x3y1 ，y3x1这六项中奇数项的个数为偶数个，即0,2,4,6。
	  所以我们把点分类：奇奇，偶偶，奇偶，偶奇。逐个分析之后可以发现，只要保证三个顶点中至少有两个属于同一类，就能保证有偶数个 奇数项。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL;
LL C(int m,int n){//m个数选n个数的组合 
	if(m<n)return 0;
	if(m==n||n==0)return 1;
	LL ans=1;
	for(int i=1,j=m;i<=n;i++,j--)ans=ans*j/i;
	return ans;
}
int n,x,y,t,cnt[5];
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		while(n--){
			scanf("%d%d",&x,&y);
			if((x&1)&&(y&1))cnt[0]++;
			else if( !(x&1) && !(y&1))cnt[1]++;
			else if( !(x&1) && (y&1))cnt[2]++;
			else cnt[3]++; 
		}
		cnt[4]=cnt[0]+cnt[1]+cnt[2]+cnt[3];
		LL ans=0;
		for(int j=0;j<4;j++)
			ans+=C(cnt[j],3)+C(cnt[j],2)*(cnt[4]-cnt[j]);
		printf("Scenario #%d:\n%lld\n\n",i,ans);
	}
	return 0;
}

