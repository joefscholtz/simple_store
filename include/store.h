#ifndef STORE_H
#define STORE_H

#define MAX_NAME 100
#define MAX_ITEMS 500

// typedef double Vector3d[3];

typedef struct {
  int id;
  char name[MAX_NAME];
  float price;
  int quantity;
} Product;

void addProduct(Product *inventory, int *count);
void removeProductByName(Product *inventory, int *count, const char *name);
void displayInventory(const Product *inventory, int count);
Product *findProduct(Product *inventory, int count, int id);

#endif
