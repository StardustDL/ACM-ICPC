/*
º£Õ½
*/
#include<iostream>
#include<cstdio>
using namespace std;
int r,c,ans=0,map[1002][1002];
int main(){
	scanf("%d %d",&r,&c);
	char d;
	for(int i=1;i<=r;i++){
		scanf("\n");
		for(int j=1;j<=c;j++){
			scanf("%c",&d);
			if(d=='.')map[i][j]=0;
			else map[i][j]=1;
		}
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(map[i][j]==0)continue;
			int p=i+1,q=j+1;
			while((q<=c)&&(map[i][q]==1))q++;
			q--;
			while((p<=r)&&(map[p][j]==1)&&(map[p][j-1]==0)&&(map[p][q+1]==0))p++;//check left right
			p--;
			for(int k=j;k<=q;k++){//check down
				if(map[p+1][k]==1){
					cout<<"Bad placement.";
					return 0;
				}
			}
			bool bt=true;
			for(int a=i+1;a<=p;a++){
				for(int b=j+1;b<=q;b++){
					if(map[a][b]==0){
						bt=false;
						break;
					}
				}
				if(!bt)break;
			}
			if(bt){
				ans++;
				for(int a=i;a<=p;a++){
					for(int b=j;b<=q;b++)map[a][b]=0;
				}
			}
		}
	}
	cout<<"There are "<<ans<<" ships.";
	return 0;
}
