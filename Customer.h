 1 #ifndef CUSTOMER_H
 2 #define CUSTOMER_H
 3
 8
 10 #define MAX_CUSTOMERS 100
 11
 13 #define NAME_SIZE 50
 14
 21 typedef struct {
 22 char username[NAME_SIZE]; 
 23 char password[NAME_SIZE]; 
 24 } Customer;
 25
 34 unsigned int registerCustomer(const Customer* customer);
 35
 44 unsigned int loginCustomer(const Customer* customer);
 45
 46 #endif // CUSTOMER_H
