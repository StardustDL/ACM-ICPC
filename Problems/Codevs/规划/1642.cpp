/*
矩形
分析：题意很简单，但思路很有特点 
	  先按列预处理出连续白块个数，然后逐行逐列计算
	  opt[i][j]表示每一个位置以[i][j]为右下角的矩形个数
	  枚举j之前的列，如果之前列的白块个数大于等于当前的（设为cnt），那么就又可以有cnt个矩形
	  当出现小于的情况，就将那个位置的答案加到opt[i][j]上，所有位置的opt[i][j]之和即为答案 
*/
#include<iostream>
using namespace std;
const int MAXN=150;
int n,mp[MAXN+3][MAXN+3],up[MAXN+3][MAXN+3],opt[MAXN+3][MAXN+3];
void input(){
	char ch;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ch;
			switch(ch){
				case 'W':mp[i][j]=1;break;
				case 'B':mp[i][j]=0;break;
			}
		}
	}
}
void init(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mp[i][j])up[i][j]=up[i-1][j]+1;
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!mp[i][j])continue;
			int cnt=opt[i][j]=up[i][j],t=j-1;
			while(mp[i][t]&&up[i][t]>=cnt){
				opt[i][j]+=cnt;t--;
			}
			opt[i][j]+=opt[i][t];
			ans+=opt[i][j];
		}
	}
	return ans;
}
int main(){
	input();init();
	cout<<solve();
	return 0;
}
