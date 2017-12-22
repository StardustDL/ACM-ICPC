#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=9;
bitset<MAXN+3> used=0;
int mp[MAXN+3][MAXN+3],n;
void read(){
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			cin>>mp[i][j];
		}
	}
}
bool check(){
	for(int i=1;i<=9;i++){
		used=0;
		for(int j=1;j<=9;j++){
			if(used[mp[i][j]])return false;
			used[mp[i][j]]=1;
		}
	}
	for(int i=1;i<=9;i++){
		used=0;
		for(int j=1;j<=9;j++){
			if(used[mp[j][i]])return false;
			used[mp[j][i]]=1;
		}
	}
	for(int i=1;i<=9;i+=3){
		for(int j=1;j<=9;j+=3){
			used=0;
			for(int a=0;a<=2;a++){
				for(int b=0;b<=2;b++){
					if(used[mp[i+a][b+j]])return false;
					used[mp[i+a][b+j]]=1;
				}
			}
		}
	}
	return true;
}
int main(){
	cin>>n;
	while(n-->0){
		read();
		if(check())cout<<"Right"<<endl;
		else cout<<"Wrong"<<endl;
	}
	return 0;
}
