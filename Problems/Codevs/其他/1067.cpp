/*
ЛњЦїЗ­вы
*/
#include<stdio.h>
int sa[101],k=0,m = 0,s=0;
bool isin(int n){
	for(int i=1;i<=m;i++)if(sa[i]==n)return true;
	return false;
}
void add(int n){
	s++;k++;sa[k]=n;
	if(k==m)k=0;
}
int main(){
	int n,i,l;
	scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)sa[i]=-1;
	for(i=1;i<=n;i++){
		scanf("%d",&l);
		if(!isin(l))add(l);
	}
	printf("%d",s);
	return 0;
}
