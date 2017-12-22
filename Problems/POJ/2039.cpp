/*
To and Fro
分析：简单的转成题中矩阵，行列反着输出 
*/
#include <iostream>
#include <cstring>
using namespace std;
int n;
char s[503],map[503][503];
int main(){
	while(scanf("%d",&n),n){
		scanf("%s",s);
		int len=strlen(s),k=0,flag=0;
		while(k<len){
			for(int i=0;i<n;i++)map[flag][i]=s[k++];
			flag++;
			if(k==len)break;
			for(int j=n-1;j>=0;j--)map[flag][j]=s[k++];
			flag++;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<flag;j++)
				putchar(map[j][i]);
		puts("");
	}
	return 0;
}

