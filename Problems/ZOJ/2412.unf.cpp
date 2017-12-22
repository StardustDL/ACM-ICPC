#include<iostream>
using namespace std;
const int MAXN=50;
int mp[3*MAXN+3][3*MAXN+3],m,n;
bool read(){
	cin>>m>>n;
	if(m<0||n<0)return false;
	char c;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			switch(c){
				case 'A':
					mp[i+1][j]=mp[i][j+1]=mp[i+1][j+1]=1;break;
				case 'B':
					mp[i+1][j+2]=mp[i][j+1]=mp[i+1][j+1]=1;break;
				case 'C':
					mp[i+1][j]=mp[i+2][j+1]=mp[i+1][j+1]=1;break;
				case 'D':
					mp[i+1][j+2]=mp[i+2][j+1]=mp[i+1][j+1]=1;break;
				case 'E':
					mp[i][j+1]=mp[i+1][j+1]=mp[i+2][j+1]=1;break;
				case 'F':
					mp[i+1][j]=mp[i+1][j+1]=mp[i+1][j+2]=1;break;
				case 'G':
					mp[i+1][j]=mp[i][j+1]=mp[i+1][j+1]=mp[i+1][j+2]=1;break;
				case 'H':
					mp[i+1][j]=mp[i][j+1]=mp[i+1][j+1]=mp[i+2][j+1]=1;break;
				case 'I':
					mp[i+1][j]=mp[i+1][j+1]=mp[i+1][j+2]=mp[i+2][j+1]=1;break;
				case 'J':
					mp[i][j+1]=mp[i+1][j+1]=mp[i+2][j+1]=mp[i+1][j+2]=1;break;
				case 'K':
					mp[i][j+1]=mp[i+1][j+1]=mp[i+2][j+1]=mp[i+1][j+2]=mp[i+1][j]=1;break;
			}
		}
	}
	return true;
}
void dfs(int i,int j){
	if(i<1||j<1||i>m||j>n||!mp[i][j])return;
	mp[i][j]=0;
	dfs(i+1,j);dfs(i-1,j);dfs(i,j+1);dfs(i,j-1);
}
int solve(){
	int ans=0;
	for(int i=1;i<=3*m;i++){
		for(int j=1;j<=3*n;j++){
			if(mp[i][j]){
				ans++;
				dfs(i,j);
			}
		}
	}
	return ans;
}
int main(){
	while(read()){
		cout<<solve()<<endl;
	}
	return 0;
}
