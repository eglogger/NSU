#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TREE struct tree
#define MAX_LEN 100

TREE {

    int key;
    char question[MAX_LEN];

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

    TREE* node = NULL;

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
            insert(tree -> left, key, question);
            insert(tree -> right, key, question);
        }
    }
}

// Building tree from file.
void buildTree(FILE* file, char line[], TREE** root) {

    while (fgets(line, MAX_LEN, file) != NULL) {

        // Taking node key.
        char *token = strtok(line, "|");
        int key = atoi(token);

        // Taking node question.
        token = strtok(NULL, "|");
        char *question = strdup(token);
        question[strlen(question) - 1] = '\0';

        if(!*root)
            *root = newNode(key, question);

        else
            insert(*root, key, question);
    }
}

// Rewriting file with new tree.
void rebuildTree(FILE* file, TREE* root) {

    if (root == NULL)
        return;

    if (root -> key)
        fprintf(file,"%d|%s\n", root -> key, root -> question);

    rebuildTree(file,root -> left);
    rebuildTree(file,root -> right);
}

// Guessing word function.
void guessGame(TREE* node) {

    char answer[3];
    char newAnswer[MAX_LEN];
    char newQuestion[MAX_LEN];

    if (node -> left == NULL && node -> right == NULL && node -> key == 16) {
        printf("%s\n", node -> question);
        return;
    }

    if (node -> left == NULL && node -> right == NULL) {

        printf("%s\nIs it right? (yes/no):", node -> question);
        gets(answer);

        if (strcmp(answer, "yes") == 0) {
            printf("Glad to hear that! Thanks for playing :).");
            return;
        }

        else if (strcmp(answer, "no") == 0) {

            printf("Hm... What it is then?\nType new answer:");
            gets(newAnswer);

            printf("Okay! Which question can be answered 'yes' to understand "
                   "that it`s your new answer, but not my guess?\nType new question:");
            gets(newQuestion);

            char *tmp = strdup(node -> question);

            strcpy(node -> question, newQuestion);

            node -> left = newNode(node -> key * 2, tmp);
            node -> right = newNode(node -> key * 2 + 1, newAnswer);

            printf("Thanks, the database has been updated!");

            return;
        }
    }

    printf("%s (yes/no):", node -> question);
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
    char line[MAX_LEN];

    file = fopen("data.txt", "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    buildTree(file, line, &root);
    guessGame(root);
    file = fopen("data.txt", "w");
    rebuildTree(file, root);

    fclose(file);
    freeTree(root);

    return 0;
}
