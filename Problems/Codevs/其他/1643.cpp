/*
线段覆盖 3
分析：贪心，按右端点递增排序，相当于每次选右端点最靠左的区间  
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000000;
struct Q{
	int a,b;
	Q(int x,int y){
		if(x>y)a=y,b=x;
		else a=x,b=y;
	}
	Q(){}
	bool operator < (const Q &e)const{
		return b<e.b;
	}
}q[MAXN+3];
int n,a,b,curb=-10000,ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;q[i]=Q(a,b);
	}
	sort(q+1,q+n+1);
	for(int i=1;i<=n;i++)
		if(q[i].a>=curb)ans++,curb=q[i].b;
	cout<<ans;
	return 0;
}
