#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char firstName[50];
    char lastName[50];
    char email[100];
} User;

void addUser(User **users, int *size, int *capacity) {
    if (*size >= *capacity) {
        *capacity *= 2;
        *users = realloc(*users, (*capacity) * sizeof(User));
        if (*users == NULL) {
            printf("Error!\n");
            exit(1);
        }
    }

    printf("Enter first name: ");
    scanf("%s", (*users)[*size].firstName);
    printf("Enter surname: ");
    scanf("%s", (*users)[*size].lastName);
    printf("Enter e-mail: ");
    scanf("%s", (*users)[*size].email);

    (*size)++;
}

void listUsers(User *users, int size) {
    if (size == 0) {
        printf("No users registered\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("User %d: %s %s, Email: %s\n", i + 1, users[i].firstName, users[i].lastName, users[i].email);
    }
}

void removeUser(User *users, int *size) {
    if (*size == 0) {
        printf("No users registered\n");
        return;
    }

    int index;
    printf("Enter index for removal (1 to %d): ", *size);
    scanf("%d", &index);

    if (index < 1 || index > *size) {
        printf("Wrong index\n");
        return;
    }

    for (int i = index - 1; i < *size - 1; i++) {
        users[i] = users[i + 1];
    }

    (*size)--;
    printf("User succesfully removed\n");
}

int main() {
    int size = 0;
    int capacity = 30;
    User *users = malloc(capacity * sizeof(User));

    if (users == NULL) {
        printf("Error!\n");
        return 1;
    }

    int choice;

    do {
        printf("\nOptions:\n");
        printf("1. Add User\n");
        printf("2. Print User\n");
        printf("3. Remove User\n");
        printf("4. End\n");
        printf("Enter Your decision: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(&users, &size, &capacity);
                break;
            case 2:
                listUsers(users, size);
                break;
            case 3:
                removeUser(users, &size);
                break;
            case 4:
                printf("Ending\n");
                break;
            default:
                printf("Error!\n");
                break;
        }
    } while (choice != 4);

    free(users);

    return 0;
}

