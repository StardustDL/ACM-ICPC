/*
��������
���⣺��k�����ӷ���һ�����ϣ�������Щλ�ÿ��Էţ���Щ�����ԣ����ж����ַ���ʹ��ÿ��ÿ��ֻ��һ�����ӡ�
������DFS���ɣ������ύ�˺ü�����ʾ������࣬��������ʵ��û�����⣬����Ϊʲô�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int num[9],number[9][9],n,k,cnt,put;;//num��¼ÿһ�еĿ�������number��¼ÿһ�п��е�������Щ 
char map[9];
bool vis[9];
void dfs(int cur){
    if(k==put){cnt++;return;}//����ҵ��ˣ���ȻҲ������k���������һ�е������ 
    if(cur==n||k-put>n-cur)return;//��������߽��ʣ�µ���������Ҫ���µ��� 
    if(!num[cur]){dfs(cur+1);return;}//���һ��Ϊ��
    for(int i=0;i<num[cur];i++){
        if(!vis[number[cur][i]]){
            put++;vis[number[cur][i]]=true;//��һ��
            dfs(cur+1);
            put--;vis[number[cur][i]]=false;//����
        }
    }
    dfs(cur+1); //��һ�в��ţ�ֱ��������һ�У�����ֻ����һ�Σ���Ȼ���ظ�  
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
                if(map[j]=='#')number[i][num[i]++]=j;//��¼ÿһ�еĸ��������ڵ����� 
        }
        put=0;cnt=0;
        dfs(0);
        printf("%d\n",cnt);
    }
}

