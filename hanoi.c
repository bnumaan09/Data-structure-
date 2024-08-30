#include <stdio.h>

char initial[4] = {'D', 'C', 'B', 'A'};
char final[4], help[4];
int top_initial = 3, top_final = -1, top_help = -1;

int isEmpty(int top);
int check_condition(char a1, char a2);

void moveRing(int source, int destination, char sourceTower[], char destTower[], int *top_source, int *top_dest) {
    char data;
    int r = isEmpty(*top_source);
    if (r == 1) {
        printf("No data in the source tower to be moved!\n");
        return;
    }

    // taking data from source tower
    data = sourceTower[*top_source];
    int check = check_condition(data, destTower[*top_dest]);

    if (check == 1) {
        // putting the data to destination tower
        (*top_dest)++;
        destTower[*top_dest] = data;
        (*top_source)--;
        printf("%c SucessFully Moved!\n", data);
    } else {
        printf("The data you are trying to insert is larger than the one already existing in the destination tower!\n");
    }
}

int isEmpty(int top) {
    if (top == -1)
        return 1;
    return 0;
}

int check_condition(char a1, char a2) {
    if (a2 == 0)
        return 1;
    else if (a1 < a2)
        return 1;
    else
        return 0;
}

void display(char stack[4], int top) {
    int i;
    int r = isEmpty(top);
    if (r == 1) {
        for (i = 0; i < 4; i++) {
            printf("---\n| |\n");
        }
        printf("---\n");
        return;
    }
    for (i = top; i >= 0; i--) {
        printf("\n|%c|\n---", stack[i]);
    }
}

int gameover() {
    if (top_final == 3) {
        return 1;
    }
    return 0;
}

void rules() {
    printf("Three simple rules are followed:\n1. Only one disk can be moved at a time.\n2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack. In other words, a disk can only be moved if it is the uppermost disk on a stack.\n3. No larger disk may be placed on top of a smaller disk.");
}

int main() {
    int choice, gm;
    int from, to;

    printf("Welcome to the game TOWER OF HANOI\n");
    printf("\nTOWER : 1\n");
    display(initial, top_initial);
    printf("\nTOWER : 2\n");
    display(final, top_final);
    printf("\nTOWER : 3\n");
    display(help, top_help);
    printf("\nMove the four rings (characters where D > C > B > A) from Tower 1 to Tower 2 using Tower 3\n");

    while (1) {
        printf("\nPress 1 to move a ring\n");
        printf("Press 2 to view the rules of the game\n");
        printf("Press 3 to exit the game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Move From: ");
                scanf("%d", &from);
                printf("Move To: ");
                scanf("%d", &to);

                if (from == 1 && to == 2)
                    moveRing(from, to, initial, final, &top_initial, &top_final);
                else if (from == 1 && to == 3)
                    moveRing(from, to, initial, help, &top_initial, &top_help);
                else if (from == 2 && to == 1)
                    moveRing(from, to, final, initial, &top_final, &top_initial);
                else if (from == 2 && to == 3)
                    moveRing(from, to, final, help, &top_final, &top_help);
                else if (from == 3 && to == 1)
                    moveRing(from, to, help, initial, &top_help, &top_initial);
                else if (from == 3 && to == 2)
                    moveRing(from, to, help, final, &top_help, &top_final);
                else if (from == to)
                    printf("Invalid move! Source and destination towers cannot be the same.\n");
                break;

            case 2:
                rules();
                break;

            case 3:
                printf("\nExiting the game!\n");
                return 0;

            default:
                printf("\nInvalid Choice!!\n\n");
                break;
        }

        printf("\nTOWER : 1\n");
        display(initial, top_initial);
        printf("\nTOWER : 2\n");
        display(final, top_final);
        printf("\nTOWER : 3\n");
        display(help, top_help);

        gm = gameover();
        if (gm == 1) {
            printf("YOU WON!!!\nGame over\n");
            return 0;
        }
    }

    return 0;
}
