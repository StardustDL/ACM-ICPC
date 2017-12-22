/*
零用钱
分析：贪心，由于每一个面额都能整除所有比它大的面额，所以基本贪心思路就是：对于每一个星期，先让零用钱不超过C，尽量取大的面额。取完后若没达到C，尽量取小的面额补足到C。
	  一个小优化：如果有一种硬币的金额大于c，则直接把此金额的硬币数量(m)加入星期数(ans)中（相当于每个星期只给一个此金额的硬币就行了） 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=20,INF=0x3f3f3f3f;
int n,c,ans=0;
struct data{
	int v,b;
	bool operator < (const data &t)const{return v<t.v;}
}ds[MAXN+3];
int main(){
	cin>>n>>c;
	for(int i=1;i<=n;i++)cin>>ds[i].v>>ds[i].b;
	sort(ds+1,ds+n+1);
	for(;ds[n].v>=c;ans+=ds[n--].b);
	//cout<<ds[1].v<<endl;
	while(1){
		int t=c;
		for(int i=n;i>=1;i--){
			while(t>=ds[i].v&&ds[i].b){
				t-=ds[i].v;ds[i].b--;
			}
		}
		for(int i=1;i<=n;i++){
			while(t>0&&ds[i].b){
				t-=ds[i].v;ds[i].b--;
			}
		}
		if(t>0)break;
		ans++;
	}
	//for(int i=1;i<=n;i++)cout<<ds[i].b<<endl;
	cout<<ans<<endl;
	return 0;
}

