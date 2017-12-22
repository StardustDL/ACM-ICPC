/*
[Usaco2005 jan]Muddy Fields ��Ţ������
���������ܸ�ס�õأ���ô��Ϊ1��ľ��ֻ�ܷ����С�����ͨ���������ͨ��Ӧ�����ܵ����졣 ����Ϊ���ܸ�ס�õأ����Բ���ֱ���������ߣ�Ҫ����ͨ�飩 
		����һ������뱻����ľ��֮һ���ǣ������С�����ͨ���Ӧ���Ҳ��еĵ㣬��ض�Ӧ�ߡ�
		�����ͼ��С���Ǿ��Ǵ𰸡�
		����ͼ��С�㸲��==���ƥ�� 
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
