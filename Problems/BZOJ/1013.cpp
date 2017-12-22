/*
[JSOI2008]球形空间产生器sphere
分析：高斯消元 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define sqr(x) ((x)*(x))
const int MAXN=10;
double a[MAXN+3][MAXN+3],b[MAXN+3][MAXN+3],ans[MAXN+3];
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++){
			scanf("%lf",&b[i][j]);
			b[i][n+1]+=sqr(b[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=b[i+1][j]-b[i][j];
		}
		a[i][n+1]=(b[i+1][n+1]-b[i][n+1])/2.0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			double t=a[j][i]/a[i][i];
			for(int k=i+1;k<=n+1;k++){
				a[j][k]=a[j][k]-a[i][k]*t;
			}
		}
	}
	for(int i=n;i>=1;i--){
		double sum=0;
		for(int j=n;j>i;j--)sum+=a[i][j]*ans[j];
		ans[i]=(a[i][n+1]-sum)/a[i][i];
	}
	for(int i=1;i<n;i++)printf("%.3lf ",ans[i]);
	printf("%.3lf\n",ans[n]);
	return 0;
}
