#include <compare-img.hpp>
#include <iostream>
using namespace std;

int main()
{
    double res = compareImg("a.JPG", "b.JPG");
    cout << res << endl;
}