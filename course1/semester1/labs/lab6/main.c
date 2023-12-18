#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TREE struct tree

TREE {

    int key;
    char question[100];

    TREE* left;
    TREE* right;
};


TREE* newNode(int key, char* question) {

    TREE* node = (TREE*)malloc(sizeof(TREE));

    node -> key = key;
    strcpy(node -> question, question);

    node -> left = NULL;
    node -> right = NULL;

    return node;
}

TREE* insert(TREE* node, int key, char* question) {

    if (node == NULL)
        return newNode(key, question);

    if (key < node -> key)
        node -> left = insert(node -> left, key, question);

    else if (key > node->key)
        node -> right = insert(node -> right, key, question);

    return node;
}

void preorder(TREE *root) {

    if (root == NULL) {
        printf("Nothing here...");
        return;
    }

    printf("%d ", root -> key);
    printf("%s ", root -> question);

    preorder(root -> left);
    preorder(root -> right);
}

void buildTree(FILE* file, char line[], TREE** root) {

    while (fgets(line, 100, file) != NULL) {

        char *token = strtok(line, "|");
        int key = atoi(token);

        token = strtok(NULL, "|");
        char *question = strdup(token);
        question[strlen(question) - 1] = '\0';

        *root = insert(*root, key, question);
    }
}

void guessGame(TREE* node) {

    char answer[3];

    if (node -> left == NULL && node -> right == NULL) {
        printf("%s\n", node -> question);
        return;
    }

    printf("%s (yes/no): ", node -> question);
    gets(answer);

    if (strcmp(answer, "yes") == 0)
        guessGame(node -> right);

    else if (strcmp(answer, "no") == 0)
        guessGame(node -> left);

    else {
        printf("Wrong input!\n");
        guessGame(node);
    }
}

void freeTree(TREE* node) {

    if (node != NULL) {
        freeTree(node -> left);
        freeTree(node -> right);
        free(node);
    }
}

int main() {

    TREE* root = NULL;
    FILE *file;
    char line[100];

    file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    buildTree(file, line, &root);
    guessGame(root);
    fclose(file);

    freeTree(root);

    return 0;
}