/*
Comrade ͬ־
*/
#include<stdio.h>
#include<ctype.h>
using namespace std;
int n,i,j,s=0;
char k,a[10001];
int main(){
	scanf("%c",&k);
	if(!isupper(k)){
		printf("I do not like lowercase letters!");
		return 0;
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%c",&a[i]);
		if(a[i]==k)s++;
	}
	printf("%d",s);
	return 0;
}
