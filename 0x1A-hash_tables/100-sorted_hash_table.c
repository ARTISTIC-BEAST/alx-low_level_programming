0x1A. C - Hash tables
hash_tables.h


#ifndef _HASH_TABLES_H_

#define _HASH_TABLES_H_


#include <stdlib.h>

#include <string.h>

#include <stdio.h>

/**

 * struct hash_node_s - Node of a hash table

 *

 * @key: The key, string

 * The key is unique in the HashTable

 * @value: The value corresponding to a key

 * @next: A pointer to the next node of the List

 */

typedef struct hash_node_s

{

         char *key;

         char *value;

         struct hash_node_s *next;

} hash_node_t;


/**

 * struct hash_table_s - Hash table data structure

 *

 * @size: The size of the array

 * @array: An array of size @size

 * Each cell of this array is a pointer to the first node of a linked list,

 * because we want our HashTable to use a Chaining collision handling

 */

typedef struct hash_table_s

{

         unsigned long int size;

         hash_node_t **array;

} hash_table_t;


/*functions*/

hash_table_t *hash_table_create(unsigned long int size);

unsigned long int hash_djb2(const unsigned char *str);

unsigned long int key_index(const unsigned char *key, unsigned long int size);

int hash_table_set(hash_table_t *ht, const char *key, const char *value);

char *hash_table_get(const hash_table_t *ht, const char *key);

void hash_table_print(const hash_table_t *ht);

void hash_table_delete(hash_table_t *ht);


/**

 * struct shash_node_s - Node of a sorted hash table

 *

 * @key: The key, string

 * The key is unique in the HashTable

 * @value: The value corresponding to a key

 * @next: A pointer to the next node of the List

 * @sprev: A pointer to the previous element of the sorted linked list

 * @snext: A pointer to the next element of the sorted linked list

 */

typedef struct shash_node_s

{

        char *key;

        char *value;

        struct shash_node_s *next;

        struct shash_node_s *sprev;

        struct shash_node_s *snext;

} shash_node_t;


/**

 * struct shash_table_s - Sorted hash table data structure

 *

 * @size: The size of the array

 * @array: An array of size @size

 * Each cell of this array is a pointer to the first node of a linked list,

 * because we want our HashTable to use a Chaining collision handling

 * @shead: A pointer to the first element of the sorted linked list

 * @stail: A pointer to the last element of the sorted linked list

 */

typedef struct shash_table_s

{

        unsigned long int size;

        shash_node_t **array;

        shash_node_t *shead;

        shash_node_t *stail;

} shash_table_t;


shash_table_t *shash_table_create(unsigned long int size);

int shash_table_set(shash_table_t *ht, const char *key, const char *value);

void shash_table_print(const shash_table_t *ht);

char *shash_table_get(const shash_table_t *ht, const char *key);

void shash_table_print_rev(const shash_table_t *ht);

void shash_table_delete(shash_table_t *ht);

#endif /*_HASH_TABLES_H_*/




________________________________




0-main.c


#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "hash_tables.h"


/**

 * main - check the code for

 *

 * Return: Always EXIT_SUCCESS.

 */

int main(void)

{

    hash_table_t *ht;


    ht = hash_table_create(1024);

    printf("%p\n", (void *)ht);

    return (EXIT_SUCCESS);

}



________________________________



0-hash_table_create.c


#include "hash_tables.h"


/**

 * hash_table_create - creates a hash table

 * @size: size of the hash table

 *

 * Return: pointer to hash table

 */


hash_table_t *hash_table_create(unsigned long int size)

{

        hash_table_t *table;


        if (size == 0)

                return (NULL);


        table = calloc(1, sizeof(hash_table_t));

        if (table == NULL)

                return (NULL);


        table->size = size;

        table->array = calloc(size, sizeof(hash_node_t *));

        if (table->array == NULL)

        {

                free(table);

                return (NULL);

        }

        return (table);

}



________________________________




1-djb2.c


#include "hash_tables.h"


/**

 * hash_djb2 - function to compute hash of 'str' using djb2

 * @str: string to hash

 *

 * Return: value of 64 bits hash

 */


