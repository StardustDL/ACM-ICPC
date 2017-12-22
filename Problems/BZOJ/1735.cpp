/*
[Usaco2005 jan]Muddy Fields 泥泞的牧场
分析：不能盖住好地，那么宽为1的木板只能放在行、列连通块里。而且联通块应尽可能得延伸。 （因为不能盖住好地，所以不能直接行列连边，要找联通块） 
		对于一个点必须被横竖木板之一覆盖，所以行、列连通块对应左、右部中的点，泥地对应边。
		求二分图最小覆盖就是答案。
		二分图最小点覆盖==最大匹配 
*/
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int R,C,n;
char s[50+3][50+3];
int match[1000+3],vis[1000+3];
vector<int> g[1000+3]; 
bool find(int x){
    for(int i=0;i<g[x].size();i++){
        if(vis[g[x][i]]) continue;
        vis[g[x][i]]=1;
        if(match[g[x][i]]==-1 || find(match[g[x][i]])){
        	match[g[x][i]]=x;
        	return 1;
		}
    }
    return 0;
}
int xn=0,yn=0;
int a[50+3][50+3],b[50+3][50+3];
int main(){
    memset(match,-1,sizeof(match));
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++)scanf("%s",s[i]);
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(s[i][j]=='*'){
                if(j>0&&s[i][j-1]=='*')a[i][j]=a[i][j-1];
                else a[i][j]=++yn;
                if(i>0&&s[i-1][j]=='*')b[i][j]=b[i-1][j];
                else b[i][j]=++xn;
            }
        }
    }
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            if(s[i][j]=='*')
				g[a[i][j]].push_back(b[i][j]);
    n=yn;
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(find(i)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
