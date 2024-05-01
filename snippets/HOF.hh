//High order functions
bool is_greater(int a, int b){
    return a > b;
}

bool is_less(int a, int b){
    return a < b;
}

//Function as parameter:
bool my_foo(int x, int y, bool(*cmp)(int x, int y)){
    return cmp(x, y);
}

bool my_foo2(int x, int y, std::function<bool(int,int)> f){
    return f(x, y);
}

//Define a generic lambda function
auto is_equal_gen = [](auto a, auto b) -> bool{
    return a > b;
};
