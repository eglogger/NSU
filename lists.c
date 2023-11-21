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

LIST *findKey(int key, LIST *L) {

    LIST *cur = L;

    while (key != cur -> key)
        cur = cur -> next;

    printf("%d: %f", cur -> key, cur -> value);

    return 0;
}

int elCnt(LIST *L) {

    LIST *cur = L;
    int cnt = 0;

    while (cur -> next) {
        cur = cur -> next;
        cnt++;
    }

    return cnt;
}

void delEvenKeys(LIST *L) {

    LIST *cur = L -> next;
    LIST *last = L;

    while(cur) {

        if (cur -> key % 2 == 0) {

            if (last == L) {
                L = cur -> next;
                free(cur);
                cur = L;
            }

            else {
                last -> next = cur -> next;
                free(cur);
                cur = last -> next;
            }
        }
        else {
            last = cur;
            cur = cur -> next;
        }
    }
    print(L);
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

    // Functions tests:

    /* print(L);

    -----

    printf("| ");

    float t = pop(L);
    printf("%f", t);
    print(L);

    -----

    printf("|");

    LIST *cur = L -> next;
    delete(cur);
    print(L);

    -----

    LIST *cur = last(L);
    LIST *now = create(100, 500);

    insert(cur, now);
    print(L);

    -----

    printf("\nInput key:");
    scanf("%d", &key);
    findKey(key, L);

    print(L);
    elCnt(L);

    ----- */

    delEvenKeys(L);

    return 0;
}
