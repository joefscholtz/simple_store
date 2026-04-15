#include "store.h"
#include <stdio.h>
#include <string.h>

void addProduct(Product *inventory, int *count) {
  if (*count >= MAX_ITEMS) {
    printf("Error: Inventory full!\n");
    return;
  }

  // Product produto;
  // produto.id;
  // produto.price;

  Product *p = &inventory[*count];
  //(*p).id;
  p->id = *count + 1;

  printf("Enter product name: ");
  scanf("%s", p->name);
  printf("Enter price: ");
  scanf("%f", &p->price);
  printf("Enter quantity: ");
  scanf("%d", &p->quantity);

  (*count)++;
  printf("Product added successfully!\n");
}

void removeProductByName(Product *inventory, int *count, const char *name) {
  int foundIndex = -1;

  // Find the item
  for (int i = 0; i < *count; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      foundIndex = i;
      break;
    }
  }

  if (foundIndex == -1) {
    printf("Product '%s' not found.\n", name);
    return;
  }

  // Shift remaining items to the left to fill the gap
  for (int i = foundIndex; i < (*count) - 1; i++) {
    inventory[i] = inventory[i + 1];
  }

  (*count)--;
  printf("Product '%s' removed.\n", name);
}

void displayInventory(const Product *inventory, int count) {
  if (count < 1) {
    printf("\n--- Inventory Empty ---\n");
    return;
  }
  printf("\n--- Current Inventory ---\n");
  for (int i = 0; i < count; i++) {
    printf("ID: %d | Name: %s | Price: %.2f | Qty: %d\n", inventory[i].id,
           inventory[i].name, inventory[i].price, inventory[i].quantity);
  }
}

Product *findProduct(Product *inventory, int count, int id) {
  for (int i = 0; i < count; i++) {
    if (inventory[i].id == id) {
      return &inventory[i];
    }
  }
  return NULL;
}
