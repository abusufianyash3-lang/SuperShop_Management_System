 1 #ifndef PRODUCT_H
 7 #define PRODUCT_H
 8
 9 #define NAME_SIZE 50
 10
 17 typedef struct Product {
 18 unsigned int id; 
 19 char name[NAME_SIZE]; 
 20 float price; 
 21 unsigned int quantity; 
 22 struct Product* next; 
 23 } Product;
 24
 29 typedef struct {
 30 Product* head; 
 31 } ProductList;
 32
 42 Product* createProduct(unsigned int id, const char* name, float price, unsigned int
quantity);
 43
 50 void addProduct(ProductList* list, Product* product);
 51
 59 Product* findProductById(ProductList* list, unsigned int id);
 60
 70 void updateProduct(ProductList* list, unsigned int id, const char* name, float price, 
unsigned int quantity);
 71
 78 void deleteProduct(ProductList* list, unsigned int id);
 79
 85 void listProducts(const ProductList* list);
 86
 92 void freeProductList(ProductList* list);
 93
 101 float getProductPrice(ProductList* list, const char* productName);
 102
 103 #endif // PRODUCT_H
