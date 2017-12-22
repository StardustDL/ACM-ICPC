/*
超级书架
分析：排下序就好了 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=20000;
int n,b,h[MAXN+3],ans=0;
int main(){
	cin>>n>>b;
	for(int i=1;i<=n;i++)cin>>h[i];
	sort(h+1,h+n+1);
	while(b>0){
		b-=h[n--];ans++;
	}
	cout<<ans;
	return 0;
}
