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

/*
 * Complete the function below.
 */
vector < float > market_equilibrium(vector < float > initial_market_share, vector < vector < float > > switch_probability) {
    float limit;
    vector < float > c;
    for(int i=0;i<initial_market_share.size();i++)
        c.push_back(0.0);
    
    do{
        for(int i=0;i<initial_market_share.size();i++)
            c[i]=0.0;
        
        for(int i=0;i<initial_market_share.size();i++)
            for(int j=0;j<switch_probability.size();j++)
            c[i]+=initial_market_share[j]*switch_probability[j][i];
    
        limit=fabs(c[0]-initial_market_share[0]);
        for(int i=0;i<initial_market_share.size();i++)
            initial_market_share[i]=c[i];
    }
    while(limit>0.00001);
    return c;
            
}


int main(int argc, const char * argv[]) {
   // ofstream fout(getenv("OUTPUT_PATH"));
    vector <float> res;
    
    int _initial_market_share_size=0;
    //cin>>_initial_market_share_size;
    _initial_market_share_size=2;
    //cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    vector<float> _initial_market_share;
    float _inital_market_share_item;
//    for(int _initial_market_share_i=0;_initial_market_share_i<_initial_market_share_size;_initial_market_share_i++)
//    {
//         cin>>_inital_market_share_item;
//         cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//        _initial_market_share.push_back(_inital_market_share_item);
//    }
    _initial_market_share.push_back(.4);
    _initial_market_share.push_back(.6);
    
    int _switch_probability_rows=2;
    int _switch_probability_cols=2;
    
    //cin>>_switch_probability_rows>>_switch_probability_cols;
    vector< vector<float> > _switch_probability(_switch_probability_rows);
//    for(int _switch_probability_i=0;_switch_probability_i<_switch_probability_rows;_switch_probability_i++)
//    {   for(int _switch_probability_j=0;_switch_probability_j<_switch_probability_cols;_switch_probability_j++)
//        {
//            float _switch_probability_tmp;
//            cin>>_switch_probability_tmp;
//            _switch_probability[_switch_probability_i].push_back(_switch_probability_tmp);
//        }
//    }
    _switch_probability[0].push_back(.8);
    _switch_probability[0].push_back(.2);
    _switch_probability[1].push_back(.1);
    _switch_probability[1].push_back(.9);
    
    res=market_equilibrium(_initial_market_share,_switch_probability);
    for(int res_i=0;res_i<res.size();res_i++)
    {
        //fout<<res[res_i]<<endl;
        cout<<res[res_i]<<endl;
    }
    //fout.close();
    return 0;
    
}

