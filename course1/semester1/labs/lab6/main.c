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
 void insert(TREE* tree, int key, char* question) {

    TREE* node;

    node = NULL;

    if (tree) {

        if (key == tree -> key * 2) {
            node = newNode(key, question);
            tree -> left = node;
        }

        else if (key == tree -> key * 2 + 1) {
            node = newNode(key, question);
            tree -> right = node;
        }

        else {
            insert(tree->right, key, question);
        }
    }
}            insert(tree->left, key, question);


void buildTree(FILE* file, char line[], TREE** root) {

    while (fgets(line, 100, file) != NULL) {

        char *token = strtok(line, "|");
        int key = atoi(token);

        token = strtok(NULL, "|");
        char *question = strdup(token);
        question[strlen(question) - 1] = '\0';

        if(!*root)
            *root = newNode(key, question);
        else
            insert(*root, key, question);
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