unsigned long int hash_djb2(const unsigned char *str)

{

        unsigned long int hash;

        int c;


        hash = 5381;

        while ((c = *str++))

        {

                hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        }

        return (hash);

}



________________________________



1-main.c


#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "hash_tables.h"


/**

 * main - check the code

 *

 * Return: Always EXIT_SUCCESS.

 */

int main(void)

{

    char *s;


    s = "cisfun";

    printf("%lu\n", hash_djb2((unsigned char *)s));

    s = "Don't forget to tweet today";

    printf("%lu\n", hash_djb2((unsigned char *)s));

    s = "98";

    printf("%lu\n", hash_djb2((unsigned char *)s));

    return (EXIT_SUCCESS);

}



________________________________



100-main.c



#include <stdlib.h>

#include <string.h>

#include <stdio.h>

#include "hash_tables.h"


/**

 * main - check the code

 *

 * Return: Always EXIT_SUCCESS.

 */

int main(void)

{

    shash_table_t *ht;


    ht = shash_table_create(1024);

    shash_table_set(ht, "y", "0");

    shash_table_print(ht);

    shash_table_set(ht, "j", "1");

    shash_table_print(ht);

    shash_table_set(ht, "c", "2");

    shash_table_print(ht);

    shash_table_set(ht, "b", "3");

    shash_table_print(ht);

    shash_table_set(ht, "z", "4");

    shash_table_print(ht);

    shash_table_set(ht, "n", "5");

    shash_table_print(ht);

    shash_table_set(ht, "a", "6");

    shash_table_print(ht);

    shash_table_set(ht, "m", "7");

    shash_table_print(ht);

    shash_table_print_rev(ht);

        shash_table_delete(ht);

    return (EXIT_SUCCESS);

}



________________________________



100-sorted_hash_table.c



#include "hash_tables.h"


/**

 * sorted_list - function for insert new node in sorted

 * @ht: pointer to sorted hash table

 * @new_node: pew node to insert

 *

 */

void sorted_list(shash_table_t *ht, shash_node_t *new_node)

{

        shash_node_t *sbucket = ht->shead;


        if (sbucket == NULL)

        {

                ht->shead = ht->stail = new_node;

                new_node->snext = new_node->sprev = NULL;

                return;

        }

        do {

                if (strcmp(new_node->key, sbucket->key) < 0)

                {

                        new_node->snext = sbucket;

                        new_node->sprev = sbucket->sprev;


                        if (!sbucket->sprev)

                                ht->shead = new_node;

                        else

                                sbucket->sprev->snext = new_node;

                        sbucket->sprev = new_node;

                        return;

                }

                sbucket = sbucket->snext;

        } while (sbucket);

        new_node->sprev = ht->stail;

        new_node->snext = ht->stail->snext;

        ht->stail->snext = new_node;

        ht->stail = new_node;

}


/**

 * shash_table_create - creates a sorted hash tables

 * @size: size of the hash table

 *

 * Return: pointer to hash table

 */

shash_table_t *shash_table_create(unsigned long int size)

{

        shash_table_t *table;


        if (size == 0)

                return (NULL);


        table = calloc(1, sizeof(shash_table_t));

        if (table == NULL)

                return (NULL);


        table->size = size;

        table->array = calloc(size, sizeof(shash_node_t *));

        if (table->array == NULL)

        {

                free(table);

                return (NULL);

        }

        return (table);

}


