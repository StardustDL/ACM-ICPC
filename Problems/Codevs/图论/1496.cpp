/*
地毯填补
分析：典型的分治，但不知道为什么过不了
	  思路是：将每个棋盘分成四个小棋盘，对于已经有黑块的部分直接递归求解，否则强行设置一个位置为黑色
	  怎么设置呢？在当前棋盘的中心即可，这样刚好构成一个图形
	  终止条件是棋盘大小=2*2时，直接判断黑块的位置，输出 
*/ 
#include<iostream>
using namespace std;
const int MAXN=1<<10+1;
int mp[MAXN+3][MAXN+3],X,Y,K;
bool has(int x,int y,int l){
	for(int i=x;i<=x+l-1;i++){
		for(int j=y;j<=y+l-1;j++){
			if(mp[i][j])return true;
		}
	}
	return false;
}
void out(){
	for(int i=1;i<=1<<K;i++){
		for(int j=1;j<=1<<K;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void solve(int x,int y,int k){
	if(k==1){
		if(has(x,y,1)){
			cout<<x+1<<" "<<y+1<<" "<<3<<endl;
		}
		else if(has(x+1,y,1)){
			cout<<x<<" "<<y+1<<" "<<2<<endl;
		}
		else if(has(x,y+1,1)){
			cout<<x+1<<" "<<y<<" "<<1<<endl;
		}
		else if(has(x+1,y+1,1))cout<<x<<" "<<y<<" "<<4<<endl;
		mp[x][y]=mp[x+1][y]=mp[x][y+1]=mp[x+1][y+1]=1;
		return;
	}
	
	int l=(1<<k-1),a,b,c,d;a=b=c=d=0;
	if(!has(x,y,l)){
		a=1;
		mp[x+l-1][y+l-1]=1;
	}
	if(!has(x+l,y,l)){
		b=1;
		mp[x+l][y+l-1]=1;
	}
	if(!has(x,y+l,l)){
		c=1;
		mp[x+l-1][y+l]=1;
	}
	if(!has(x+l,y+l,l)){
		d=1;
		mp[x+l][y+l]=1;
	}
	//out();
	if(a+b+d==3)cout<<x+l<<" "<<y+l-1<<" "<<1<<endl;
	if(a+c+d==3)cout<<x+l-1<<" "<<y+l<<" "<<2<<endl;
	if(b+c+d==3)cout<<x+l<<" "<<y+l<<" "<<3<<endl;
	if(a+b+c==3)cout<<x+l-1<<" "<<y+l-1<<" "<<4<<endl;
	solve(x,y,k-1);
	solve(x+l,y,k-1);
	solve(x,y+l,k-1);
	solve(x+l,y+l,k-1);
}
int main(){
	cin>>K;
	cin>>X>>Y;
	mp[X][Y]=1;
	//out();
	solve(1,1,K);
	/out();
	return 0;
}
