/*
FatMouse' Trade
题意：一共有n个房子，每个房子里有老鼠喜欢吃的javabeans,但是每个房间里的javabeans的总价格不一样。老鼠用m元，问m元最多可以卖多少javabeans，其中每个房间里的javabeans可以被分割。 
分析：按单价从小到大排序，先选大的（贪心） 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
struct data{
	int j,f;double pri;
	void cal(int i,int j){
		this->j=i;
		this->f=j;
		pri=i*1.0/j;
	}
	bool operator < (const data &t)const{
		return pri<t.pri;
	}
}ds[MAXN+3];
int n,m; 
bool input(){
	scanf("%d%d",&m,&n);
	if(m+n==-2)return false;
	int a,b;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		ds[i].cal(a,b);
	}
	sort(ds+1,ds+n+1);
	return true;
}
double solve(){
	double ans=0;
	for(int i=n;i>=1&&m>0;i--){
		if(m>=ds[i].f){
			m-=ds[i].f;ans+=ds[i].j;
		}
		else{
			ans+=m*1.0/ds[i].f*ds[i].j;//为什么ans+=m/ds[i].pri是错的 
			m=0;
		}
	}
	return ans;
}
int main(){
	while(input()){
		printf("%.3f\n",solve());
	}
	return 0;
}

