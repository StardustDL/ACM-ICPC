/*
¹¤×÷·ÖÅä
*/
#include<iostream>
#include<algorithm>
using namespace std;
long a[4][4],ans=0;
int main(){
	for(int i=1;i<=3;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(i==j)continue;
			for(int k=1;k<=3;k++){
				if(k==i||k==j)continue;
				ans=max(a[1][i]+a[2][j]+a[3][k],ans);
			}
		}
	}
	cout<<ans;
	return 0;
}
