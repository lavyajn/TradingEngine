#include <iostream>
#include "OrderPool.h"

int main() {
    std::cout << "--- Starting Order Matching Engine Test ---" << std::endl;

    // 1. Initialize the Pool with 10 pre-allocated orders
    OrderPool pool(10);
    std::cout << "OrderPool initialized with 10 slots." << std::endl;

    // 2. Acquire an order from the pool
    Order* myOrder = pool.getOrder();
    
    if (myOrder) {
        myOrder->id = 101;
        myOrder->price = 50000; // e.g., $500.00
        myOrder->qty = 10;
        myOrder->isBuy = true;

        std::cout << "Acquired Order ID: " << myOrder->id << std::endl;
        std::cout << "Price: " << myOrder->price << " | Qty: " << myOrder->qty << std::endl;
    }

    // 3. Release the order back to the pool (recycling memory)
    pool.releaseOrder(myOrder);
    std::cout << "Order released back to pool." << std::endl;

    // 4. Prove we can get it again
    Order* recycledOrder = pool.getOrder();
    std::cout << "Re-acquired order from pool. New ID (should be 0 after reset): " << recycledOrder->id << std::endl;

    return 0;
}