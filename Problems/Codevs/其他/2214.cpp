/*
超级书架 2
分析：n较小，直接二进制枚举 
*/
#include<iostream>
using namespace std;
const int MAXN=20,INF=1<<30;
int n,h[MAXN+3],b,ans=INF,t,k;
int main(){
	cin>>n>>b;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=0;i<(1<<n);i++){
		t=k=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				t+=h[j];k++;
				if(t>=b){
					ans=min(ans,t-b);break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
