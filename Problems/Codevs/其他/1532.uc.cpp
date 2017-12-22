/*
йЩапеепР
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100000;
int n,a[MAXN+3],ans=0,r[MAXN+3];
bool cmp(const int i,const int j){
	if(a[i]<a[j]){
		return true;
	}
	ans++;
	return false;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];r[i]=i;
	}
	sort(r+1,r+n+1,cmp);
	cout<<ans;
	return 0;
}
