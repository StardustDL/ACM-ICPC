/*
[Usaco2005 nov]Asteroids ��ԽС����Ⱥ
����������ͼ�����е�ֱ��ʾ�С��С�
		����һ����(x,y) �� x��y���ߡ�
		��С���Ǽ��Ǵ𰸡�
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=500,INF=0x3f3f3f3f;
int mp[MAXN+3][MAXN+3],match[MAXN+3],vis[MAXN+3];
int n,k;
bool augment(int x){
    for(int i=1;i<=n;i++){
        if(vis[i] || mp[x][i]==0)continue;
        vis[i]=1;
        if(match[i]==0 || augment(match[i])){
            match[i]=x;
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1,x,y;i<=k;i++){scanf("%d%d",&x,&y);mp[x][y]=1;}
    int ans=0;
    for(int i=1;i<=n;i++){memset(vis,0,sizeof(vis));if(augment(i))ans++;}
    printf("%d\n",ans); 
    return 0;
}
