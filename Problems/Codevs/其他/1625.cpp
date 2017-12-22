/*
Êý×Ö½ð×ÖËþ
*/
#include<iostream>
using namespace std;
int n,s[1001][1001];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>s[i][j];
	for(int i=n-1;i>=1;i--)
		for(int j=1;j<=i;j++)
			if(s[i+1][j]>s[i+1][j+1])
				s[i][j]+=s[i+1][j];
			else s[i][j]+=s[i+1][j+1];
	cout<<s[1][1];
	return 0;
}
