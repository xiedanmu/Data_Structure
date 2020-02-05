#include "HashDef.h"
#include<stdio.h>
#include<stdlib.h>

int main() {

    insert(0);
    insert(0);
    insert(80);
    insert(5);
    insert(44);
    insert(32);
    insert(11);
    insert(78);
    insert(397);

    display();
    item = searchWithData(397);

    if (item != NULL) {
        printf("Element found: %d,key is:%d\n", item->data,item->key);
    }
    else {
        printf("Element not found\n");
    }

    delete(item);
    item = searchWithKey(12);

    if (item != NULL) {
        printf("Element found: %d,key is:%d\n", item->data, item->key);
    }
    else {
        printf("Element not found\n");
    }

    system("pause");
    return 0;
}