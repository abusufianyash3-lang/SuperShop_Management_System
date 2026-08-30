#include <stdio.h>
#include <string.h>

#include "admin.h"
#include "customer.h"
#include "product.h"
#include "order.h"


int main()
{
    ProductList productList;
    unsigned int choice;
    unsigned int loggedIn = 0;

    productList.head = NULL;

    while (1)
    {
        printf("\n=================================\n");
        printf(" SUPERSHOP MANAGEMENT SYSTEM\n");
        printf("=================================\n");

        printf("1. Admin Login\n");
        printf("2. Customer Register\n");
        printf("3. Customer Login\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%u", &choice);


        /* ADMIN LOGIN */

        if (choice == 1)
        {
            Admin admin;
            unsigned int adminChoice;

            printf("Username: ");
            scanf("%49s", admin.username);

            printf("Password: ");
            scanf("%49s", admin.password);

            loggedIn = adminLogin(&admin);

            if (loggedIn == 1)
            {
                printf("\nAdmin Login Successful!\n");

                while (1)
                {
                    printf("\n===== ADMIN PANEL =====\n");

                    printf("1. Add Product\n");
                    printf("2. Update Product\n");
                    printf("3. Delete Product\n");
                    printf("4. View Products\n");
                    printf("5. View All Orders\n");
                    printf("6. Logout\n");

                    printf("Enter choice: ");
                    scanf("%u", &adminChoice);


                    if (adminChoice == 1)
                    {
                        unsigned int id;
                        unsigned int quantity;
                        char name[NAME_SIZE];
                        float price;

                        printf("Product ID: ");
                        scanf("%u", &id);

                        printf("Product Name: ");
                        scanf("%49s", name);

                        printf("Price: ");
                        scanf("%f", &price);

                        printf("Quantity: ");
                        scanf("%u", &quantity);

                        Product *product;

                        product = createProduct(
                            id,
                            name,
                            price,
                            quantity
                        );

                        addProduct(
                            &productList,
                            product
                        );
                    }


                    else if (adminChoice == 2)
                    {
                        unsigned int id;
                        unsigned int quantity;
                        char name[NAME_SIZE];
                        float price;

                        printf("Product ID to update: ");
                        scanf("%u", &id);

                        printf("New Name: ");
                        scanf("%49s", name);

                        printf("New Price: ");
                        scanf("%f", &price);

                        printf("New Quantity: ");
                        scanf("%u", &quantity);

                        updateProduct(
                            &productList,
                            id,
                            name,
                            price,
                            quantity
                        );
                    }


                    else if (adminChoice == 3)
                    {
                        unsigned int id;

                        printf("Product ID to delete: ");
                        scanf("%u", &id);

                        deleteProduct(
                            &productList,
                            id
                        );
                    }


                    else if (adminChoice == 4)
                    {
                        listProducts(
                            &productList
                        );
                    }


                    else if (adminChoice == 5)
                    {
                        viewAllCustomerOrders(
                            &productList
                        );
                    }


                    else if (adminChoice == 6)
                    {
                        printf("Admin logged out!\n");
                        break;
                    }
                }
            }
            else
            {
                printf("Invalid Admin Credentials!\n");
            }
        }


        /* CUSTOMER REGISTER */

        else if (choice == 2)
        {
            Customer customer;

            printf("Enter Username: ");
            scanf("%49s", customer.username);

            printf("Enter Password: ");
            scanf("%49s", customer.password);

            registerCustomer(&customer);
        }


        /* CUSTOMER LOGIN */

        else if (choice == 3)
        {
            Customer customer;

            printf("Username: ");
            scanf("%49s", customer.username);

            printf("Password: ");
            scanf("%49s", customer.password);

            loggedIn = loginCustomer(&customer);

            if (loggedIn == 1)
            {
                unsigned int customerChoice;

                printf("\nCustomer Login Successful!\n");

                while (1)
                {
                    printf("\n===== CUSTOMER PANEL =====\n");

                    printf("1. View Products\n");
                    printf("2. Place Order\n");
                    printf("3. View My Orders\n");
                    printf("4. Logout\n");

                    printf("Enter choice: ");
                    scanf("%u", &customerChoice);


                    if (customerChoice == 1)
                    {
                        listProducts(
                            &productList
                        );
                    }


                    else if (customerChoice == 2)
                    {
                        Order order;
                        unsigned int i;

                        strcpy(
                            order.customerName,
                            customer.username
                        );

                        printf("How many items? ");
                        scanf(
                            "%u",
                            &order.itemCount
                        );

                        if (order.itemCount >
                            MAX_ITEMS_PER_ORDER)
                        {
                            order.itemCount =
                                MAX_ITEMS_PER_ORDER;
                        }

                        for (i = 0;
                             i < order.itemCount;
                             i++)
                        {
                            printf(
                                "Product Name %u: ",
                                i + 1
                            );

                            scanf(
                                "%49s",
                                order.items[i]
                            );

                            printf(
                                "Quantity: "
                            );

                            scanf(
                                "%u",
                                &order.itemQuantities[i]
                            );
                        }

                        placeOrder(&order);
                    }


                    else if (customerChoice == 3)
                    {
                        viewMyOrders(
                            customer.username
                        );
                    }


                    else if (customerChoice == 4)
                    {
                        printf(
                            "Customer logged out!\n"
                        );

                        break;
                    }
                }
            }
            else
            {
                printf(
                    "Invalid Customer Credentials!\n"
                );
            }
        }


        /* EXIT */

        else if (choice == 4)
        {
            printf(
                "Thank you for using Supershop Management System!\n"
            );

            break;
        }


        else
        {
            printf(
                "Invalid choice!\n"
            );
        }
    }

    freeProductList(&productList);

    return 0;
}
