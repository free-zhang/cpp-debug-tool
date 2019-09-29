#include "debug.h"

int main(){
    vector<int> v1 = {1,2,3,4,5,6};
    PRINT(v1);

    vector<vector<string>> v2 = {{"abc", "def"}, {"123a", "456b"}};
    PRINT(v2);

    set<int> st = {1,2,2,3,3,4,4};
    PRINT(st);

    map<string, long> m1 ={{"123", 1}, {"456", 2}};
    PRINT(m1);

    map<int, map<string, long>> m2;
    m2[1] = m1;
    m2[2] = m1;
    PRINT(m2);

    return 0;
}
