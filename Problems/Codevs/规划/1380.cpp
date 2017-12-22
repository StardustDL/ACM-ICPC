/*
û����˾�����
��������������DP 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=6000;
vector<int> G[MAXN+3];//����
int n,h[MAXN+3],boss[MAXN+3]/*�ϰ�*/,f[MAXN+3][2];//f[i][1]��ʾ��iΪ����i��ϯ�����ֵ��f[i][0]��ʾ��iΪ����i����ϯ�����ֵ
void dfs(int k){
    for(int j=0;j<G[k].size();j++){
        int i=G[k][j];
        dfs(i);
        //����ϰ��ϯ����ô�������¾Ͳ���ϯ
        f[k][0]+=max(f[i][0],f[i][1]);
        f[k][1]+=f[i][0];
    }
    f[k][1]+=h[k];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    memset(boss,0,sizeof(boss));
    memset(f,0,sizeof(f));
    int x,y;
    while(scanf("%d%d",&x,&y)==2,x||y){
        G[y].push_back(x);
        boss[x]=y;
    }
    for(int i=1;i<=n;i++){
        if(boss[i]==0){//���ڵ�
            dfs(i);//����DP
            printf("%d",max(f[i][0],f[i][1]));
            break;
        }
    }
    return 0;
}
