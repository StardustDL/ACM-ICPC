#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstring>
using namespace std;
typedef char str[100];
str first,middle;
int find(str a,int l,int r,char c){
	for(int i=l;i<=r;i++)
		if(a[i]==c)return i;
}
void build(int fl,int fr,int ml,int mr){
	if(fl>fr)return;
	char root=first[fl];
//	cout<<fl<<" "<<fr<<" "<<ml<<" "<<mr<<endl;
	if(fl<fr){
		int m=find(middle,ml,mr,root),len=m-ml;
		build(fl+1,fl+1+len-1,ml,m-1);
		build(fl+1+len-1+1,fr,m+1,mr);
	}
	//cout<<0<<endl;
	//printf("%c",root);
	putchar(root);
}
int main(){
	scanf("%s",first+1);
	scanf("%s",middle+1);
	int fr=strlen(first+1),mr=strlen(middle+1);
	//cout<<fr<<" "<<mr<<endl;
	build(1,fr,1,mr);
	return 0;
}