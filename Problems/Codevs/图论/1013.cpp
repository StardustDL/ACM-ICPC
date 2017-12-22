/*
求先序排列
分析：DFS，先根据后序找到根，再由中序找到左右子树。 
*/
#include<iostream>
#include<cstring> 
using namespace std;
char str[2][11];
void dfs(int zl,int zr,int hl,int hr){
	if(zl>zr||hl>hr)return; 
	char root=str[1][hr];
	cout<<root;
	int i=zl;
	while(i<=zr && str[0][i]!=root)i++;
	dfs(zl,i-1,hl,(hl-1)+i-zl);
	dfs(i+1,zr,(hl-1)+i-zl +1 ,hr-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>str[0]>>str[1];
	dfs(0,strlen(str[0])-1,0,strlen(str[1])-1); 
	return 0;
}
