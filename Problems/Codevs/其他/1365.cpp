/*
Ô¡»ğÒøºÓĞÇ¼ÊÌøÔ¾
*/
#include<iostream>
using namespace std;
const int MAXN=20000;
int pa[MAXN+3];
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
void unions(int a,int b){
	a=find(a),b=find(b);
	if(a!=b)pa[a]=b;
}
bool same(int a,int b){
	return find(a)==find(b);
}
int main(){
	int n,a,b,m,x;
	cin>>x>>n>>m;
	while(n-->0){
		cin>>a>>b;unions(a,b);
	}
	while(m-->0){
		cin>>a>>b;
		if(same(a,b))cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
} 
