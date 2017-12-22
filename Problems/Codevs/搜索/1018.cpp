/*
单词接龙
题意：每个单词最多用两次，不允许包含，相邻问能形成的最大长度。 
分析：先预处理出每两个字符串的重合部分，注意要使重合部分尽量小，然后DFS即可 
*/
#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=23;
char str[MAXN][255];
int f[MAXN][MAXN],n,vis[MAXN],res=0,len[MAXN];

void dfs(int x,int ans){
	if(ans>res)res=ans; 
	for(int i=1;i<=n;i++){
		if(vis[i]<2&&f[x][i]!=-1){
			vis[i]++;
			dfs(i,ans+len[i]-f[x][i]);
			vis[i]--;
		}
	}
}
bool cmp(char* s1,char* s2,int p){
	int k=0;
	while(k<strlen(s2)&&p<strlen(s1)){
		 if(s1[p]!=s2[k])return false;
		 p++,k++;
	} 
	return true;
}
void init(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i];
		len[i]=strlen(str[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int p=len[i]-1;
			while(!cmp(str[i],str[j],p) && p>=0)p--;
			/*if(p==0)f[i][j]=-1;
			else */if(p>=0){
				f[i][j]=len[i]-p;
			}
			else f[i][j]=-1;
		}
	}
} 
int main(){
	ios::sync_with_stdio(false);
	init();
	char c;
	cin>>c;
	//cout<<f[1][1]<<endl;
	for(int i=1;i<=n;i++){
		if(str[i][0]==c){
			vis[i]=1;
			dfs(i,len[i]);
		}
	}
	cout<<res;
	return 0;
}
