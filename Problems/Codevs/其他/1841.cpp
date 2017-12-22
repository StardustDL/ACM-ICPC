/*
烧水问题
题意：题意不难理解，只要每次新的水都和之前的水进行一次热传导就是最优解 
分析：n还是比较小的，但暴力N^2是过不了的，发现当前面的杯子一次又一次被降温后，会趋近于0，那么直接跳过他们
	  还有一个性质：最后各杯温度之和即为总要升高的温度，但这个性质不知道怎么利用 
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n;
double T[300003];
double solve(int n){
	double ans,t=0,k=4200.0/n;
	int cur=1;
	for(int i=1;i<=n;i++){
		T[i]=0;
		for(int j=cur;j<i;j++){
			//if(T[j]-T[i]<0.01)continue;
			T[j]=T[i]=(T[j]+T[i])/2;
		}
		//if(100-T[i]<0.1)break;
		t+=(100-T[i]);T[i]=100;
		while(T[cur]<0.00001)cur++;
		//cout<<t<<endl;
	}
	ans=k*t;
	return ans;
}
int main(){
	cin>>n;
	printf("%.2lf\n",solve(n));
	return 0;
}
