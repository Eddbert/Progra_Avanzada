#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#define HASH_DEBUG "HASH_DEBUG"

void printDebug(char *msg) {
    char *hashDebug = getenv(HASH_DEBUG);
    if(hashDebug != NULL && strcmp(hashDebug,"y") == 0) {
        printf("%s\n",msg);
    }
}

unsigned long
doHash(unsigned char *str, unsigned size)
{
    unsigned hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash%size;
}

void hashInit(HashInt *hash, int size) 
{
    hash->size = size;
    hash->data = (HashElement *)calloc(size,sizeof(HashElement));
}

static void hashDoInsert(HashInt *hash, char *key, int value)
{
    char errorMessage[255];
    printDebug("dohash");
    unsigned index = doHash(key,hash->size);
    printDebug("dohash2");
    HashElement *currentHashElements = &(hash->data[index]);
    sprintf(errorMessage,"index %d", index);
    printDebug(errorMessage);
    if( currentHashElements->elements == NULL ) 
    {
        printDebug("CHECKING DATA");
        currentHashElements->elements = (Element *)malloc(2*sizeof(Element));
        currentHashElements->count = 0;
        currentHashElements->length = 2;
    }
    if( currentHashElements->length == currentHashElements->count ) 
    {
        currentHashElements->length *= 2;
        currentHashElements->elements = (Element *)realloc(currentHashElements->elements,
                                                          currentHashElements->length * sizeof(Element));
    }
    printDebug("Assigning");
    currentHashElements->elements[currentHashElements->count].key = strdup(key);
    currentHashElements->elements[currentHashElements->count].value = value;
    currentHashElements->count += 1;
    printDebug("Completed");
}

static void hashDoUpdate(HashInt *hash, char *key, int value)
{
    int pos = doHash(key, hash->size);
    int i;
    Element *currentElements = hash->data[pos].elements;
    int currentElementsLength = hash->data[pos].count;

    for(i=0;i < currentElementsLength; i++) {
        if(strcmp(key,currentElements[i].key) == 0) {
            currentElements[i].value = value;
            break;
        }
    }
}
void hashInsert(HashInt *hash, char *key, int value)
{
    int * oldValue = hashGet(hash, key);
    if(oldValue == NULL) {
        hashDoInsert(hash,key,value);
    }
    else {
        hashDoUpdate(hash,key,value);
    }
}

int* hashGet(HashInt *hash, char *key) {
    int pos = doHash(key, hash->size);
    int i;
    Element *currentElements = hash->data[pos].elements;
    int currentElementsLength = hash->data[pos].count;
    int *value = NULL;
    for(i=0;i < currentElementsLength; i++) {
        if(strcmp(key,currentElements[i].key) == 0) {
            value = (int*)malloc(sizeof(int));
            *value = currentElements[i].value;
            break;
        }
    }
    return value;
}