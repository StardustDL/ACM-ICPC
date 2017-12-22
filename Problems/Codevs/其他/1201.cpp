/*
最小数和最大数
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int INF=1<<31-1;
int n,a,mn=INF,mx=-1*INF;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n-->0){
		cin>>a;
		mn=min(mn,a);
		mx=max(mx,a);
	}
	cout<<mn<<" "<<mx;
	return 0;
}
