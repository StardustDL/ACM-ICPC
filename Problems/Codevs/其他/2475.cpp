/*
Ry哥还是任意
*/
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int RY=0,ry=0;
	char a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a=='S'&&b=='J')ry++;
		else if(a=='J'&&b=='S')RY++;
		else if(a=='J'&&b=='B')ry++;
		else if(a=='B'&&b=='J')RY++;
		else if(a=='B'&&b=='S')ry++;
		else if(a=='S'&&b=='B')RY++;
	}
	if(RY==ry)cout<<"RY=ry";
	else if(RY<ry)cout<<"ry win";
	else cout<<"RY win";
	return 0;
}
