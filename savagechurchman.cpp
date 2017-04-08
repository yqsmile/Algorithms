#include <iostream>
#include <vector>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;

struct MCnode{
  int m;
  int c;
  int b;
};

vector<MCnode> closed;
list<MCnode> fringe;

bool isGoal(MCnode tnode){
  if(tnode.m==0&&tnode.c==0&&tnode.b==0){
    return true;
  }
  else {
    return false;
  }
}

bool isLegal(MCnode tnode){
  if(tnode.m>=0&&tnode.m<=3&&tnode.c>=0&&tnode.c<=3){
    if((tnode.m==tnode.c)||(tnode.m==3)||(tnode.m==0)){
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

bool operator==(MCnode m1,MCnode m2){
  if(m1.m==m2.m&&m1.c==m2.c&&m1.b==m2.b){
    return true;
  }
  else{
    return false;
  }
}

bool isClosed(MCnode tnode){
  int i;
  for(i=0;i<closed.size();++i){
    if(tnode==closed[i]){
      return true;
    }
  }
  if(i==closed.size()){
    return false;
  }
}

void expand(MCnode tnode,int b,list<MCnode> &fringe){
  MCnode node[5];
  if(b==1){
    for(int i=0;i<5;++i){
      node[i].b=0;
    }
    node[0].m=tnode.m-1;
    node[0].c=tnode.c;
    node[1].m=tnode.m;
    node[1].c=tnode.c-1;
    node[2].m=tnode.m-1;
    node[2].c=tnode.c-1;
    node[3].m=tnode.m-2;
    node[3].c=tnode.c;
    node[4].m=tnode.m;
    node[4].c=tnode.c-2;
  }
  else{
    for(int i=0;i<5;++i){
      node[i].b=1;
    }
    node[0].m=tnode.m+1;
    node[0].c=tnode.c;
    node[1].m=tnode.m;
    node[1].c=tnode.c+1;
    node[2].m=tnode.m+1;
    node[2].c=tnode.c+1;
    node[3].m=tnode.m+2;
    node[3].c=tnode.c;
    node[4].m=tnode.m;
    node[4].c=tnode.c+2;
  }
  for(int i=0;i<5;++i){
    if(isLegal(node[i])&&!isClosed(node[i])){
      fringe.push_front(node[i]);
    }
  }
}

int main(){
  MCnode initNode,unode;
  initNode={3,3,1};
  fringe.push_front(initNode);
  while(!fringe.empty()){
    unode=fringe.front();
    fringe.pop_front();
    if(isGoal(unode)){
      closed.push_back(unode);
      for(int i=0;i!=closed.size();++i){
        cout<<closed[i].m<<closed[i].c<<closed[i].b<<endl;
      }
      cout<<closed.size()<<endl;
      break;
    }
    if(!isClosed(unode)){
      closed.push_back(unode);
      expand(unode, unode.b, fringe);
    }
  }
}
