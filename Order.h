#ifndef ORDER_H
 7 #define ORDER_H
 8
 9 #define MAX_ORDERS 100 
 10 #define MAX_ITEMS_PER_ORDER 10 
 11 #define NAME_SIZE 50 
 12
 17 typedef struct {
 18 char customerName[NAME_SIZE]; 
 19 char items[MAX_ITEMS_PER_ORDER][NAME_SIZE]; 
 20 unsigned int itemQuantities[MAX_ITEMS_PER_ORDER]; 
 21 unsigned int itemCount; 
 22 } Order;
 23
 24 struct ProductList; // Forward declaration to avoid circular dependency
 25
 33 void placeOrder(const Order* order);
 34
 40 void viewMyOrders(const char* customerName);
 41
 47 void viewAllCustomerOrders(struct ProductList* products);
 48
 49 #endif
