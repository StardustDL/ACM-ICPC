/*
Function Run Fun
题意：定义了一个函数，求函数值
分析：由于限制在(20,20,20)，打个表即可 
*/
#include<iostream>
using namespace std;
const int size = 21;
int map[size][size][size];
void makeMap(){
	for(int a=0;a<size;a++)
		for(int b=0;b<size;b++)
			for(int c=0;c<size;c++){
				if(a<=0||b<=0||c<=0)map[a][b][c]=1;
				else if(a<b&&b<c)map[a][b][c]=map[a][b][c-1]+map[a][b-1][c-1]-map[a][b-1][c];
				else map[a][b][c]=map[a-1][b][c]+map[a-1][b-1][c]+map[a-1][b][c-1]-map[a-1][b-1][c-1];
			}
}
int main(){
	int a,b,c,ans;
	makeMap();
	while(scanf("%d %d %d",&a,&b,&c),!(a==-1&&b==-1&&c==-1)){
		if(a<0||b<0||c<0)ans=1;
		else if(a>20||b>20||c>20)ans=map[20][20][20];
		else ans=map[a][b][c];
        printf("w(%d, %d, %d) = %d\n",a,b,c,ans);
	}
	return 0;
}
