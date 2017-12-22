/*
Washing Clothes
题意：两个人洗衣服， 每种颜色的衣服有多件， 要求两人只能同时洗相同颜色的衣服， 求洗衣服的最短时间。
分析：因为只能同时洗相同颜色的衣服， 因此可将不同颜色的衣服看为不同的组， 分别求出来每组的最短时间， 其和即为所求；每组最短时间就是0 1背包；对于每种颜色洗它都有一个总时间，要求洗这种颜色的最少时间，就是求看能不能一个人洗这种颜色的衣服达到总时间的一半，也就是让两个人洗这种颜色的衣服的时间尽可能相同。
	  先求出洗每种颜色的衣服所用的总时间，为了让两个人所用时间尽可能相同，把总时间的一半当做背包容量，每件衣服所花费的时间既是物体体积，又是物品价值，这样就转化为01背包，求背包的最大价值，然后用这种颜色的总时间减去最大价值就是洗这种颜色的衣服所用的最短时间。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<map>
#include<vector>
#include<string>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000/2;
map<string,int> mp;
struct data{
	int sum;
	vector<int> thing;
}ds[13];
int n,m,opt[MAXN+3];
bool input(){
	cin>>m>>n;
	if(m+n==0)return false;
	string tmp; 
	for(int i=1;i<=m;i++){
		cin>>tmp;
		mp[tmp]=i; 
		ds[i].thing.clear(),ds[i].sum=0;
	}
	for(int i=1,t;i<=n;i++){
		cin>>t>>tmp;
		ds[mp[tmp]].thing.push_back(t);
		ds[mp[tmp]].sum+=t;
	}
	return true;
}
int solve(){
	int ans=0;
	for(int i=1;i<=m;i++){
		memset(opt,0,sizeof(opt));
		for(int j=0;j<ds[i].thing.size();j++){
			for(int k=ds[i].sum/2;k>=ds[i].thing[j];k--){
				opt[k]=max(opt[k-ds[i].thing[j]]+ds[i].thing[j],opt[k]);
			}
		}
		ans+=ds[i].sum-opt[ds[i].sum/2];
	}
	return ans;
}
int main(){
	while(input()){
		printf("%d\n",solve());
	}
	return 0;
}

