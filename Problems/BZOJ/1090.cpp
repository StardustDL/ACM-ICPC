/*
[SCOI2003]字符串折叠
分析：dp(i,j)表示[i..j]的最优解，
		三种转移：
			j-i+1
			dp(i,k)+dp(k+1,j)
			dp(i,k)+2+calc(t) if [k+1..j]=t([i..k])
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=100;
char s[MAXN+3];
int f[MAXN+3][MAXN+3];
bool mark[MAXN+3][MAXN+3];
bool check(int l,int r,int cl,int cr){
    if((r-l+1)%(cr-cl+1)!=0)return 0;
    for(int i=l;i<=r;i++)if(s[i]!=s[(i-l)%(cr-cl+1)+cl])return 0;
    return 1;
}
int calc(int x){int t=0;while(x){x/=10;t++;}return t;}
int dp(int l,int r){
    if(l==r)return 1;
    if(mark[l][r])return f[l][r];
    mark[l][r]=1;
    int t=r-l+1;
    for(int i=l;i<r;i++){
        t=min(t,dp(l,i)+dp(i+1,r));
        if(check(i+1,r,l,i))t=min(t,dp(l,i)+2+calc((r-i)/(i-l+1)+1));
    }
    return f[l][r]=t;
}
int main(){
    scanf("%s",s+1);
    printf("%d",dp(1,strlen(s+1)));
    return 0;
}
