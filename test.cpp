#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
  // cout<<"begin";
  // // list<int> lst1={1,2};
  // vector<int> lst1={1,2};
  // vector<int>::iterator iter1 = lst1.begin(),iter2=lst1.end();
  // vector<int>::difference_type
  // // list<int>::iterator iter1 = lst1.begin(),iter2=lst1.end();
  // while(iter1<iter2){
  //   cout<<"not end";
  //   ++iter1;
  // }
  FILE *fw;
  fw=fopen("r2.txt", "w");
  string s="sss";
  cin>>s;
  const char* a;
  a=s.c_str();
  fputs(a, fw);
  fclose(fw);
  cout<<"over";


}
