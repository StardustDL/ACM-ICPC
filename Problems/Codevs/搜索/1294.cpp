/*
全排列
分析：先想的是用库函数，然后超时1个点
	for(int i=1;i<=n;i++)a[i]=i;
	do{
		output();
	}while(next_permutation(a+1,a+n+1)); 
	于是老老实实DFS，但也是超时，于是放弃cout，AC 
*/
#include<algorithm>
#include<cstdio>
#include<bitset>
using namespace std;
int a[11],n;
bitset<11> used;
void output(){
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
}
void dfs(int id){
	for(int i=1;i<=n;i++)if(!used[i]){
		a[id]=i;
		if(id==n)output();
		else {
			used[i]=1;dfs(id+1);used[i]=0;
		}
	}
}
int main(){
	//ios::sync_with_stdio(false);
	scanf("%d",&n);
	used=0;
	dfs(1);
	return 0;
} 
