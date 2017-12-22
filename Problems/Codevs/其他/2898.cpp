/*
卢斯的进位制  
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=30,INF=0x3f3f3f3f;
int n;
char str[MAXN+3]; 
int main(){
	scanf("%d\n",&n);
	//getchar();
	gets(str);
	for(int i=1,a,len;i<n;i++){
		gets(str);a=0;len=strlen(str);
		str[len]=' ';
		for(int j=0,l=0;j<=len;j++){
			if(str[j]==' '){
				if(j-l==2)a++;
				l=j+1;
			}
		}
		printf("%c=%d ",str[0],a);
	}
	printf("\n%d\n",n-1);
	return 0;
}

