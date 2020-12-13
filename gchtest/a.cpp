#include "temp.h"

void A::log(int a)
{
    std::cout << a << std::endl;
}

int main()
{
    A a;
    a.log();
    std::vector<int> v;
    return 1;
}
