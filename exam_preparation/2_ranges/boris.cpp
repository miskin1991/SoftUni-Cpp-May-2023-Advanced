#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <sstream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <memory>
#include <set>
#include <map>

using namespace std;


int main(int argc, char* argv[]){


    vector<int> vecFrom,vecTo;

    while (true){
        string strRange;
        getline(cin,strRange);

        if (strRange[0]=='.')
            break;
        
        int numFrom, numTo;
        istringstream theIstr(strRange);
        theIstr>>numFrom;
        theIstr>>numTo;

        vecFrom.push_back(numFrom);
        vecTo.push_back(numTo);
    }

    sort(vecFrom.begin(),vecFrom.end());
    sort(vecTo.begin(),vecTo.end());

    while (true){
        string strCheckNumber;
        getline(cin,strCheckNumber);

        if(strCheckNumber[0]=='.')
            break;

        int checkNumber;
        istringstream theIstr(strCheckNumber);
        theIstr>>checkNumber;
        auto iterFrom=vecFrom.begin();


        auto iterTo=lower_bound(vecTo.begin(),vecTo.end(),checkNumber);
        size_t idx=iterTo-vecTo.begin();

        if (*iterTo>=checkNumber && vecFrom[idx]<=checkNumber)
            cout<<"in"<<endl;
        else
            cout<<"out"<<endl;

    }

}

/*
1 3
5 10
20 20
.
0
2
3
4
5
7
19
20
10
.
*/