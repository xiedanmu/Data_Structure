#pragma once
#define SIZE 20

struct DataItem {
    int data;
    int key;
};

struct DataItem* hashArray[SIZE];
struct DataItem* dummyItem;
struct DataItem* item;

int hashCode(int key);
struct DataItem* searchWithKey(int key);
struct DataItem* searchWithData(int data);

void insert(int data);
struct DataItem* delete(struct DataItem* item);
void display();