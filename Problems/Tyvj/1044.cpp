#include<iostream>
#include<algorithm>
using namespace std;
int n,s[101][101];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>s[i][j];
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++)
		{
			s[i][j]+=max(s[i+1][j],s[i+1][j+1]);
		}
	}
	cout<<s[1][1];
	return 0;
}
