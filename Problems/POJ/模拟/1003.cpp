/*
Hangover
题意：求最小的n让1/2+1/3+...+1/n+1/(n+1)大于给的一个实数 
*/
#include<cstdio>
using namespace std;
int solve(double T){
	int i=1;
	while(T>0)T-=1.0/(++i);
	return i-1;
}
int main(){
	double k=0;
	while(scanf("%lf",&k),k!=0)
		printf("%d card(s)\n",solve(k));
	return 0;
}

