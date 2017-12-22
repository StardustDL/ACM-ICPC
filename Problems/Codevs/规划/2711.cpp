/*
Êý×Ö»®·Ö
*/
#include<iostream>
using namespace std;
const int MAXN=200,MAXK=11;
long opt[MAXN+3][MAXK+3],n,k;
int main(){
	cin>>n>>k;
	opt[0][0]=1; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
			if(i>=j)opt[i][j]=opt[i-1][j-1]+opt[i-j][j];
	}
	cout<<opt[n][k];
	return 0;
} 
