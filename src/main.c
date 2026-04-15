#include "io.h"
#include "store.h"
#include <stdio.h>

#define DATA_FILE "data/inventory.csv"

int main() {
  char full_path[512];
  snprintf(full_path, sizeof(full_path), "%s/%s", PROJECT_ROOT_PATH, DATA_FILE);

  Product inventory[MAX_ITEMS];
  int count = loadInventory(inventory, full_path);
  int choice;
  char name[MAX_NAME];

  printf("Loaded %d items from database.\n", count);

  while (1) {
    printf("\n1. Add Item | 2. View inventory | 3. Remove Item by Name | 4. "
           "Exit\nChoice: ");

    if (scanf("%d", &choice) != 1) {
      // clear the invalid input from the buffer
      int c;
      while ((c = getchar()) != '\n' && c != EOF) {
      }
      // inform the user and continue the loop
      printf("Invalid input! Please enter a number.\n");
      continue;
    }

    // if (choice == 1) {
    // } else if (choice == 2) {
    // } else if (choice == 3) {
    // } else if (choice == 4) {
    // } else {
    // }

    switch (choice) {
    case 1:
      addProduct(inventory, &count);
      saveInventory(inventory, count, full_path);
      break;
    case 2:
      displayInventory(inventory, count);
      break;
    case 3:
      printf("Enter name to remove: ");
      scanf("%s", name);
      removeProductByName(inventory, &count, name);
      saveInventory(inventory, count, full_path);
      break;
    case 4:
      saveInventory(inventory, count, full_path);
      return 0;
    default:
      printf("No matching choice");
      break;
    }
  }
  return 0;
}
