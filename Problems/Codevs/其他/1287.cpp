/*
æÿ’Û≥À∑®
*/
#include<iostream>
using namespace std;
const int N=203;
typedef int Me[N][N];
Me a,b,c;
int ai,aj,bi,bj;
int main(){
	cin>>ai>>aj;
	for(int i=1;i<=ai;i++)
		for(int j=1;j<=aj;j++)cin>>a[i][j];
	cin>>bi>>bj;
	for(int i=1;i<=bi;i++)
		for(int j=1;j<=bj;j++)cin>>b[i][j];
	for(int i=1;i<=ai;i++){
		for(int j=1;j<=bj;j++){
			c[i][j]=0;
			for(int k=1;k<=aj;k++)
				c[i][j]+=a[i][k]*b[k][j];
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
