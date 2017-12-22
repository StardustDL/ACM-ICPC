/*
[CQOI2007]三角形tri
分析：对一个三角形，顺时针给边标号1，2，3
	  首先如果最后一位是4，那么直接把最后一位改成1，2，3输出即可
	  否则，可以发现它一定有一条边挨着和他同级的，最后一位为4的三角形 
	  	最后一位=？
		  1：边2挨着T..4  2：边1挨着T..1   3：边3挨着T..4 
	  向前枚举，剩下的相邻三角形一定是T....4的形式，考虑哪条边会挨着当前的三角形即可。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char ch[100];
int n,m,l;
bool f[5];
void out(int x,int d){
    for(int i=0;i<=x;i++)printf("%c",ch[i]);
    printf("%d\n",d);
}
int main(){
    scanf("%s",&ch);
    l=strlen(ch);l--;
	if(ch[l]=='4'){
		for(int i=1;i<=3;i++)out(l-1,i);
        return 0;
	}
	switch(ch[l]-'0'){
		case 1:f[1]=f[3]=1;break;
		case 2:f[2]=f[3]=1;break;
		case 3:f[1]=f[2]=1;break;
	}
	out(l-1,4);// 和l同级的三角形
	for(int i=l-1;i>=1;i--){
		switch(ch[i]-'0'){//和i同级的三角形 
			case 1:if(f[2]){out(i-1,4);f[2]=0;}break;
			case 2:if(f[1]){out(i-1,4);f[1]=0;}break;
			case 3:if(f[3]){out(i-1,4);f[3]=0;}break;
		}
	}
	return 0;
}
