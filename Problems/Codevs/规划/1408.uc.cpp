/*
最长公共子序列
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=3000;
int n,a[MAXN+3],b[MAXN+3],opt[MAXN+3][MAXN+3];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==b[j]){
				for(int k=1;k<=i;k++){
					
				}
				opt[i][j]=opt[i-1][j-1]+1;
			}
			else {
				opt[i][j]=max(opt[i-1][j],opt[i][j-1]);
			}
		}
	}
	return 0;
} 
