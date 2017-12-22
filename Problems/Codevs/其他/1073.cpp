/*
¼Ò×å
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=5000;
const char *tr="Yes",*fa="No";
typedef int arr[MAXN+3];
arr pa;
int n,m,p,t1,t2;
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]);
}
void init(){
	for(int i=1;i<=n;i++)pa[i]=i;
}
int main(){
	cin>>n>>m>>p;
	init();
	int a,b;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		t1=find(a);t2=find(b);
		if(t1!=t2)pa[t1]=t2;
	}
	for(int i=1;i<=p;i++){
		cin>>a>>b;
		if(find(a)==find(b))cout<<tr<<endl;
		else cout<<fa<<endl;
	}
	return 0;
}
