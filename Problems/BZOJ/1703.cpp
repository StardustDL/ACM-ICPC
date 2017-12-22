/*
[Usaco2007 Mar]Ranking the Cows ��ţ����
������bitset���ݱհ�����Ϊ�����Եĸ�����
		���������Եĸ�����ô���أ�
		�ݳ�ԭ�����е�Ը�����ȥ�����Եĸ�����Ϊ�𰸡�
		��ôά�������Ը�����?bitset���ݱհ����ɡ� 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=1000;
bitset<MAXN+3> b[MAXN+3];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int x,y;m;m--){
        scanf("%d%d",&x,&y);
        b[x][y]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)if(b[i][k])b[i]|=b[k];
    int ans=0;
    for(int i=1;i<=n;i++)ans+=b[i].count();
    printf("%d\n",(n*(n-1)/2)-ans);
    return 0;
}

