#ifndef ORDER_H
#define ORDER_H
#include <cstdint>

enum class Side : uint8_t {
    BUY = 0, 
    SELL = 1
};

struct Order {
    uint64_t id;
    uint64_t price;
    uint32_t quantity;
    Side side;
    uint64_t timestamp;

    Order* next = nullptr;
    Order* prev = nullptr;

    void reset() {
    id = 0;
    price = 0;
    quantity = 0;
    timestamp = 0;
    next = nullptr;
    prev = nullptr;
}
};
#endif 


