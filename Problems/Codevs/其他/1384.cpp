/*
ºÚÉ«ĞÇÆÚÎå
*/
#include<iostream>
using namespace std;
int get(int y,int m){
    int i=0;
    if((y%4==0&&y%100!=0)||(y%400==0)) i=1;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)return 31;
    else if (m==2){
		if(i==1)return 29;
        else return 28;
	}
    return 30;
}
int main(){
    int n,a[7]={0},week=6;cin>>n;
    for(int i=1900;i<=1900+n-1;i++)
        for(int j=1;j<=12;j++){
			a[week%7]++;
            week+=get(i,j);
        }
    cout<<a[6]<<" "<<a[0]<<" ";
    for(int i=1;i<=5;i++)
        cout<<a[i]<<" ";
    return 0;
}
