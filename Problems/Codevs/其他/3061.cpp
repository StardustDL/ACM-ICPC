/*
º∆À„
*/
#include<stdio.h>
int main(){
	int a,b;
	char c;
	scanf("%d%d",&a,&b);
	scanf("\n%c",&c);
	switch(c){
		case '+':printf("%d",a+b);break;
		case '-':printf("%d",a-b);break;
		case '*':printf("%d",a*b);break;
		case '/':printf("%d",a/b);break;
	}
	return 0;
}
