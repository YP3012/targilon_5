#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

std::mutex m;  // global mutex for cout
void foo(int a) {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::lock_guard<std::mutex> lock(m);  // lock until end of scope
    cout << a << endl;
}
int main() {
    thread threads[20];
    for (int i = 0; i < 20; i++) {
        threads[i] = thread(foo, i);
    }
    for (int i = 0; i < 20; i++) {
        threads[i].join();
    }
}
