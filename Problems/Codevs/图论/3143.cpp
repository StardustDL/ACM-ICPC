/*
¶þ²æÊ÷µÄÐò±éÀú
*/
#include<stdio.h>
int a[30][3];
void xian(int k){
	printf("%d ",k);
	if(a[k][1]!=0)xian(a[k][1]);
	if(a[k][2]!=0)xian(a[k][2]);
}
void zhong(int k){
	if(a[k][1]!=0)zhong(a[k][1]);
	printf("%d ",k);
	if(a[k][2]!=0)zhong(a[k][2]);
}
void hou(int k){
	if(a[k][1]!=0)hou(a[k][1]);
	if(a[k][2]!=0)hou(a[k][2]);
	printf("%d ",k);
}
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i][1],&a[i][2]);
	xian(1);
	printf("\n");
	zhong(1);
	printf("\n");
	hou(1);
	return 0;
}
