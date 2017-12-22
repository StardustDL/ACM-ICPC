/*
棋盘问题
题意：求k个棋子放在一盘棋上，其中有些位置可以放，有些不可以；问有多少种方法使得每行每列只有一个棋子。
分析：DFS即可，但是提交了好几回提示输出过多，但程序其实并没有问题，这是为什么？ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int num[9],number[9][9],n,k,cnt,put;;//num记录每一行的可行数，number记录每一行可行的列是哪些 
char map[9];
bool vis[9];
void dfs(int cur){
    if(k==put){cnt++;return;}//如果找到了（当然也包括第k个放在最后一行的情况） 
    if(cur==n||k-put>n-cur)return;//如果超出边界或剩下的行数比需要放下的少 
    if(!num[cur]){dfs(cur+1);return;}//如果一行为空
    for(int i=0;i<num[cur];i++){
        if(!vis[number[cur][i]]){
            put++;vis[number[cur][i]]=true;//放一个
            dfs(cur+1);
            put--;vis[number[cur][i]]=false;//不放
        }
    }
    dfs(cur+1); //这一行不放，直接搜索下一行，但是只能搜一次，不然会重复  
}
int main(){
	while(~scanf("%d%d%*c",&n,&k)){
        if(n==-1&&k==-1)break;
        memset(num,0,sizeof(number));
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%s",map);
            for(int j=0;j<n;j++)
                if(map[j]=='#')number[i][num[i]++]=j;//记录每一行的个数与所在的列数 
        }
        put=0;cnt=0;
        dfs(0);
        printf("%d\n",cnt);
    }
}

