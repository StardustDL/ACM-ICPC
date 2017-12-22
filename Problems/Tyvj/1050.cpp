#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000;
int f[MAXN+3][MAXN+3];
char a[MAXN+3],b[MAXN+3];
int get(int x,int y){
	if(x==-1||y==-1)return 0;
	else return f[x][y];
}
int main(){
	cin>>a>>b;
	memset(f,0,sizeof(f));
	int la=strlen(a),lb=strlen(b),ln=max(la,lb);
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			if(a[i]==b[j])f[i][j]=get(i-1,j-1)+1;
			else f[i][j]=max(get(i-1,j),get(i,j-1));
		}
	}
	cout<<f[la-1][lb-1];
	return 0;
}
