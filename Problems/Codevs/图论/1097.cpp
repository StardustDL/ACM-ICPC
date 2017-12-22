/*
校门外的树
*/
#include<cstdio>
#include<bitset>
using namespace std;
int l,m;
bitset<10001> a;
int main(){
	scanf("%d %d",&l,&m);
	for(int i=0;i<=l;i++)a[i]=1;
	for(int i=1;i<=m;i++){
		int s,t;
		scanf("%d %d",&s,&t);
		for(int j=s;j<=t;j++)a[j]=0;
	}
	int sum=0;
	for(int i=0;i<=l;i++)sum+=a[i];
	printf("%d",sum);
	return 0;
}
