/*
[SDOI2011]打地鼠
分析：数据小，枚举长宽，暴力判断 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,sum,mp[101][101],t[101][101],ans=0x3f3f3f3f;
bool check(int x,int y){
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)t[i][j]=mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
	    	if(!t[i][j])continue;
	    	if(i+x-1<=n&&j+y-1<=m){
	        	int tmp=t[i][j];
                for(int k=0;k<x;k++)
                   for(int l=0;l<y;l++)
                       if((t[i+k][j+l]-=tmp)<0)return false;
            }
            else return false;
        }
    return true;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=m;j++){
       	   scanf("%d",&mp[i][j]);
       	   sum+=mp[i][j];
       }
    for(int i=n;i;i--)
       for(int j=m;j;j--)
       	   if(sum%(i*j)==0&&sum/(i*j)<ans&&check(i,j))
       	      ans=sum/(i*j);
    printf("%d\n",ans);
	return 0;
}

