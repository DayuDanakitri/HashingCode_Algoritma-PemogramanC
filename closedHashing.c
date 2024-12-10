#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
} HashEntry;

HashEntry* hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);
    int originalIndex = index;
    HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
    if (!newEntry) {
        printf("Memory allocation failed!\n");
        return;
    }
    newEntry->key = key;
    newEntry->value = value;

    while (hashTable[index] != NULL && hashTable[index]->key != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) { 
            printf("Hash table is full! Cannot insert (%d, %d)\n", key, value);
            free(newEntry);
            return;
        }
    }
    hashTable[index] = newEntry; 
    printf("Inserted (%d, %d) at index %d\n", key, value, index);
}

void displayTable() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == NULL || hashTable[i]->key == -1) {
            printf("[%d] : NULL\n", i);
        } else {
            printf("[%d] : (%d, %d)\n", i, hashTable[i]->key, hashTable[i]->value);
        }
    }
}

int main() {
    initializeTable();

    insert(5, 50);
    insert(15, 150);
    insert(25, 250);
    insert(35, 350);
    insert(45, 450);

    displayTable();

    insert(55, 550);

    displayTable();

    return 0;
}
