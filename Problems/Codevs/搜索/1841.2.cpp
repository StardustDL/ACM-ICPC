/*
1841.2
Éèbn=a[n][1]+...+a[n][n]
Ôòbn=a[n-1][1]*(sigma{2^(-i)|i=1->n}
    +a[n-1][2]*(sigma{2^(-i)|i=1->n-1}
    +...
    +a[n-1][n]*(sigma{2^(-i)|i=1->n-n+1})
*/
#include<iostream>
#include<cstdio>
using namespace std;
double T[3000][3000];
/*double dfs(int n){
	if(n==1)return 
}*/
int main(){
	int n;
	cin>>n;
	T[1][1]=100;
	for(int i=2;i<=n;i++){
		T[i][1]=T[i-1][1]/2;
		T[i][i]=100;
		for(int j=2;j<i;j++){
			T[i][j]=(T[i][j-1]+T[i-1][j])/2;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++)printf("%.2lf ",T[i][j]);
		printf("\n");
	}
}

/*
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const LL M=100000000000LL,K=100*M;
int n;
LL T[300003];
double solve(int n){
	double t=0;LL e;
	int cur=1;
	for(int i=1;i<=n;i++){
		e=0;T[i]=K;
		for(int j=cur;j<i;j++){
			T[j]=e=(T[j]+e)>>1;
		}
		while(T[cur]<1000000)cur++;
	}
	for(int i=1;i<=n;i++)t+=T[i];
	return 4200.0/n*(t*1.0/M);
}
int main(){
	cin>>n;
	printf("%.2lf\n",solve(n));
	return 0;
}
*/
