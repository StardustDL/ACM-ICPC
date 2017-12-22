/*
Letters
分析：贪心，每个字母一定选择离它最近的相同字母换过来，然后就成了求逆序对了
	  重编号一下就好，这一步可以用26个队列 
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
	void init(int n){
		//memset(d,0,sizeof(d));
		this->n=n;
	}
	
	void add(LL x,LL ad){
		while(x<=n){
			d[x]+=ad;x+=lowbit(x);
		}
	}
	LL sum(int x){
		int ans=0;
		while(x>0){
			ans+=d[x];x-=lowbit(x);
		}
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
	for(int i=0;i<n;i++)T[a[i]-'A'].push(i);
	for(int i=n-1;i>=0;i--){
		s[i]=T[b[i]-'A'].top();T[b[i]-'A'].pop();
	}
	LL ans=0;
	//for(int i=0;i<n;i++)cout<<s[i]<<" ";
	for(int i=n-1;i>=0;i--){
		ans+=bit.sum(s[i]+1);
		bit.add(s[i]+1,1LL);
	}
	cout<<ans;
	return 0;
}
