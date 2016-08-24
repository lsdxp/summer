//
//  main.cpp
//  dele
//
//  Created by Shengdong  Liu on 8/11/16.
//  Copyright © 2016 Shengdong  Liu. All rights reserved.
//

#include <iostream>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct node{
    bool light;
    int x;
    int y;
    struct node* left;
    struct node* right;
};

vector<int> off;
void build_tree(node root,int x1,int y1,int x2,int y2,int width,int height){
    off.push_back(root.x*10+root.y);
    if( ((root.x+x1)>=0)&&((root.x+x1)<width)&&((root.y+y1)>=0)&&((root.y+y1)<height))
       {
           node left;
           left.light=false;
           left.x=root.x+x1;
           left.y=root.y+y1;
           off.push_back(left.x*10+left.y);
           build_tree(left,x1,y1,x2,y2,width,height);

       }

    if( ((root.x+x2)>=0)&&((root.x+x2)<width)&&((root.y+y2)>=0)&&((root.y+y2)<height))
    {
        node right;
        right.light=false;
        right.x=root.x+x2;
        right.y=root.y+y2;
        off.push_back(right.x*10+right.y);
        build_tree(right,x1,y1,x2,y2,width,height);
    }
};

int main(int argc, const char * argv[]) {

    int width,height,x1,y1,x2,y2,startx,starty;
    width=5;
    height=3;
    x1=-1;
    y1=0;
    x2=-1;
    y2=-1;
    startx=4;
    starty=2;
    node root;
    root.light=true;
    root.x=startx;
    root.y=starty;
    build_tree(root,x1,y1,x2,y2,width,height);
    sort( off.begin(), off.end() );
    off.erase( unique( off.begin(), off.end() ), off.end() );
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it2 = off.begin() ; it2 != off.end(); ++it2)
        std::cout << ' ' << *it2<<endl;
    
    cout<<width*height-off.size()<<endl;
    return 0;
}

