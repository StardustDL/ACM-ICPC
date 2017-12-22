/*
产生数
分析：首先由乘法原理，总个数=每一位可以变成的种数乘积
		而每一位可变成的种数，不能直接是题目中给出的，还可以间接变化
		所以要沿着变化的边（图论）DFS，回溯时求两者并集，
		这可以通过二进制实现，并且“每一位可以变成的种数”就是二进制中1的个数
注意：二进制技巧：
		取第i位（i从0计）：(t>>(i))&1
		计算含1个数： while(t>0){t&=(t-1);ans++;}//t&(t-1) ->清除最右边的1
		将第i位设为1：t|=1<<i;
		将第i位设为0：t&=1<<i;
*/
#include<iostream>
#include<cstring>
#include<bitset>
#include<vector>
using namespace std;
const int MAXK=16;
int k,x,y;
long long ans=1;
int a[10],cn[10];
bitset<10> hasdfs=0;
char n[31];
int geti(int t,int i){
	return (t>>(i))&1;
}
int get1cn(int t){
	int ans=0;
	while(t>0){
		t&=(t-1);
		ans++;
	}
	return ans;
}
void dfs(int e){
	if(hasdfs[e])return;
	hasdfs[e]=1;
	for(int i=0;i<=9;i++){
		if(i==e||geti(a[e],i)==0)continue;
		dfs(i);
		a[e]=a[e]|a[i];
	}
}
/*void out(int t){将一个数二进制输出 
	for(int i=0;i<=9;i++){
		cout<<geti(t,i);
	}
	cout<<endl;
}*/
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=0;i<=9;i++)a[i]|=1<<i;//每个数字都可以变为自己（即不变） 
	for(int i=1;i<=k;i++){
		cin>>x>>y;
		a[x]|=1<<y;
	}
	for(int i=0;i<=9;i++){
		dfs(i);
		cn[i]=get1cn(a[i]);
	}
	for(int i=0;i<strlen(n);i++){
		ans*=cn[n[i]-'0'];
	}
	cout<<ans;
	return 0;
}
