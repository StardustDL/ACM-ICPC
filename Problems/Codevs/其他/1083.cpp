/*
Cantor±í
*/
#include<stdio.h>
int a[1000][1000],p,q,n;
void fill(int n){
	int x=1,y=1,s=1;
	bool b=true;
	a[x][y]=s;
	x=1;y=2;s=2;
	while(1){
		a[x][y]=s;
		if(s==n){
			p=x;q=y;
			return;
		}
		if(b){
			x++;y--;
			if(y==0)y=1,b=false;
		}
		else{
			y++;
			if(--x==0)x=1,b=true;
		}
		s++;
	}
}
int main(){
	scanf("%d",&n);
	fill(n);
	printf("%d/%d",p,q);
	return 0;
}
