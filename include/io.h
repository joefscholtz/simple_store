#ifndef IO_H
#define IO_H

#include "store.h"

void ensureDirectoryExists(const char *path);
int loadInventory(Product *inventory, const char *filename);
void saveInventory(const Product *inventory, int count, const char *filename);

#endif
