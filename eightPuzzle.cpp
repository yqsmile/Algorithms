#include<iostream>
#include<algorithm>
#include<vector>
#include<array>

const std::size_t N=9;
using std::array;
using std::cin;
using std::cout;
using std::vector;
using std::ostream;
using std::cerr;

struct EPnode{
  array<int, N> status;
  int position;
  EPnode *pnode;
  int dth;
};

vector<EPnode> solution;
vector<EPnode> open;
vector<EPnode> closed;
vector<vector<int> > rules={{3,1},{-1,3,1},{-1,3},{-3,1,3},{-3,1,3,-1},{-3,-1,3},{-3,1},{-1,-3,1},{-1,-3}};
EPnode s={{2,8,3,1,6,4,7,0,5},7,NULL,0};
// EPnode s={{3,1,0,5,6,4,2,7,8},2,NULL,0};
//310564278
EPnode goal{{1,2,3,8,0,4,7,6,5},4,NULL,0};


int count=0;

ostream& operator<< (ostream& out,EPnode tnode);
bool comp(EPnode lnode,EPnode rnode);
bool find(EPnode tnode);
void swap(int&,int&);
EPnode move(EPnode ,int);
void expand(EPnode &);
void result(EPnode *tnode);
int anticlockwise(EPnode tnode);
bool isSolved(EPnode&);

int main(){
  expand(s);
}

void result(EPnode *tnode){
  if(!isSolved(s))
  return ;

  solution.push_back(*tnode);
  if(tnode->pnode==NULL){
    return;
  }
  result(tnode->pnode);
}

void expand(EPnode &tnode){
  if(tnode.status==goal.status){
    result(&tnode);
    for(auto b=solution.rbegin();b!=solution.rend();++b){
      cout<<*b<<"\n";
    }
    cout<<solution.size()<<"\n";
    cout<<closed.size()<<std::endl;
    return;
  }
  closed.push_back(tnode);
  vector<EPnode> snode;
  for(auto a:rules[tnode.position]){
    snode.push_back(move(tnode,a));
  }
  for(auto &a:snode){
      if(!find(a)){
        a.pnode=&tnode;
        a.dth=tnode.dth+1;
        open.push_back(a);
      }
  }
  sort(open.begin(),open.end(),comp);
  EPnode unode=*(open.end()-1);
  open.erase(open.end()-1);
  expand(unode);
}

void swap(int &a,int &b){
  int temp;
  temp=a;
  a=b;
  b=temp;
}

EPnode move(EPnode tnode,int direction){
  EPnode temp=tnode;
  swap(temp.status[temp.position], temp.status[temp.position+direction]);
  temp.position+=direction;
  return temp;
}

ostream& operator<< (ostream& out,EPnode tnode){
  for(int i=0;i<N;++i){
    if(i%3==0&&i!=0){
      out<<"\n";
    }
    out<<tnode.status[i];
  }
  out<<"\n";
  return out;
}

bool comp(EPnode lnode,EPnode rnode){
  int lh=0,rh=0;
  for(int i=0;i<N;++i){
    if(lnode.status[i]!=goal.status[i]){
      ++lh;
    }
    if(rnode.status[i]!=goal.status[i]){
      ++rh;
    }
  }
  if(lh+lnode.dth>rh+rnode.dth){
    return true;
  }
  return false;
}

bool find(EPnode tnode){
  for(auto &a:closed){
    if(a.status==tnode.status){
      return true;
    }
  }
  return false;
}

bool isSolved(EPnode &tnode){
  return anticlockwise(tnode)==anticlockwise(goal);
}
int anticlockwise(EPnode tnode){
  int sum=0;
  for(int i=0;i<N;++i){
    if(tnode.position==i){
      continue;
    }
    for(int j=0;j<i;++j){
      if(tnode.position==i){
        continue;
      }
      if(tnode.status[j]<tnode.status[i]){
        ++sum;
      }
    }
  }
}
