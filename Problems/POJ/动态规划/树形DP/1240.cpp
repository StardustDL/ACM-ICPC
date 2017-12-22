/*
Pre-Post-erous!
���⣺����һ��k������ǰ��ͺ���������У������k����һ�������ж����� 
��������ÿ���ڵ㺢�ӽڵ�ĸ���n��Ȼ���m��λ����ѡn��λ�ø���n�����ӣ�һ����c(m ,n )��ѡ���������нڵ�����ֵ��˼���
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

