#include <stdio.h>

#ifdef _WIN32
#include <direct.h>
#define make_dir(path) _mkdir(path)
#else
#include <sys/stat.h>
#define make_dir(path) mkdir(path, S_IRWXU)
#endif

#include "io.h"
#include <errno.h>
#include <string.h>

void ensureDirectoryExists(const char *filename) {
  char path[512];
  strncpy(path, filename, sizeof(path) - 1);
  path[sizeof(path) - 1] = '\0';

  // Find the last occurrence of the directory separator
  char *last_slash = strrchr(path, '/');

  if (last_slash != NULL) {
    // Terminate the string at the last slash to get just the directory path
    *last_slash = '\0';

    // Now 'path' contains only the directory part
    if (mkdir(path, S_IRWXU) == -1) {
      if (errno != EEXIST) {
        // If it fails for reasons other than "already exists", log it
      }
    }
  }
}

int loadInventory(Product *inventory, const char *filename) {
  FILE *file = fopen(filename, "r");
  if (!file) {
    printf("No existing database found. Starting fresh.\n");
    return 0;
  }

  int count = 0;
  while (fscanf(file, "%d,%[^,],%f,%d\n", &inventory[count].id,
                inventory[count].name, &inventory[count].price,
                &inventory[count].quantity) == 4) {
    count++;
    if (count >= MAX_ITEMS)
      break;
  }

  fclose(file);
  return count;
}

void saveInventory(const Product *inventory, int count, const char *filename) {
  ensureDirectoryExists(filename);

  FILE *file = fopen(filename, "w");
  if (!file) {
    perror("Error creating file");
    return;
  }

  for (int i = 0; i < count; i++) {
    fprintf(file, "%d,%s,%.2f,%d\n", inventory[i].id, inventory[i].name,
            inventory[i].price, inventory[i].quantity);
  }

  fclose(file);
}
