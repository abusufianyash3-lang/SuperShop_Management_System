#include <stdio.h>
#include <string.h>
#include "order.h"
#include "product.h"

static Order orderDatabase[MAX_ORDERS];
static unsigned int orderCount = 0;


void placeOrder(const Order *order)
{
    if (orderCount >= MAX_ORDERS)
    {
        printf("Order database is full!\n");
        return;
    }

    orderDatabase[orderCount] = *order;
    orderCount++;

    printf("Order placed successfully!\n");
}


void viewMyOrders(const char *customerName)
{
    unsigned int i;
    unsigned int j;
    unsigned int found = 0;

    printf("\n========== MY ORDERS ==========\n");

    for (i = 0; i < orderCount; i++)
    {
        if (strcmp(orderDatabase[i].customerName,
                   customerName) == 0)
        {
            found = 1;

            printf("\nCustomer: %s\n",
                   orderDatabase[i].customerName);

            printf("Items:\n");

            for (j = 0;
                 j < orderDatabase[i].itemCount;
                 j++)
            {
                printf("%s - Quantity: %u\n",
                       orderDatabase[i].items[j],
                       orderDatabase[i].itemQuantities[j]);
            }
        }
    }

    if (found == 0)
    {
        printf("No orders found!\n");
    }
}


void viewAllCustomerOrders(ProductList *products)
{
    unsigned int i;
    unsigned int j;

    printf("\n===== ALL CUSTOMER ORDERS =====\n");

    for (i = 0; i < orderCount; i++)
    {
        float total = 0.0f;

        printf("\nCustomer: %s\n",
               orderDatabase[i].customerName);

        for (j = 0;
             j < orderDatabase[i].itemCount;
             j++)
        {
            float price;

            price = getProductPrice(
                products,
                orderDatabase[i].items[j]
            );

            total += price *
                     orderDatabase[i].itemQuantities[j];

            printf("%s | Quantity: %u | Price: %.2f\n",
                   orderDatabase[i].items[j],
                   orderDatabase[i].itemQuantities[j],
                   price);
        }

        printf("Total Amount: %.2f\n", total);
    }
}
