/*
ºìÓëºÚ
·ÖÎö£ºBFS 
*/
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int a[22][22];
struct poi{
	int x,y;
	poi(int a,int b){x=a;y=b;}
	int get(){return a[x][y];}
	void set(int val){a[x][y]=val;}
};
queue<poi> ps;
int w,h,x,y;
char c;
bool read(){
	cin>>w>>h;
	if(w==0&&h==0)return false;
	scanf("\n");
	while(!ps.empty())ps.pop();
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>c;
			switch(c){
				case '.':a[i][j]=1;break;
				case '@':a[x=i][y=j]=1;break;
				case '#':a[i][j]=0;break;
			}
		}
		scanf("\n");
	}
	return true;
}
void work(){
	poi po=poi(x,y);
	ps.push(po);
	po.set(2);
	while(!ps.empty()){
		poi po=ps.front();ps.pop();
		if((po.x-1>0)&&(a[po.x-1][po.y]==1)){
			poi k=poi(po.x-1,po.y);
			ps.push(k);
			k.set(2);
		}
		if((po.y-1>0)&&(a[po.x][po.y-1]==1)){
			poi k=poi(po.x,po.y-1);
			ps.push(k);
			k.set(2);
		}
		if((po.x+1<=h)&&(a[po.x+1][po.y]==1)){
			poi k=poi(po.x+1,po.y);
			ps.push(k);
			k.set(2);
		}
		if((po.y+1<=w)&&(a[po.x][po.y+1]==1)){
			poi k=poi(po.x,po.y+1);
			ps.push(k);
			k.set(2);
		}
	}
}
int sum(){
	int sum=0;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if(a[i][j]==2)sum++;
	return sum;
}
int main(){
	while(read()){
		work();cout<<sum()<<endl;
	}
	return 0;
}
