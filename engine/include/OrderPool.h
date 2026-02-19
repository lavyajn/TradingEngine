#ifndef ORDER_POOL_H
# define ORDER_POOL_H

#include <vector>
#include <cstdint>
using namespace std;

struct Order {
    uint64_t id;
    uint64_t price;
    uint32_t qty;
    bool isBuy;

    Order* next = nullptr;
    Order* prev = nullptr;
}

class OrderPool {
    private:
    vector <Order> pool;
    vector <Order*> freeList;

    public:
    OrderPool(size_t size) {
        pool.resize(size);
        freeList.reserve(size);

        for(size_t i = 0; i<size; ++i) {
            freeList.push_back(&pool[i]);
        }
    }
    Order* getOrder() {
        if(freeList.empty()) {
            return nullptr;
        }
        
    }
}