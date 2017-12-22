/*
铺地毯
分析：先全读进来，然后只处理和目标有关的 
*/
#include<iostream>
using namespace std;
const int MAXN=10000; 
int n,a[MAXN+3],b[MAXN+3],g[MAXN+3],k[MAXN+3],x,y,ans=-1;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>g[i]>>k[i];
	}
	cin>>x>>y;
	for(int i=1;i<=n;i++){
		if(x>=a[i]&&x<=a[i]+g[i]-1&&y>=b[i]&&y<=b[i]+k[i]-1)ans=i;
	}
	cout<<ans;
	return 0;
}
