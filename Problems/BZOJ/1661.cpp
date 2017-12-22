/*
[Usaco2006 Nov]Big Square 巨大正方形
分析：暴力 ，枚举两个点，以这两点为正方形的一条边，可求出另两个点（注意有两种方法，分别在两侧），验证另两个点 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100*2,INF=0x3f3f3f3f;//没有判超过n，所以开两倍 
int mp[MAXN+3][MAXN+3],n,ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
        	char ch=getchar();while(ch!='J'&&ch!='B'&&ch!='*')ch=getchar();
        	if(ch=='J') mp[i][j]=2;
        	else if(ch=='*') mp[i][j]=1;
    }

    for(int x=1;x<=n;x++){//枚举一个点 
		for(int y=1;y<=n;y++){
			if(mp[x][y]!=2)continue;
        	for(int i=1;i<=n;i++){ 
				for(int j=1;j<=n;j++){//枚举另一个点，注意可以是已经放了J，也可以是没放牛，因为 Bessie不是必须参与作为正方形的四个顶点之一
					if(x==i&&y==j || mp[i][j]==0)continue; 
            		int l=i-x,r=j-y;
					if(l*l+r*r<ans) continue;
					if(i-r>=0 && j+l>=0 && x-r>=0 && y+l>=0 && mp[i-r][j+l]==2 && mp[x-r][y+l]==2)ans=l*l+r*r;
					if(i+r>=0 && j-l>=0 && x+r>=0 && y-l>=0 && mp[i+r][j-l]==2 && mp[x+r][y-l]==2)ans=l*l+r*r;
				}
			}
		}
	}
	printf("%d\n",ans);
    return 0;
}
