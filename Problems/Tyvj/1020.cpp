/*
Ñ°ÕÒÖÊÒòÊı
*/
#include<iostream>
#include<bitset>
#include<algorithm>
using namespace std;
const int MAXN=5000,MAXP=20000;
int pris[MAXN+3],cnt=0,n,ans=0,mx=0,t;
bitset<MAXP+3> isp;
void load(){
	pris[++cnt]=1;
	for(int i=2;i<=MAXP;i++){
		if(isp[i])continue;
		pris[++cnt]=i;
		for(int j=i*i;j<=MAXP;j+=i)isp[j]=1;
	}
}
int Max(int p){
	int ind=lower_bound(pris+1,pris+cnt+1,p)-pris;
	//cout<<pris[ind]<<endl;
	for(int i=ind;i>=1;i--){
		if(p%pris[i]==0)return pris[i];
	}
}
int main(){
	load();
	cin>>n;
	while(n--){
		cin>>t;
		int p=Max(t);//cout<<p<<endl<<endl;
		if(p>mx){
			mx=p;ans=t;
		}
	}
	cout<<ans;
	return 0;
}
