#include <iostream>

using namespace std;
int add(int a, int b)
{
    cout<<a+b;

}
double add(double a, double b){
    cout <<a+b;

}
int add(int a, int b, int c){
    cout<<a+b+c;

}

int main()
{
    add(1,2);
    cout<<""<<endl;
    add(2.3, 1.5);
    cout<<""<<endl;
    add(3,2,5);
    return 0;
}
