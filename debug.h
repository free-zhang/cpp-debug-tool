/* Created by freezhang on 2019/9/29.
 * @初衷：python的print函数可以非常方便的打印变量的内容，调试起来很方便。在c++中没有此方法，于是写了PRINT(a)模拟一下，此宏比较方便的地方是可以打印出变量的名字
 * @类debug: 约定T1, T2,T3为c++基础类型以及string类型，Debug类定义的str方法可以将 T1, vector<T1>, vector<vector<T1>, map<T1, T1>, map<T1, map<T2, T3>>, set<T1>转换为string
 * @使用方法：PRINT(a) 宏可以将 变量所在的行，变量的名字，变量值打印出
 *           SHOW_VAR 宏可以控制是否打印变量
 * @支持类型： 约定T1, T2,T3为c++基础类型以及string类型，目前支持 T1, vector<T1>, vector<vector<T1>, map<T1, T1>, map<T1, map<T2, T3>>, set<T1>
 */

#ifndef CLION_TEST_DEBUG_H
#define CLION_TEST_DEBUG_H

#include <map>
#include <iostream>
#include <string>
#include <set>
#include <vector>

using  namespace std;

#define SHOW_VAR 1

#if SHOW_VAR==1
    #define PRINT(a) {cout << "at line "<< __LINE__ << " , "<< #a << " ->  " <<  Debug::str(a) << endl;}
#elif SHOW_VAR==0
    #define PRINT(a) {}
#endif

struct Debug {
    template <typename T>
    static string to_str(const T& t){
        return (to_string(t));
    };

    static string to_str(const string& s){
        return ("\"" + s + "\"");
    }

    template<typename T>
    static string str(const T& a) { return to_string(a); };

    template<typename T>
    static string str(const vector<T>& v) {
        string s("[ ");
        for (auto &i : v) { s += to_str(i) + ", "; }
        return (s += "]");
    };

    template<typename T>
    static string str(const vector<vector<T>>& v) {
        string s("[ ");
        for (auto &i : v) s += str(i) + ", ";
        return (s + "]");
    };


    template<typename T1, typename T2>
    static string str(const map<T1, T2>& m) {
        string s("{ ");
        for (auto &i : m) { s += to_str(i.first) + " : " + to_str(i.second) + ", "; }
        return (s += "}");
    };

    template <typename T>
    static string str(const set<T>& st){
        string s("{ ");
        for(auto &i : st){s += to_str(i) + ", ";}
        return (s += "}");
    }

    template <typename T1, typename T2, typename T3>
    static string str(const map<T1, map<T2, T3>>& m){
        string s("{ ");
        for (auto &i : m) { s += to_str(i.first) + " : " + str(i.second) + ", "; }
        return (s += "}");
    };
};

#endif //CLION_TEST_DEBUG_H
