/*
¼ÆËãÆ÷
*/
#include<stdio.h>
int main(){
	int n,b,s,i,k;
	char c;
	scanf("%d%d",&n,&b);
	s = b;
	for (i=1;i<=n;i++){
		scanf("\n%c",&c);
		scanf("%d",&k);
		switch(c){
			case '+':s+=k;break;
			case '-':s-=k;break;
			case '*':s*=k;break;
			case '/':
				if(k!=0)s/=k;
				else{
					printf("Error!");return 0;
				}
				break;
			case '%':
				if(k!=0)s%=k;
				else{
					printf("Error!");return 0;
				}
				break;
		}
	}
    printf("%d",s);
	return 0;
}
