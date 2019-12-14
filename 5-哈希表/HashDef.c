#include "HashDef.h"
#include<stdio.h>
#include<stdlib.h>

int hashCode(int key) {
    return key % SIZE;
}

struct DataItem* searchWithKey(int key)
{
    while (hashArray[key] != NULL) {
            return hashArray[key];
    }
    return NULL;
}

struct DataItem* searchWithData(int data)
{
    int hashIndex = hashCode(data);

    while (hashArray[hashIndex] != NULL) {
        if (hashArray[hashIndex]->data == data) {
            return hashArray[hashIndex];
        }

        ++hashIndex;//handle the collision

        hashIndex %= SIZE;
    }
    return NULL;
}

void insert(int data)
{
    int hashIndex = hashCode(data);
    struct DataItem* item = (struct DataItem*)malloc(sizeof(struct DataItem*));
    if (item == NULL)
    {
        return 0;
    }
    item->data = data;
    item->key = hashIndex;


    while (hashArray[hashIndex] != NULL) 
    {
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}


struct DataItem* delete(struct DataItem* item) {
    int key = item->key;

    //get the hash 
    int hashIndex = hashCode(key);

    //move in array until an empty
    while (hashArray[hashIndex] != NULL) {

        if (hashArray[hashIndex]->key == key) {
            hashArray[hashIndex] = NULL;
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void display() {
    int i = 0;

    for (i = 0; i < SIZE; i++) {

        if (hashArray[i] != NULL)
            printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
        else
            printf(" ~~ ");
    }

    printf("\n");
}
