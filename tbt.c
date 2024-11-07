#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int lbit, rbit;
    struct Node *left;
    struct Node *right;
} Node;

Node* inorder_succ(Node *root) {
    Node *curr = root->right;
    if (root->rbit == 1) {
        while (curr->lbit == 1) {
            curr = curr->left;
        }
    }
    return curr;
}

void create(Node *head) {
    Node *root = (Node*)malloc(sizeof(Node));
    scanf(" %d", &root->data);
    head->lbit = 1;
    head->left = root;
    root->left = head;
    root->right = head;
    root->lbit = 0;
    root->rbit = 0;
    int ch;

    do {
        Node* temp = root;
        Node *curr = (Node*)malloc(sizeof(Node));
        scanf(" %d", &curr->data);
        curr->lbit = 0;
        curr->rbit = 0;
        int f = 0;

        while (f == 0) {
            int c;
            printf("Input l or r \n");
            scanf(" %d", &c);

            if (c == 0) {
                if (temp->lbit == 0) {
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 1;
                    f = 1;
                } else {
                    temp = temp->left;
                }
            }

            if (c == 1) {
                if (temp->rbit == 0) {
                    curr->left = temp;
                    curr->right = temp->right;
                    temp->right = curr;
                    temp->rbit = 1;
                    f = 1;
                } else {
                    temp = temp->right;
                }
            }
        }
        printf("MORE Inputs (1 | 0) \n");
        scanf("%d", &ch);

    } while (ch == 1);
}

/*
void create(Node *head) {
    // Allocate memory for root
    Node *root = (Node *)malloc(sizeof(Node));
    printf("Enter root data: ");
    scanf("%d", &root->data);

    // Initialize head and root
    head->lbit = 1;
    root->left = head;
    root->right = head;
    root->lbit = 0;
    root->rbit = 0;
    head->left = root;

    int ch;
    do {
        int flag = 0;
        Node *temp = root;

        // Allocate memory for new node
        Node *curr = (Node *)malloc(sizeof(Node));
        printf("Enter data for new node: ");
        scanf("%d", &curr->data);
        curr->lbit = 0;
        curr->rbit = 0;

        while (flag == 0) {
            char choice;
            printf("Insert left or right of %d (l/r): ", temp->data);
            scanf(" %c", &choice);

            if (choice == 'l') {
                if (temp->lbit == 0) { // Insert as left child
                    curr->right = temp;
                    curr->left = temp->left;
                    temp->left = curr;
                    temp->lbit = 1;
                    flag = 1; // Exit the loop after insertion
                } else {
                    temp = temp->left; // Move to the left child
                }
            } else if (choice == 'r') {
                if (temp->rbit == 0) { // Insert as right child
                    curr->left = temp;
                    curr->right = temp->right;
                    temp->right = curr;
                    temp->rbit = 1;
                    flag = 1; // Exit the loop after insertion
                } else {
                    temp = temp->right; // Move to the right child
                }
            } else {
                printf("Invalid input. Please enter 'l' or 'r'.\n");
            }
        }

        printf("Add more nodes? (1 for yes, 0 for no): ");
        scanf("%d", &ch);

    } while (ch == 1);
}
*/

void inorder(Node *root) {
    Node *temp = root;
    while (1) {
        temp = inorder_succ(temp);
        if (temp == root) break;
        printf("%d ", temp->data);
    }
}

int main() {
    Node *head = (Node*)malloc(sizeof(Node));
    head->lbit = 0;
    head->left = head;
    head->right = head;
    head->rbit = 1;
    create(head);
    inorder(head);
}
