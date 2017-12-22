/*
生日礼物
题意：得到一个最小的K，使得可以叠出m种，每种k张的蝴蝶。
分析：枚举K，验证对于当前的K能否买到一种合适的方案，验证用DFS即可，但注意几点：
		1.先生成出每种本子的个数，再计算验证 
		2.加入剪枝：预处理出每种本子中最多的纸张有多少，DFS中先判断有没有可能超出K这个界限。
		3.DFS有另外一种写法：实时计算每种纸张的张数，这样会带来性能损失，但也能有更强的剪枝
			每次比较当前张数和K，一但超出，就跳出循环。但目前无法确定这两种方法的复杂度区别。
备注：先写的方法2，然后没调过，于是改成了方法1，交了之后超时，于是加了剪枝
2015.2.20 30min 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=13;
typedef int sta[MAXN];
int n,m,a[MAXN][MAXN],b[MAXN],k;
bool flag;
sta T,S;
void dfs(int ind){
	if(ind>n){
		memset(S,0,sizeof(S));
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				S[j]+=T[i]*a[i][j];
			}
			if(S[j]!=k)return;
		}
		flag=true;return;
	}
	for(int i=0;i<=b[ind];i++){
		if(flag)return;
		if(i*a[ind][12]>k)break;
		T[ind]=i;
		dfs(ind+1);
	}
} 
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int &t=a[i][12];
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			t=max(t,a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)cin>>b[i];
	for(k=1;m*k<=1000;k++){
		memset(T,0,sizeof(T));
		dfs(1);
		if(flag){
			cout<<k*m<<endl;
			return 0;
		}
	}
	cout<<"alternative!";
	return 0;
} 
