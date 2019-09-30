/* Created by freezhang on 2019/9/29.
 * @初衷：python的print函数可以非常方便地打印变量的值，调试起来很方便，在c++中没有此方法，于是写了PRINT(a)模拟一下，此宏不仅可以打印变量的值，还可以打印变量的名字以及变量所在行数。
 * @类型定义：T1, T2, T3 为c++基本类型以及string类型的任意一种
 * @使用限制：宏PRINT 目前支持的类型有 T1, vector<T1>, vector<vector<T1>, map<T1, T2>, map<T1, map<T2, T3>>, set<T1> 转换为string的方法，其他类型可以考虑先类型转换
 * @使用示例如下：
 *              vector<int> v1 = {1,2,3,4,5,6};
 *              PRINT(v1);
 *              // at line 5 , v1 ->  [ 1, 2, 3, 4, 5, 6, ]

 *              vector<vector<string>> v2 = {{"abc", "def"}, {"123a", "456b"}};
 *              PRINT(v2);
 *              // at line 8 , v2 ->  [ [ "abc", "def", ], [ "123a", "456b", ], ]

 *              set<int> st = {1,2,2,3,3,4,4};
 *              PRINT(st);
 *              // at line 11 , st ->  { 1, 2, 3, 4, }

 *              map<string, long> m1 ={{"123", 1}, {"456", 2}};
 *              PRINT(m1);
 *              // at line 14 , m1 ->  { "123" : 1, "456" : 2, }

 *              map<int, map<string, long>> m2;
 *              m2[1] = m1;
 *              m2[2] = m1;
 *              PRINT(m2);
 *              // at line 19 , m2 ->  { 1 : { "123" : 1, "456" : 2, }, 2 : { "123" : 1, "456" : 2, }, }
 */

#ifndef CLION_TEST_DEBUG_H
#define CLION_TEST_DEBUG_H

#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using  namespace std;

#define SWITCH_PRINT 1

#if SWITCH_PRINT==1
    #define PRINT(a) {cout << "at line "<< __LINE__ << " , "<< #a << " ->  " <<  Debug::to_str(a) << endl;}
#elif SWITCH_PRINT==0
    #define PRINT(a) {}
#endif

/* @类型定义：T1, T2, T3 为c++基本类型以及string类型的任意一种
 * @brief：利用c++的模板以及函数重载机制，定义了将T1, vector<T1>, vector<vector<T1>, map<T1, T2>, map<T1, map<T2, T3>>, set<T1> 转换为string的方法
 */
struct Debug {
    template <typename T>
    static string to_str(const T& t){
        return (to_string(t));
    };

    static string to_str(const string& s){
        return ("\"" + s + "\"");
    }

    template<typename T>
    static string to_str(const vector<T>& v) {
        string s("[ ");
        for (auto &i : v) { s += to_str(i) + ", "; }
        return (s += "]");
    };

    template<typename T>
    static string to_str(const vector<vector<T>>& v) {
        string s("[ ");
        for (auto &i : v) s += to_str(i) + ", ";
        return (s + "]");
    };


    template<typename T1, typename T2>
    static string to_str(const map<T1, T2>& m) {
        string s("{ ");
        for (auto &i : m) { s += to_str(i.first) + " : " + to_str(i.second) + ", "; }
        return (s += "}");
    };

    template <typename T>
    static string to_str(const set<T>& st){
        string s("{ ");
        for(auto &i : st){s += to_str(i) + ", ";}
        return (s += "}");
    }

    template <typename T1, typename T2, typename T3>
    static string to_str(const map<T1, map<T2, T3>>& m){
        string s("{ ");
        for (auto &i : m) { s += to_str(i.first) + " : " + to_str(i.second) + ", "; }
        return (s += "}");
    };
};

#endif //CLION_TEST_DEBUG_H
