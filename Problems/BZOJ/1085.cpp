/*
分析：A*，估价就是和终态有多少不同= = 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
const int ANS[5][5]={{1,1,1,1,1},{0,1,1,1,1},{0,0,2,1,1},{0,0,0,0,1},{0,0,0,0,0}};
const int dx[8]={1,1,-1,-1,2,2,-2,-2},dy[8]={2,-2,2,-2,1,-1,1,-1};
int mp[5][5],mxdep;
bool judge(){
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(mp[i][j]!=ANS[i][j])return false;
	return true;
}
int eva(){
	int ans=0;
	for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(mp[i][j]!=ANS[i][j])ans++;
	return ans;
}
bool dfs(int dep,int x,int y){
	if(dep==mxdep)return judge();
	for(int i=0;i<8;i++){
		int tx=x+dx[i],ty=y+dy[i];
		if(tx<0||ty<0||tx>=5||ty>=5)continue;
		swap(mp[x][y],mp[tx][ty]);
		if(eva()+dep<=mxdep && dfs(dep+1,tx,ty))return true;
		swap(mp[x][y],mp[tx][ty]);
	}
	return false;//注意返回= = 
}
char ch[10];
int main(){
	int T,x,y;scanf("%d",&T);
    while(T--){
        for(int i=0;i<5;i++){
            scanf("%s",ch);
            for(int j=0;j<5;j++){
                if(ch[j]=='*'){mp[i][j]=2;x=i;y=j;}
                else mp[i][j]=ch[j]-'0';
            }
        }
        //cout<<x<<" "<<y<<endl;
        for(mxdep=1;mxdep<=15;mxdep++){if(dfs(0,x,y)){printf("%d\n",mxdep);break;}}
        if(mxdep>15)printf("-1\n");
    }
	return 0;
}

