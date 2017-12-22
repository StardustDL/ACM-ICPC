/*
Prime Ring Problem
题意：素数环 
分析：素数表+DFS，输出都要加空行，PE了好久。。。 
*/
#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
const int MAXN=17*2+3;
int n,a[19];
bitset<MAXN+3> isp;
bitset<19> used=0;
void loadpris(){
	isp=0;
	for(int i=2;i<=MAXN;i++)if(!isp[i])for(int j=i*i;j<=MAXN;j+=i)isp[j]=1;
}
void print(){
	printf("%d",a[1]);
	for(int i=2;i<=n;i++)printf(" %d",a[i]);
	puts("");
}
void dfs(int ind){
	if(ind>n){
		if(!isp[a[ind-1]+a[1]])print();
		return;
	}
	for(int i=1;i<=n;i++){
		if((!used[i]) && (!isp[i+a[ind-1]])){
			a[ind]=i;
			used[i]=1;
			dfs(ind+1);
			used[i]=0;
		}
	}
}
int main(){
	loadpris();int kase=0;
	while(cin>>n){
		printf("Case %d:\n",++kase);
		used=0;
		a[1]=1;used[1]=1;
		dfs(2);
		puts("");
	}
	return 0;
}
