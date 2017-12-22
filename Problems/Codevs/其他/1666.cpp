/*
买票
分析：预处理前缀和，然后枚举区间即可 
*/
#include<iostream>
using namespace std;
int n,f,a[1000003],ans=0,t;
int main(){
	cin>>n>>f;
	for(int i=1;i<=n;i++){
		cin>>t;
		a[i]=a[i-1]+t;
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			if(a[j]-a[i-1]<=f){
				ans=max(ans,j-i+1);break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
