#ifndef PRICE_LEVEL_H
#define PRICE_LEVEL_H

#include "Order.h"
// implementing a doubly linked list queue to manage order at proce level,for efficient addition adn removal of orders without needing to shift index-wise
struct PriceLevel {
    uint64_t price;
    Order* head = nullptr; // order at the head of the line
    Order* tail = nullptr; // order at the tail of the line

    // function to add new order to the back
    void addOrder(Order* newOrder) {
        if(head == nullptr) {
            head = tail = newOrder;
            newOrder->next = nullptr;
            newOrder->prev = nullptr;
        }else {
            tail->next = newOrder;
            newOrder->prev = tail;
            newOrder->next = nullptr;
            tail = newOrder;
        }
        }
    // function to remove order from the front
    void removeOrder(Order* order) {

        


    }
    };
#endif