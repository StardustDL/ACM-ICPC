/*
Color Me Less
题意：给16个底色，后给若干个颜色问与前面哪个距离最小？
分析：暴力 
*/
#include<iostream>
#include<cmath>
using namespace std;
typedef struct fun{int x,y,z;}rr;
fun a[17];
int x,y,z,k; 
int main(){
	for(int i=0;i<16;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	while(scanf("%d%d%d",&x,&y,&z),!(x==-1&&y==-1&&z==-1)){
		int sum=INT_MAX;
		for(int i=0;i<16;i++){
			int j=(x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y)+(z-a[i].z)*(z-a[i].z);
			if(j<sum){sum=j;k=i;}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n",x,y,z,a[k].x,a[k].y,a[k].z);
	}
	return 0;
}
