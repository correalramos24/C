#include <iostream>
#include <vector>
#include <stack>
#include <functional>
#include <algorithm> //for each
#include <numeric>   //reduce
#include "HOF.hh"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{   
    //Passing functions as arguments:
    std::cout << my_foo(1,2, is_greater) << std::endl;
    std::cout << my_foo(1,2, is_less) << std::endl;
    //Passing lamda functions as arg:
    std::cout << my_foo(2,2, [](int a, int b){return a == b;}) << std::endl;
    std::cout << my_foo(1.0,1.0, is_equal_gen) << std::endl;
    std::cout << "========" << std::endl;
    std::vector<int> v = {10,20,30,40,50,60,70,80};
    auto suma_3 = [](int x){return x+3;};
    std::transform(v.begin(), v.end(), v.begin(), suma_3);
    std::for_each(v.begin(), v.end(), [](const int& i){cout << i << endl;});
    std::cout << "========" << std::endl;
    std::vector<int> res;
    auto less_40 = [](int x){return x < 40;};
    std::copy_if(v.begin(), v.end(), std::back_inserter(res), less_40);
    std::for_each(res.begin(), res.end(), [](const int& i){cout << i << endl;});
    cout << result << endl;
    return 0;
}
