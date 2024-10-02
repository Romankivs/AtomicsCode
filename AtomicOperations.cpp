#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::atomic_int atomic_counter;
int counter;

void f()
{
    for (int n = 0; n < 100000; ++n)
    {
        atomic_counter.fetch_add(1, std::memory_order_relaxed);
        ++counter;
    }
}

int main()
{
    {
        std::vector<std::jthread> pool;
        for (int n = 0; n < 10; ++n)
        {
            pool.emplace_back(f);
        }
    }

    std::cout << "The atomic counter is " << atomic_counter << '\n'
        << "The non-atomic counter is " << counter << '\n';
}
