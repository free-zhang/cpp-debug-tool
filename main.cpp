#include "debug.h"

int main(){
    vector<int> v1 = {1,2,3,4,5,6};
    PRINT(v1);
    // at line 5 , v1 ->  [ 1, 2, 3, 4, 5, 6, ]

    vector<vector<string>> v2 = {{"abc", "def"}, {"123a", "456b"}};
    PRINT(v2);
    // at line 8 , v2 ->  [ [ "abc", "def", ], [ "123a", "456b", ], ]

    set<int> st = {1,2,2,3,3,4,4};
    PRINT(st);
    // at line 11 , st ->  { 1, 2, 3, 4, }

    map<string, long> m1 ={{"123", 1}, {"456", 2}};
    PRINT(m1);
    // at line 14 , m1 ->  { "123" : 1, "456" : 2, }
    
    map<int, map<string, long>> m2;
    m2[1] = m1;
    m2[2] = m1;
    PRINT(m2);
    // at line 19 , m2 ->  { 1 : { "123" : 1, "456" : 2, }, 2 : { "123" : 1, "456" : 2, }, }

    return 0;
}


