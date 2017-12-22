/*

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct score{
	int l,w;
	score(int w,int l):l(l),w(w){}
};
char c;
int l11,l21,w11,w21;
vector<score> s11,s21;
bool check11(){
	if(abs(l11-w11)>=2&&(l11>=11||w11>=11))return true;
	return false;
}
bool check21(){
	if(abs(l21-w21)>=2&&(l21>=21||w21>=21))return true;
	return false;
}
int main(){
	while(scanf("%c",&c),c!='E'){
		if(c=='L')l11++,l21++;
		else if(c=='W')w11++,w21++;
		else continue;
		if(check11()){
			s11.push_back(score(w11,l11));
			w11=l11=0;
		}
		if(check21()){
			s21.push_back(score(w21,l21));
			w21=l21=0;
		}
	}
	s11.push_back(score(w11,l11));
	s21.push_back(score(w21,l21));
	for(int i=0;i<s11.size();i++)
		printf("%d:%d\n",s11[i].w,s11[i].l);
	puts("");
	for(int i=0;i<s21.size();i++)
		printf("%d:%d\n",s21[i].w,s21[i].l);
	return 0;
}

