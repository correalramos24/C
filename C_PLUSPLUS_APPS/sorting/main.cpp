#include <bits/stdc++.h>
#include "sorting.hh"

using namespace std;


int main(int argc, char const *argv[]){

    cout << "Welcome to the drive program for sorting algorithms" << endl;

    vector<int> v(10, 0);

    sorting<int>::mergeSort(v);


    cout << "All done" << endl;
    return 0;
}
