/*
[cqoi2013]二进制a+b
分析：DP
		f[i][a][b][c][j]
		当前枚举到(二进制下的)第i位，a' b' c'各用a,b,c了几个1，j表示最后一位是否有进位
		这时的最小答案 
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL f[40][40][40][40][2];
bool vis[40][40][40];
int L,len[10];
int getlen(LL k){
    int tmp=0,num=0;
    while(k){
        if(k&1)num++;
        k=k>>1;
        tmp++;
    }
    L=max(L,tmp);
    return num;
}
void update(LL& a,LL b){
    if(a==-1) a=b;else a=min(a,b);
}
void getf0(int l,int a,int b,int c){
    if(f[l][a][b][c][0]==-1) return;
    update(f[l+1][a+1][b][c+1][0],f[l][a][b][c][0]+(1<<l));
    update(f[l+1][a][b+1][c+1][0],f[l][a][b][c][0]+(1<<l));
    update(f[l+1][a][b][c][0],f[l][a][b][c][0]);
    update(f[l+1][a+1][b+1][c][1],f[l][a][b][c][0]+(1<<(l+1)));
}
void getf1(int l,int a,int b,int c){
    if(f[l][a][b][c][1]==-1) return;
    update(f[l+1][a+1][b][c][1],f[l][a][b][c][1]+(1<<(l)));
    update(f[l+1][a][b+1][c][1],f[l][a][b][c][1]+(1<<(l)));
    update(f[l+1][a][b][c+1][0],f[l][a][b][c][1]);
    update(f[l+1][a+1][b+1][c+1][1],f[l][a][b][c][1]+(1<<(l+1)));
}
int main(){
    LL a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    len[1]=getlen(a);len[2]=getlen(b);len[3]=getlen(c);
    memset(f,-1,sizeof(f));
    f[0][0][0][0][0]=0;
    for(int i=0;i<=L;i++)
        for(int j=0;j<=min(len[1],i);j++)
            for(int k=0;k<=min(len[2],i);k++)
                for(int l=0;l<=min(len[3],i);l++)
                    getf0(i,j,k,l),getf1(i,j,k,l);
    printf("%lld\n",f[L][len[1]][len[2]][len[3]][0]);
    return 0;
}
