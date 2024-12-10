#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10  

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hashFunction(int key) {
    return key % TABLE_SIZE; 
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(int key) {
    int index = hashFunction(key);  
    Node* newNode = createNode(key);

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int search(int key) {
    int index = hashFunction(key);  
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key) {
            return 1; 
        }
        temp = temp->next;
    }
    return 0;  
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(15);
    insert(25);
    insert(35);
    insert(7);
    insert(17);
    insert(27);

    printf("Hash Table:\n");
    display();

    int key = 25;
    if (search(key)) {
        printf("\nData %d ditemukan dalam hash table.\n", key);
    } else {
        printf("\nData %d tidak ditemukan dalam hash table.\n", key);
    }

    return 0;
}