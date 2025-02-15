#include <atomic>
#include <iostream>
#include <utility>

struct A
{
    int a[100];
};

struct B
{
    int x;
    int y;
};

int main()
{
    std::cout << std::boolalpha
        << "std::atomic<A> is lock free? "
        << std::atomic<A>{}.is_lock_free() << '\n'
        << "std::atomic<B> is lock free? "
        << std::atomic<B>{}.is_lock_free() << '\n';
}