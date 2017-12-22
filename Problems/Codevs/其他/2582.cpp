/*
Letters
分析：贪心，每个字母一定选择离它最近的相同字母换过来，然后就成了求逆序对了
	  重编号一下就好，这一步可以用26个队列 
	  这里说明一下树状数组求逆序对：每个数i对应到树状数组中第i个位置，从小到大枚举这个序列，设当前值为x，则ans+=sum(x)，相当于统计比x小的数在前i个数中有多少个，并将第x位置+1 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<stack>
#include<cstring>
#define lowbit(x) (x&-x)
using namespace std;
const int MAXN=1000000;
typedef char str[MAXN+3];
typedef long long LL;
struct BIT{
	LL d[MAXN+3],n;
	void init(int n){this->n=n;}
	void add(LL x,LL ad){
		while(x<=n){d[x]+=ad;x+=lowbit(x);}
	}
	LL sum(int x){
		int ans=0;
		while(x>0){ans+=d[x];x-=lowbit(x);}
		return ans;
	}
}bit;
int n;
stack<int> T[27+4];
str a,b;
int s[MAXN+3];
int main(){
	cin>>n>>a>>b;
	bit.init(n);
	for(int i=0;i<n;i++)T[a[i]-'A'].push(i);//相当于对每个字母挂一个邻接表，表中存着这个字母的出现位置（递增序） 
	for(int i=n-1;i>=0;i--){
		s[i]=T[b[i]-'A'].top();T[b[i]-'A'].pop();//选择离着最近的对应 
	}
	LL ans=0;
	for(int i=n-1;i>=0;i--){//树状数组求逆序对 
		ans+=bit.sum(s[i]+1);//因为字母是0..25，而树状数组0位置不能有值，所以+1 
		bit.add(s[i]+1,1LL);
	}
	cout<<ans;
	return 0;
}
