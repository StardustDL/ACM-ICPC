/*
�������ĸ��� 
���������ӵ�ģ�⣬�������ʽ���ҵĳ����δ֪��ϵ�����ɡ������ú�����ʽ���˴��� 
*/
#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
char x,str[101];
int cl=0,cr=0,xl=0,xr=0;
bool calitem(int l,int r,int &e){//��һ���е�ϵ����ȡ�������Ƿ��ţ����ش����Ƿ���δ֪�� 
	e=0;
	bool hasx=false;
	if(str[r]>'9'){
		x=str[r];
		r--;
		hasx=true;
	}
	while(l<=r){
		e=e*10+str[l]-'0';
		l++;
	}
	return hasx;
}
bool split(int &l,int &r){//��l��ʼ�ָ��һ����Ҳ������ţ����ط����Ƿ�Ϊ�� 
	bool isplus=true;
	if(str[l]=='-')isplus=false,l++;
	else if(str[l]=='+')l++;
	r=l;
	while(str[r]!='+' && str[r]!='-' && str[r]!='=' && r<strlen(str))r++;
	r--;
	return isplus;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>str;
	int l=0,r=0,e,eqind=0;
	while(eqind<strlen(str)&&str[eqind]!='=')eqind++;
	while(l<eqind){
		bool b=split(l,r);
		bool c=calitem(l,r,e);
		if(c){
			if(b)xl+=e;
			else xl-=e;
		}
		else{
			if(b)cl+=e;
			else cl-=e;
		}
		l=r+1;
	}
	l=eqind+1;
	while(l<strlen(str)){
		bool b=split(l,r);
		bool c=calitem(l,r,e);
		if(c){
			if(b)xr+=e;
			else xr-=e;
		}
		else{
			if(b)cr+=e;
			else cr-=e;
		}
		l=r+1;
	}
	cout<<x<<"="<<setprecision(3)<<setiosflags(ios::fixed)<<((cr-cl)*1.0/(xl-xr));
	return 0;
}
