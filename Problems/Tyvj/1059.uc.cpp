//Î´Í¨¹ý 
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=10000,INF=101;
int l,s,t,m,a[101],b[101],opt[MAXN+3];
void read(){
	ios::sync_with_stdio(false);
	cin>>l>>s>>t>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)b[i]=a[i]-a[i-1];
	for(int i=1;i<=m;i++)if(b[i]>100){
		l-=b[i]-100;
		b[i]=100;
	}
	for(int i=1;i<=m;i++){
		a[i]=a[i-1]+b[i];
		opt[a[i]]=1;
	}
}
int solve(){
	for(int i=0;i<=l;i++){
		int t=INF;
		for(int j=s;j<=t;j++){
			t=min(t,opt[i-j]);
		}
		opt[i]+=t;
	}
	return opt[l];
}
int main(){
	read();	
	cout<<solve()<<endl;
	return 0;
}
