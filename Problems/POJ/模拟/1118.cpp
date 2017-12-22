/*
Lining Up
题意：给N各点，求最多有多少个点在同一条直线上
分析：解析几何暴力算 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=700; 
struct Point{int x,y;}p[MAXN+3];
int main(){
    int n,sum,mx;
    while(cin>>n&&n){
        for(int i=0;i<n;i++)cin>>p[i].x>>p[i].y;
        mx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                sum=2;
                for(int k=j+1;k<n;k++){
                    sum+=
						((p[i].y-p[k].y)*(p[j].x-p[k].x))
						==((p[i].x-p[k].x)*(p[j].y-p[k].y));
                }
                mx=max(mx,sum);
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
