/*
ÉßÐÎ¾ØÕó
*/
#include<stdio.h>
int main()
{
	int n,x,y,i,p,h=1,k=1,a[101][101];
	scanf("%d",&n);
	x=(n+1)/2;y=x;
	a[x][y]=1;
	while(k<=n*n){
		for(i=1;i<=h;i++)a[x][++y]=++k;
		if(k>n*n)break;
		for(i=1;i<=h;i++)a[--x][y]=++k;
		h++;
		for(i=1;i<=h;i++)a[x][--y]=++k;
		for(i=1;i<=h;i++)a[++x][y]=++k;
		h++;
	}
	for(x=1;x<=n;x++){
		for(y=1;y<=n;y++)printf("%d ",a[x][y]);
		printf("\n");
	}
	h=0;
	for(i=1;i<=n;i++){
		h+=a[i][i];
		h+=a[i][n-i+1];
	}
	h-=a[(n+1)/2][(n+1)/2];
	printf("%d",h);
	return 0;
}
