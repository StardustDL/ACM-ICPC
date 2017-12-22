/*
砝码称重 2
分析：可以二分搜索，但由于数据并不太大，也可以加一大堆剪枝AC
	  剪枝如下：先对所有数从大到小排序，这样先选大的，更好的减小搜索范围，
	  	然后生成后缀和，搜索中如果将当前数之后的所有数都选还不足以达到m，剪枝
		如果当前答案差于最优解，剪枝
		如果选择此物品，使得总和超过m，剪枝 
*/ 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=30; 
int n,m,ans,a[MAXN+3],s[MAXN+3];
bitset<MAXN+3> used;
void dfs(int cur,int d,int pos){
	if(d>=ans)return;
	if(cur==0){ans=min(ans,d);return;}
	for(int i=pos;i<=n;i++){
		if(cur-a[i]>=0){
			if(cur-s[i]>0)return;
			dfs(cur-a[i],d+1,i+1);
		}
	}
}
bool cmp(int x,int y){return x>y;}
int main(){
	cin>>n>>m;ans=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--)s[i]=s[i+1]+a[i];
	dfs(m,0,1);
	cout<<ans;
	return 0; 
}
