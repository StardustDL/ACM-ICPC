/*
Euro Efficiency
题意：凑数字问题。给六个纸币面额，第一个一定是1，用最少的这六个纸币凑出1-100的面值，求这1-100需要的纸币数中的最大值，和总和/100。注意纸币可加可减
分析：完全背包或BFS，注意完全背包体积为负数的时候反过来做，
	  数组上限这样设计：由于第一个数是1，所以每个数最多由100个货币组成由于来回，范围是最大值相加50次，最大为5000来，其实由于其他四个数的影响，远还不到这个数， 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1500;
int p[6],opt[(MAXN<<2)+3],T;
int main(){
	for(scanf("%d",&T);T;T--){
		for(int i=0;i<6;i++)scanf("%d",&p[i]);
		memset(opt,INF,sizeof(opt)); 
		opt[0]=0;
		for(int i=0;i<6;i++)
			for(int j=p[i];j<=MAXN;j++)opt[j]=min(opt[j],opt[j-p[i]]+1);
		for(int i=0;i<6;i++)
			for(int j=MAXN-p[i];j>=1;j--)opt[j]=min(opt[j],opt[j+p[i]]+1);
		int sum=0;
		for(int i=1;i<=100;i++)sum+=opt[i];
		printf("%.2lf %d\n",sum/100.0,*max_element(opt+1,opt+100+1));
	}
	return 0;
}

