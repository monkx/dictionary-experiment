#include<iostream>
#include<fstream>
#include <algorithm>
#include<string>
using namespace std;
int main(){
  int maxi=-1;
  string longW;
  ifstream impFile;
  impFile.open("dict.txt");
  if(!impFile)cout<<"error";
  string inp;
  while(impFile>>inp){
    transform(inp.begin(), inp.end(),inp.begin(), ::tolower);
    int a[26]={0},flag=1,waste=0;
    for(int i=0;i<inp.length();i++){
      if(inp[i]<='z' and inp[i]>='a')a[inp[i]-'a']++;
      else waste++;
    }
    for(int i=0;i<26;i++)if(a[i]>1)flag=0;
    int n=inp.length();
    if(flag && (maxi<n-waste))maxi=n,longW = inp;
  }cout<<longW<<endl;
}
