/*
Web Navigation
题意：模拟浏览器的前进后退功能
分析：一维数组模拟 ，注意每拜访一个网站，此后的网站就作废了，此网站就是最后一个
*/
#include<iostream>
#include<string>
using namespace std;
int main(){
    string a[120],b;
    int i=1,n=0,m;//i:下次读入的指针，n:当前指针，m:总网站数 
    a[0]="http://www.acm.org/";
    while(cin>>b&&b!="QUIT"){
        if(b=="VISIT"){
            cin>>a[i];
            n=m=i;
            i++;
            cout<<a[n]<<endl;
        }
        else if(b=="BACK"){
            if(n-1>=0){
                i--;
                cout<<a[--n]<<endl;
            }
            else cout<<"Ignored"<<endl;
        }
        else{
            if(n+1<=m){
                i++;
                cout<<a[++n]<<endl;
            }
            else cout<<"Ignored"<<endl;
        }
    }
    return 0;
}