/**

 * shash_table_set - function that adds an element to the sorted hash table

 * @ht: pointer to sorted hash table

 * @key: key to add the element

 * @value: value to add the element

 *

 * Return: 1 if it succeeded, 0 otherwise

 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)

{

        unsigned long int index = 0;

        char *valuecopy, *keycopy;

        shash_node_t  *bucket, *new_node;


        if (!ht || !key || !*key || !value)

                return (0);

        valuecopy = strdup(value);

        if (!valuecopy)

                return (0);

        index = key_index((const unsigned char *)key, ht->size);

        bucket = ht->array[index];


        while (bucket)

        {

                if (!strcmp(key, bucket->key))

                {

                        free(bucket->value);

                        bucket->value = valuecopy;

                        return (1);

                }

                bucket = bucket->next;

        }

        new_node = calloc(1, sizeof(shash_node_t));

        if (new_node == NULL)

        {

                free(valuecopy);

                return (0);

        }

        keycopy = strdup(key);

        if (!keycopy)

                return (0);

        new_node->key = keycopy;

        new_node->value = valuecopy;

        new_node->next = ht->array[index];

        ht->array[index] = new_node;

        sorted_list(ht, new_node);

        return (1);

}

/**

 * shash_table_get - function to retrieve value associeted with key

 * @ht: pointer to hash table

 * @key: key to retrive value

 *

 * Return: value or NULL if key does not exit.

 */

char *shash_table_get(const shash_table_t *ht, const char *key)

{

        unsigned long int index = 0;

        shash_node_t  *bucket;


        if (!ht || !key || !*key)

                return (NULL);

        index = key_index((const unsigned char *)key, ht->size);

        bucket = ht->array[index];

        while (bucket)

        {

                if (!strcmp(key, bucket->key))

                        return (bucket->value);

                bucket = bucket->next;

        }

        return (NULL);

}


/**

 * shash_table_print - function to print the key:value from ht

 * @ht: pointer to hash table

 *

 */

void shash_table_print(const shash_table_t *ht)

{

        shash_node_t *bucket;

        int not_fin = 0;


        if (!ht)

                return;

        bucket = ht->shead;

        printf("{");

        while (bucket)

        {

                if (not_fin)

                        printf(", ");

                printf("'%s': '%s'", bucket->key, bucket->value);

                not_fin = 1;

                bucket = bucket->snext;

        }

        printf("}\n");

}

/**

 * shash_table_print_rev - function to print the key:value from ht in reverse

 * @ht: pointer to hash table

 *

 */

void shash_table_print_rev(const shash_table_t *ht)

{

        shash_node_t *bucket;

        int not_fin = 0;


        if (!ht)

                return;

        bucket = ht->stail;

        printf("{");

        while (bucket)

        {

                if (not_fin)

                        printf(", ");

                printf("'%s': '%s'", bucket->key, bucket->value);

                not_fin = 1;

                bucket = bucket->sprev;

        }

        printf("}\n");

}

/**

 * shash_table_delete - free hash table and all nodes

 * @ht: pointer to hash table

 *

 */

void shash_table_delete(shash_table_t *ht)

{

        shash_node_t *bucket, *aux_free;

        unsigned long int i = 0;


        if (!ht)

                return;


        for (i = 0; i < ht->size; i++)

        {

                bucket = ht->array[i];

                while (bucket)

                {

                        aux_free = bucket;

                        bucket = bucket->next;

                        if (aux_free->key)

                                free(aux_free->key);

                        if (aux_free->value)

                                free(aux_free->value);

                        free(aux_free);

                }

        }

        free(ht->array);

        free(ht);

}



________________________________




100-sorted_hash_table.c




#include "hash_tables.h"


/**

 * sorted_list - function for insert new node in sorted

 * @ht: pointer to sorted hash table

 * @new_node: pew node to insert

 *

 */

void sorted_list(shash_table_t *ht, shash_node_t *new_node)

{

        shash_node_t *sbucket = ht->shead;


        if (sbucket == NULL)

        {

                ht->shead = ht->stail = new_node;

                new_node->snext = new_node->sprev = NULL;

                return;

        }

        do {

                if (strcmp(new_node->key, sbucket->key) < 0)

                {

                        new_node->snext = sbucket;

                        new_node->sprev = sbucket->sprev;


                        if (!sbucket->sprev)

                                ht->shead = new_node;

                        else

                                sbucket->sprev->snext = new_node;

                        sbucket->sprev = new_node;

                        return;

                }

                sbucket = sbucket->snext;

        } while (sbucket);

        new_node->sprev = ht->stail;

        new_node->snext = ht->stail->snext;

        ht->stail->snext = new_node;

        ht->stail = new_node;

}


/**

 * shash_table_create - creates a sorted hash tables

 * @size: size of the hash table

 *

 * Return: pointer to hash table

 */

