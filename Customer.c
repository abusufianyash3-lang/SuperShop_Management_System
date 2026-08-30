#include <stdio.h>
#include <string.h>
#include "customer.h"

static Customer customerDatabase[MAX_CUSTOMERS];
static unsigned int customerCount = 0;

unsigned int registerCustomer(const Customer *customer)
{
    unsigned int i;

    if (customerCount >= MAX_CUSTOMERS)
    {
        printf("Customer database is full!\n");
        return 0;
    }

    for (i = 0; i < customerCount; i++)
    {
        if (strcmp(customerDatabase[i].username,
                   customer->username) == 0)
        {
            printf("Username already exists!\n");
            return 0;
        }
    }

    customerDatabase[customerCount] = *customer;
    customerCount++;

    printf("Customer registered successfully!\n");

    return 1;
}

unsigned int loginCustomer(const Customer *customer)
{
    unsigned int i;

    for (i = 0; i < customerCount; i++)
    {
        if (strcmp(customerDatabase[i].username,
                   customer->username) == 0 &&
            strcmp(customerDatabase[i].password,
                   customer->password) == 0)
        {
            return 1;
        }
    }

    return 0;
}
