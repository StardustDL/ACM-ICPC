#include <iostream>
#include<string>
#include <vector>
#include <algorithm>  
using namespace std;
int main(){
	string str;
	string temp;;
	string target="marshtomp";
	string Des="fjxmlhx";
	string ::size_type tLength=target.length();
	string ::size_type dLength=Des.length();
	vector<string> output;
	while (getline(cin,str) ){
		temp=str;
		transform(temp.begin(),temp.end(),temp.begin(),::tolower);
		string ::size_type pos=0;
		while ( (pos=temp.find(target,pos))<str.length()){
			str.replace(pos,tLength,Des);
			temp.replace(pos,tLength,Des);
			pos+=dLength;
		}
		output.push_back(str);
	}
	for (vector<string>::size_type i=0;i<output.size();i++)
		cout<<output[i]<<endl;
	return 0;
}