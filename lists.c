#include <stdio.h>
#include <malloc.h>

#define LIST struct list

LIST {
    int key;
    float value;
    LIST * next;
};

LIST* create(int key, float value) {

    LIST * elem;
    elem = (LIST*)malloc(sizeof(LIST));

    elem -> key = key;
    elem -> value = value;
    elem -> next = NULL;

    return elem;
}

void push(LIST *L, LIST *elem) {

    LIST *first = L -> next;

    elem -> next = first;
    L -> next = elem;
}

void print(LIST *L) {

    LIST *ptr = L -> next;

    while (ptr != NULL) {
        printf("%d: %f ", ptr -> key, ptr -> value);
        ptr = ptr -> next;
    }
}

int empty(LIST *L) {

    if (L -> next)
        return 0;

    return 1;
}

float pop(LIST *L) {

    if (!empty(L)) {
        LIST *old = L -> next;
        L -> next = old -> next;
        float r = old -> value;
        free(old);
        return r;
    }

    return 0;
}

void delete(LIST *pre) {

    LIST *d = pre -> next;

    if(d) {
        pre -> next = d -> next;
        free(d);
    }
}

void insert(LIST *pre, LIST *ptr) {

    ptr -> next = pre -> next;
    pre -> next = ptr;
}


LIST *last(LIST *L) {

    LIST *cur = L;

    while (cur -> next)
        cur = cur -> next;

    return cur;
}


int main() {

    LIST *L;
    L = create(0, 0);
    int n, key;
    float value;

    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        scanf("%f", &value);
        LIST *p;
        p = create(key, value);
        push(L, p);
    }

    /* print(L);

    printf("| ");

    float t = pop(L);
    printf("%f", t);
    print(L);

    printf("|");

    LIST *cur = L -> next;
    delete(cur);
    print(L); */

    LIST *cur = last(L);
    LIST *now = create(100, 500);

    insert(cur, now);
    print(L);

    return 0;
}
