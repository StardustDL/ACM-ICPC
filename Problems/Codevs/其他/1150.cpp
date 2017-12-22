/*
多项式输出
分析：细节不少，WA了好几次，还是要细致 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,a[MAXN+3]; 
int main(){
	cin>>n;
	for(int i=0;i<=n;i++)cin>>a[n-i];
	for(int i=n;i>1;i--){
		if(a[i]==0)continue;
		if(a[i]<0)putchar('-');
		if(i!=n&&a[i]>0)putchar('+');
		if(abs(a[i])!=1)printf("%d",abs(a[i]));
		printf("x^%d",i);
	}
	if(a[1]){
		putchar(a[1]<0?'-':'+');
		if(abs(a[1])!=1)printf("%d",abs(a[1]));
		putchar('x');
	}
	if(a[0])printf("%c%d",a[0]>0?'+':'-',abs(a[0]));
	return 0;
}

