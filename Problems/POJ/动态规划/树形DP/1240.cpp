/*
Pre-Post-erous!
题意：给定一颗k叉树的前序和后序遍历序列，求这个k叉树一共可能有多少种 
分析：求每个节点孩子节点的个数n，然后从m个位置中选n个位置给这n个孩子，一共有c(m ,n )中选法，把所有节点的这个值相乘即可
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=26;
int countv[MAXN+1],m;
char pre[MAXN+1],post[MAXN+1];
int getC(int n, int m){
    return (m==0||n==m)?1:getC(n-1,m-1)+getC(n-1,m);
}
int solve(){
    int res=1;
    for(int i=0;post[i];i++)
        res*=getC(m,countv[i]);
    return res;
}
void countSons(int curPre,int curPost,int endPre){
    if(curPre==endPre)return;
    int pPre=curPre+1,pPost;
    char c;
    while(pPre<=endPre){
        c=pre[pPre];
        countv[curPre]++;
        pPost=curPost;
        while(post[pPost]!=c)pPost++;
        countSons(pPre,curPost,pPre+(pPost-curPost));
        pPre=pPre+(pPost-curPost)+1;
        curPost=pPost+1;
    }
}
int main(){
    while(scanf("%d",&m),m){
        scanf("%s%s",pre,post);
        memset(countv,0,sizeof(countv));
        countSons(0,0,strlen(pre)-1);
        printf("%d\n",solve());
    }
    return 0;
}

