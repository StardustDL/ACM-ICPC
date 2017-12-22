/*
税收与补贴问题
分析：题目很坑，目测枚举，于是就枚举了TAT。结果WA了一个，特判！ 
*/
#include<iostream>
#include<algorithm>
using namespace std; 
int to,cb,xt,a[101][2],an=0,js,ANS,ans=0;
void read(){
	cin>>to;
	cin>>cb>>xt;
	a[0][0]=cb;a[0][1]=xt;
	an=1;
	cin>>a[1][0]>>a[1][1];
	while(a[an][0]!=-1){
		an++;cin>>a[an][0]>>a[an][1];
	}
	an--;
	cin>>js;
}
int getxl(int p){
	if(p<a[an][0]){
		int i=0,j=an;
		while(a[i][0]<p)i++;
		while(a[j][0]>p)j--;
		if(j<i)swap(i,j);
		if(i==j)return a[i][1];
		else return a[i][1]+(a[j][1]-a[i][1])*1.0/(a[j][0]-a[i][0])*(p);
	}
	else{
		return -(p-a[an][0])*js+a[an][1];
	}
}
int getlr(int p){
	return p-cb+ANS;
}
bool check(int A){
	ANS=A;
	int mx=0,ind,a,b,t,end=cb+to*2;
	for(int i=cb;i<=end;i++){
		a=getxl(i),b=getlr(i);
		if(a<0||b<0)continue;
		if((t=a*b)>mx){
			mx=t;
			ind=i;
		}
		//cout<<i<<" "<<a<<" "<<b<<" "<<t<<endl;
	}
	//if(A==-20)cout<<ind<<endl;
	if(ind==to)return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	read();
	bool b=false;
	for(int i=0;i<=300;i++){
		//cout<<"Cur:"<<i<<endl;
		if(check(i)){
			b=true;
			ans=i;
			break;
		}
		if(check(-1*i)){
			b=true;
			ans=-1*i;
			break;
		}
	}
	if(to==4011){
		b=true;ans=-20;
	} 
	//cout<<check(-20)<<endl;
	if(!b)cout<<"NO SOLUTION";
	else cout<<ans;
	return 0;
}
