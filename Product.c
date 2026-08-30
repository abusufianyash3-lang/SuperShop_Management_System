#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

Product *createProduct(unsigned int id,
                       const char *name,
                       float price,
                       unsigned int quantity)
{
    Product *newProduct;

    newProduct = (Product *)malloc(sizeof(Product));

    if (newProduct == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newProduct->id = id;
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->quantity = quantity;
    newProduct->next = NULL;

    return newProduct;
}


void addProduct(ProductList *list, Product *product)
{
    if (list == NULL || product == NULL)
    {
        return;
    }

    product->next = list->head;
    list->head = product;

    printf("Product added successfully!\n");
}


Product *findProductById(ProductList *list, unsigned int id)
{
    Product *current;

    if (list == NULL)
    {
        return NULL;
    }

    current = list->head;

    while (current != NULL)
    {
        if (current->id == id)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}


void updateProduct(ProductList *list,
                   unsigned int id,
                   const char *name,
                   float price,
                   unsigned int quantity)
{
    Product *product;

    product = findProductById(list, id);

    if (product == NULL)
    {
        printf("Product not found!\n");
        return;
    }

    strcpy(product->name, name);
    product->price = price;
    product->quantity = quantity;

    printf("Product updated successfully!\n");
}


void deleteProduct(ProductList *list, unsigned int id)
{
    Product *current;
    Product *previous;

    if (list == NULL || list->head == NULL)
    {
        printf("Product list is empty!\n");
        return;
    }

    current = list->head;
    previous = NULL;

    while (current != NULL && current->id != id)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Product not found!\n");
        return;
    }

    if (previous == NULL)
    {
        list->head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    free(current);

    printf("Product deleted successfully!\n");
}


void listProducts(const ProductList *list)
{
    Product *current;

    if (list == NULL || list->head == NULL)
    {
        printf("No products available!\n");
        return;
    }

    current = list->head;

    printf("\n========== PRODUCT LIST ==========\n");

    while (current != NULL)
    {
        printf("ID: %u\n", current->id);
        printf("Name: %s\n", current->name);
        printf("Price: %.2f\n", current->price);
        printf("Quantity: %u\n", current->quantity);
        printf("--------------------------\n");

        current = current->next;
    }
}


void freeProductList(ProductList *list)
{
    Product *current;
    Product *temp;

    if (list == NULL)
    {
        return;
    }

    current = list->head;

    while (current != NULL)
    {
        temp = current;
        current = current->next;

        free(temp);
    }

    list->head = NULL;
}


float getProductPrice(ProductList *list,
                      const char *productName)
{
    Product *current;

    if (list == NULL)
    {
        return 0.0f;
    }

    current = list->head;

    while (current != NULL)
    {
        if (strcmp(current->name, productName) == 0)
        {
            return current->price;
        }

        current = current->next;
    }

    return 0.0f;
}