shash_table_t *shash_table_create(unsigned long int size)

{

        shash_table_t *table;


        if (size == 0)

                return (NULL);


        table = calloc(1, sizeof(shash_table_t));

        if (table == NULL)

                return (NULL);


        table->size = size;

        table->array = calloc(size, sizeof(shash_node_t *));

        if (table->array == NULL)

        {

                free(table);

                return (NULL);

        }

        return (table);

}


/**

 * shash_table_set - function that adds an element to the sorted hash table

 * @ht: pointer to sorted hash table

 * @key: key to add the element

 * @value: value to add the element

 *

 * Return: 1 if it succeeded, 0 otherwise

 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)

{

        unsigned long int index = 0;

        char *valuecopy, *keycopy;

        shash_node_t  *bucket, *new_node;


        if (!ht || !key || !*key || !value)

                return (0);

        valuecopy = strdup(value);

        if (!valuecopy)

                return (0);

        index = key_index((const unsigned char *)key, ht->size);

        bucket = ht->array[index];


        while (bucket)

        {

                if (!strcmp(key, bucket->key))

                {

                        free(bucket->value);

                        bucket->value = valuecopy;

                        return (1);

                }

                bucket = bucket->next;

        }

        new_node = calloc(1, sizeof(shash_node_t));

        if (new_node == NULL)

        {

                free(valuecopy);

                return (0);

        }

        keycopy = strdup(key);

        if (!keycopy)

                return (0);

        new_node->key = keycopy;

        new_node->value = valuecopy;

        new_node->next = ht->array[index];

        ht->array[index] = new_node;

        sorted_list(ht, new_node);

        return (1);

}

/**

 * shash_table_get - function to retrieve value associeted with key

 * @ht: pointer to hash table

 * @key: key to retrive value

 *

 * Return: value or NULL if key does not exit.

 */

char *shash_table_get(const shash_table_t *ht, const char *key)

{

        unsigned long int index = 0;

        shash_node_t  *bucket;


        if (!ht || !key || !*key)

                return (NULL);

        index = key_index((const unsigned char *)key, ht->size);

        bucket = ht->array[index];

        while (bucket)

        {

                if (!strcmp(key, bucket->key))

                        return (bucket->value);

                bucket = bucket->next;

        }

        return (NULL);

}


/**

 * shash_table_print - function to print the key:value from ht

 * @ht: pointer to hash table

 *

 */

void shash_table_print(const shash_table_t *ht)

{

        shash_node_t *bucket;

        int not_fin = 0;


        if (!ht)

                return;

        bucket = ht->shead;

        printf("{");

        while (bucket)

        {

                if (not_fin)

                        printf(", ");

                printf("'%s': '%s'", bucket->key, bucket->value);

                not_fin = 1;

                bucket = bucket->snext;

        }

        printf("}\n");

}

/**

 * shash_table_print_rev - function to print the key:value from ht in reverse

 * @ht: pointer to hash table

 *

 */

void shash_table_print_rev(const shash_table_t *ht)

{

        shash_node_t *bucket;

        int not_fin = 0;


        if (!ht)

                return;

        bucket = ht->stail;

        printf("{");

        while (bucket)

        {

                if (not_fin)

                        printf(", ");

                printf("'%s': '%s'", bucket->key, bucket->value);

                not_fin = 1;

                bucket = bucket->sprev;

        }

        printf("}\n");

}

/**

 * shash_table_delete - free hash table and all nodes

 * @ht: pointer to hash table

 *

 */

void shash_table_delete(shash_table_t *ht)

{

        shash_node_t *bucket, *aux_free;

        unsigned long int i = 0;


        if (!ht)

                return;


        for (i = 0; i < ht->size; i++)

        {

                bucket = ht->array[i];

                while (bucket)

                {

                        aux_free = bucket;

                        bucket = bucket->next;

                        if (aux_free->key)

                                free(aux_free->key);

                        if (aux_free->value)

                                free(aux_free->value);

                        free(aux_free);

                }

        }

        free(ht->array);

        free(ht);

}
