/*
[Usaco2007 Jan]Tallest Cow 最高的牛
分析：有点意思：先将所有高度置为H，对于一个关系(a,b)：
	  严格小于：相当于 区间(a,b)-1
	  对于两端点：注意端点可以相等，那相等一定更大。
	  所以求差分数组，使得区间减降为O(1) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
struct segment{
	int l,r;
	bool operator <(const segment &t)const{
		return l<t.l||l==t.l&&r<t.r;
	}
}ss[MAXN+3];
int c[MAXN+3],n,I,H,r; 
int main(){
	scanf("%d%d%d%d",&n,&I,&H,&r);
	for(int i=1;i<=r;i++){scanf("%d%d",&ss[i].l,&ss[i].r);if(ss[i].l>ss[i].r)swap(ss[i].l,ss[i].r);}
	sort(ss+1,ss+r+1);
	for(int i=1;i<=r;i++){
		if(ss[i].l==ss[i-1].l&&ss[i].r==ss[i-1].r)continue;
		c[ss[i].l+1]--,c[ss[i].r]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=c[i];
		printf("%d\n",sum+H);
	}
	return 0;
}

