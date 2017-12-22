/*
大批整数排序
*/
#include<cstdio>
int a[11],n;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a[0]);a[a[0]]++;
	}
	for(int i=1;i<=10;i++)
		for(int j=1;j<=a[i];j++)printf("%d\n",i);
	return 0;
}
