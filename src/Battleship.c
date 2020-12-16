/*
 ============================================================================
 Name        : Battleship.c
 Author      : Ho Jing Heng
 Version     :
 Copyright   : Ho Jing Heng @ 2018
 Description : Battleship in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

char primary1[10][10] = {{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
                       };

char primary2[10][10] = {{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
                       };

int fire1[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    };

int fire2[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    };

char secondary1[10][10] = {{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
                       };

char secondary2[10][10] = {{'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'},
                        {'~', '~', '~', '~', '~', '~', '~', '~', '~', '~'}
                       };

void play();                                            //to launch and play the game
void primaryGrid1();                                    //to store all the ships of Player 1
void carrier1(char orient, int x, char y, int a);       //to store the carrier of Player 1
void battleship1(char orient, int x, char y, int a);    //to store the battleship of Player 1
void cruiser1(char orient, int x, char y, int a);       //to store the cruiser of Player 1
void submarine1(char orient, int x, char y, int a);     //to store the submarine of Player 1
void destroyer1(char orient, int x, char y, int a);     //to store the destroyer of Player 1
void primaryGrid2();                                    //to store all the ships of Player 2
void carrier2(char orient, int x, char y, int a);       //to store the carrier of Player 2
void battleship2(char orient, int x, char y, int a);    //to store the battleship of Player 2
void cruiser2(char orient, int x, char y, int a);       //to store the cruiser of Player 2
void submarine2(char orient, int x, char y, int a);     //to store the submarine of Player 2
void destroyer2(char orient, int x, char y, int a);     //to store the destroyer of Player 2
void printPrimary1(void);                               //to print out the grid for storing ships of Player 1
void printPrimary2(void);                               //to print out the grid for storing ships of Player 2
void printSecondary1(void);                             //to print out the grid for firing for Player 2
void printSecondary2(void);                             //to print out the grid for firing for Player 1
void fullscr(void);                                     //to make the game runs in full screen mode

int main(void) {

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    fullscr();
    system("COLOR 3F");

    int mainChoice;

    printf("             ---------             \n");
    printf("            |         |           \n");
    printf("      -----------------------       \n");
    printf("     /|||||||||||||||||||||||\\      \n");
    printf("    /|||||||||||||||||||||||||\\      \n");
    printf("---------------Battleship-----------------\n");
    printf("\\||||||||||||||||||||||||||||||||||||||||/\n");
    printf(" \\||||||||||||||||||||||||||||||||||||||/\n");
    printf("  \\||||||||||||||||||||||||||||||||||||/\n");
    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n");

    while(mainChoice != 1 && mainChoice != 2)
    {
        Z: printf("\n=====================================================\n");
        printf("Enter 1 to play\n");
        printf("Enter 2 for instructions on how to play (RECOMMENDED)\n");
        printf("=====================================================\n\n");
        scanf("%d", &mainChoice);
        fflush(stdin);

        if(mainChoice == 1)
        {
            play(); //to launch and play the game
        }
        else if(mainChoice == 2)
        {
            printf("1. The first player is player 1 followed by player 2. Each player take their turns.\n");
            printf("2. The first step is for both the players to place their ship.\n");
            printf("3. There will be one 5-units carrier, two 4-units battleships, three 3-units cruiser, four 3-units submarine and five 2-units destroyer.\n");
            printf("4. Press H or h and enter for horizontal orientation. Press Y or y for vertical orientation.\n");
            printf("5. Enter your coordinates starting with a number, space and the alphabet.\n");
            printf("6. The coordinates you entered will be the starting point of the placement of the ship.\n");
            printf("7. In horizontal orientation, the size of the ship will print towards the left starting from the coordinates you entered.\n");
            printf("8. In vertical orientation, the size of the ship will print towards the bottom starting from the coordinates you entered.\n");
            printf("9. When entering the coordinates, the alphabet can be uppercase or lowercase.\n");
            printf("10. After that, each player will take turn to fire the opponent's ship by entering the coordinates.\n");
            printf("11. The player can keep firing when the player hits a ship until the player misses.\n");
            printf("12. Hit will be represented by an 'X' while miss is represented by '*'\n");
            printf("13. Take down all the opponent's ships and you're the winner!\n");
            goto Z;
        }
        else
        {
            printf("Invalid choice entered.\nPlease enter again.\n");
        }
    }

	return EXIT_SUCCESS;
}

void fullscr(void) {
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

void play(void) {

    printf("\n>> Player 1, be ready.....\n");
    printf("The sea grid is as follows, plan wisely.....\n\n");
    printf("   ");
    for(char firstLine=65; firstLine<=74; firstLine++)
    {
        printf("%c ", firstLine);
    }
    printf("\n");
    for(int num=1; num<=10; num++)
    {
        if(num<10)
        {
            printf(" %d ", num);
        }
        else
        {
            printf("%d ", num);
        }
        for(int water=0; water<10; water++)
        {
            printf("~ ");
        }
        printf("\n");
    }

    primaryGrid1(); //to store all the ships of Player 1

    system("cls");

    printf("\n\n>> Player 2, be ready.....\n");
    printf("The sea grid is as follows, plan wisely.....\n\n");
    printf("   ");
    for(char firstLine=65; firstLine<=74; firstLine++)
    {
        printf("%c ", firstLine);
    }
    printf("\n");
    for(int num=1; num<=10; num++)
    {
        if(num<10)
        {
            printf(" %d ", num);
        }
        else
        {
            printf("%d ", num);
        }
        for(int water=0; water<10; water++)
        {
            printf("~ ");
        }
        printf("\n");
    }

    primaryGrid2(); //to store all the ships of Player 2

    int x = 0, count11 = 5, count21 = 8, count31 = 9, count41 = 12, count51 = 10, count12 = 5, count22 = 8, count32 = 9, count42 = 12, count52 = 10;
    char y = '\0';
    int totalCount1 = 0, totalCount2 = 0;

    E: system("cls");
    printf("\n");
    printSecondary2();
    printf("\nPlayer 1's turn.....\n");
    printf("Enter a coordinate to fire: ");
    scanf("%d %c", &x, &y);

    if(y>=65 && y<=74)
    {
        y -= 65;
    }
    else if(y>=97 && y<=106)
    {
        y -= 97;
    }

    int a = y;

    if(fire2[x-1][a] == 1)
    {
        secondary2[x-1][a] = 'X';
        count11--;
        totalCount1++;
    }
    else if(fire2[x-1][a] == 2)
    {
        secondary2[x-1][a] = 'X';
        count21--;
        totalCount1++;
    }
    else if(fire2[x-1][a] == 3)
    {
        secondary2[x-1][a] = 'X';
        count21--;
        totalCount1++;
    }
    else if(fire2[x-1][a] == 4)
    {
        secondary2[x-1][a] = 'X';
        count21--;
        totalCount1++;
    }
    else if(fire2[x-1][a] == 5)
    {
        secondary2[x-1][a] = 'X';
        count21--;
        totalCount1++;
    }
    else
    {
        secondary2[x-1][a] = '*';
    }

    printSecondary2();  //to print the grid for firing for Player 1
    if(fire2[x-1][a] == 1 || fire2[x-1][a] == 2 || fire2[x-1][a] == 3 || fire2[x-1][a] == 4 || fire2[x-1][a] == 5)
    {
        printf("You hit a ship!\n");
    }
    else
    {
        printf("You missed!\n");
    }


    if(count11 == 0)
    {
        printf("You have sunk a carrier!");
        if(count11 == 0)
        {
            count11--;
        }
    }


    if(count21 == 4 || count21 == 0)
    {
        printf("You have sunk a battleship!");
        if(count21 == 0)
        {
            count21--;
        }
    }


    if(count31 == 6 || count31 == 3 || count31 == 0)
    {
        printf("You have sunk a cruiser!");
        if(count31 == 0)
        {
            count31--;
        }
    }

    if(count41 == 9 || count41 == 6 || count41 == 3 || count41 == 0)
    {
        printf("You have sunk a submarine!");
        if(count41 == 0)
        {
            count41--;
        }
    }

    if(count51 == 8 || count51 == 6 || count51 == 4 || count51 == 2 || count51 == 0)
    {
        printf("You have sunk a destroyer!");
        if(count51 == 0)
        {
            count51--;
        }
    }

    if(fire2[x-1][a] == 1 || fire2[x-1][a] == 2 || fire2[x-1][a] == 3 || fire2[x-1][a] == 4 || fire2[x-1][a] == 5)
    {
        goto E;
    }
    else if(totalCount1 == 44)
    {
        printf("Player 1 wins!");
        exit(0);
    }

    //Player 2
    F: system("cls");
    printSecondary1();   //to print the grid for firing for Player 2
    printf("\n\nPlayer 2's turn........\n");
    printf("Enter a coordinate to fire: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(y>=65 && y<=74)
    {
        y -= 65;
    }
    else if(y>=97 && y<=106)
    {
        y -= 97;
    }

    a = y;

    if(fire1[x-1][a] == 1)
    {
        secondary1[x-1][a] = 'X';
        count12--;
        totalCount2++;
    }
    else if(fire1[x-1][a] == 2)
    {
        secondary1[x-1][a] = 'X';
        count22--;
        totalCount2++;
    }
    else if(fire1[x-1][a] == 3)
    {
        secondary1[x-1][a] = 'X';
        count32--;
        totalCount2++;
    }
    else if(fire1[x-1][a] == 4)
    {
        secondary1[x-1][a] = 'X';
        count42--;
        totalCount2++;
    }
    else if(fire1[x-1][a] == 5)
    {
        secondary1[x-1][a] = 'X';
        count52--;
        totalCount2++;
    }
    else
    {
        secondary1[x-1][a] = '*';
    }

    printSecondary1();  //to print the grid for firing for Player 2
    if(fire1[x-1][a] == 1 || fire1[x-1][a] == 2 || fire1[x-1][a] == 3 || fire1[x-1][a] == 4 || fire1[x-1][a] == 5)
    {
        printf("You hit a ship!\n");
    }
    else
    {
        printf("You missed!\n");
    }

    if(count12 == 0)
    {
        printf("You have sunk a carrier!");
        if(count12 == 0)
        {
            count12--;
        }
    }


    if(count22 == 4 || count22 == 0)
    {
        printf("You have sunk a battleship!");
        if(count22 == 0)
        {
            count22--;
        }
    }


    if(count32 == 6 || count32 == 3 || count32 == 0)
    {
        printf("You have sunk a cruiser!");
        if(count32 == 0)
        {
            count32--;
        }
    }

    if(count42 == 9 || count42 == 6 || count42 == 3 || count42 == 0)
    {
        printf("You have sunk a submarine!");
        if(count42 == 0)
        {
            count42--;
        }
    }

    if(count52 == 8 || count52 == 6 || count52 == 4 || count52 == 2 || count52 == 0)
    {
        printf("You have sunk a destroyer!");
        if(count52 == 0)
        {
            count52--;
        }
    }

    if(fire1[x-1][a] == 1 || fire1[x-1][a] == 2 || fire1[x-1][a] == 3 || fire1[x-1][a] == 4 || fire1[x-1][a] == 5)
    {
        goto F;
    }
    else if(totalCount2 == 44)
    {
        printf("Player 2 wins!");
    }
    else
    {
        goto E;
    }

}

void printPrimary1(void) {
    printf("   ");
    for(char firstLine=65; firstLine<=74; firstLine++)
    {
        printf("%c ", firstLine);
    }
    printf("\n");
    for(int m=0; m<10; m++)
    {
        if(m<9)
        {
            printf(" %d ", ++m);
            m--;
        }
        else
        {
            printf("%d ", ++m);
            m--;
        }

        for(int n=0; n<10; n++)
        {
            printf("%c ", primary1[m][n]);
        }
        printf("\n");
    }
}

void printPrimary2(void) {
    printf("   ");
    for(char firstLine=65; firstLine<=74; firstLine++)
    {
        printf("%c ", firstLine);
    }
    printf("\n");
    for(int m=0; m<10; m++)
    {
        if(m<9)
        {
            printf(" %d ", ++m);
            m--;
        }
        else
        {
            printf("%d ", ++m);
            m--;
        }

        for(int n=0; n<10; n++)
        {
            printf("%c ", primary2[m][n]);
        }
        printf("\n");
    }
}

void primaryGrid1(void) {

    char orient = '\0', y = '\0';
    int x = 0, a = 0;

    carrier1(orient, x, y, a);  //to store the carrier of Player 1

    for(int i=0; i<2; i++)
    {
        battleship1(orient, x, y, a);   //to store the battleship of Player 1
    }

    for(int i=0; i<3; i++)
    {
        cruiser1(orient, x, y, a);  //to store the cruiser of Player 1
    }

    for(int i=0; i<4; i++)
    {
        submarine1(orient, x, y, a);    //to store the submarine of Player 1
    }

    for(int i=0; i<5; i++)
    {
        destroyer1(orient, x, y, a);    //to store the destroyer of Player 1
    }
}

void carrier1(char orient, int x, char y, int a) {

    A: printf("Carrier:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto A;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'G' || y == 'g' || y == 'H' || y == 'h' || y == 'I' || y == 'i' || y == 'J' || y == 'j')
        {
            printf("The carrier can't be put.\nPlease enter again.\n");
            goto A;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary1[x-1][a] != '~' || primary1[x-1][a+1] != '~' || primary1[x-1][a+2] != '~' || primary1[x-1][a+3] != '~' || primary1[x-1][a+4] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto A;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 6)
        {
            printf("The carrier can't be put.\nPlease enter again.\n");
            goto A;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary1[x-1][a] != '~' || primary1[x][a] != '~' || primary1[x+1][a] != '~' || primary1[x+2][a] != '~' || primary1[x+3][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto A;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m][n+1] == '~' && primary1[m][n+2] == '~' && primary1[m][n+3] == '~' && primary1[m][n+4] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 1;
                    primary1[m][n+1] = '#';
                    fire1[m][n+1] = 1;
                    primary1[m][n+2] = '#';
                    fire1[m][n+2] = 1;
                    primary1[m][n+3] = '#';
                    fire1[m][n+3] = 1;
                    primary1[m][n+4] = '#';
                    fire1[m][n+4] = 1;
                }
            }
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m+1][n] == '~' && primary1[m+2][n] == '~' && primary1[m+3][n] == '~' && primary1[m+4][n] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 1;
                    primary1[m+1][n] = '#';
                    fire1[m+1][n] = 1;
                    primary1[m+2][n] = '#';
                    fire1[m+2][n] = 1;
                    primary1[m+3][n] = '#';
                    fire1[m+3][n] = 1;
                    primary1[m+4][n] = '#';
                    fire1[m+4][n] = 1;
                }
            }
        }
    }

    system("cls");
    printPrimary1();    //to print the grid for storing ships of Player 1
}

void battleship1(char orient, int x, char y, int a) {

    B: printf("Battleship:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto B;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'H' || y == 'h' || y == 'I' || y == 'i' || y == 'J' || y == 'j')
        {
            printf("The battleship can't be put.\nPlease enter again.\n");
            goto B;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary1[x-1][a] != '~' || primary1[x-1][a+1] != '~' || primary1[x-1][a+2] != '~' || primary1[x-1][a+3] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto B;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 7)
        {
            printf("The battleship can't be put.\nPlease enter again.\n");
            goto B;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary1[x-1][a] != '~' || primary1[x][a] != '~' || primary1[x+1][a] != '~' || primary1[x+2][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto B;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m][n+1] == '~' && primary1[m][n+2] == '~' && primary1[m][n+3] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 2;
                    primary1[m][n+1] = '#';
                    fire1[m][n+1] = 2;
                    primary1[m][n+2] = '#';
                    fire1[m][n+2] = 2;
                    primary1[m][n+3] = '#';
                    fire1[m][n+3] = 2;
                }
            }
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m+1][n] == '~' && primary1[m+2][n] == '~' && primary1[m+3][n] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 2;
                    primary1[m+1][n] = '#';
                    fire1[m+1][n] = 2;
                    primary1[m+2][n] = '#';
                    fire1[m+2][n] = 2;
                    primary1[m+3][n] = '#';
                    fire1[m+3][n] = 2;
                }
            }
        }
    }

    system("cls");
    printPrimary1();    //to print the grid for storing ships of Player 1
}

void cruiser1(char orient, int x, char y, int a) {

    C: printf("Cruiser:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto C;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'I' || y == 'i' || y == 'J' || y == 'j')
        {
            printf("The cruiser can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary1[x-1][a] != '~' || primary1[x-1][a+1] != '~' || primary1[x-1][a+2] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 8)
        {
            printf("The cruiser can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary1[x-1][a] != '~' || primary1[x][a] != '~' || primary1[x+1][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m][n+1] == '~' && primary1[m][n+2] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 3;
                    primary1[m][n+1] = '#';
                    fire1[m][n+1] = 3;
                    primary1[m][n+2] = '#';
                    fire1[m][n+2] = 3;
                }
            }
        }
    }
    else if(orient == 'v' || orient=='V' )
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m+1][n] == '~' && primary1[m+2][n] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 3;
                    primary1[m+1][n] = '#';
                    fire1[m+1][n] = 3;
                    primary1[m+2][n] = '#';
                    fire1[m+2][n] = 3;
                }
            }
        }
    }

    system("cls");
    printPrimary1();    //to print the grid for storing ships of Player 1
}

void submarine1(char orient, int x, char y, int a) {

    C: printf("Submarine:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto C;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'I' || y == 'i' || y == 'J' || y == 'j')
        {
            printf("The submarine can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary1[x-1][a] != '~' || primary1[x-1][a+1] != '~' || primary1[x-1][a+2] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 8)
        {
            printf("The submarine can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary1[x-1][a] != '~' || primary1[x][a] != '~' || primary1[x+1][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m][n+1] == '~' && primary1[m][n+2] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 4;
                    primary1[m][n+1] = '#';
                    fire1[m][n+1] = 4;
                    primary1[m][n+2] = '#';
                    fire1[m][n+2] = 4;
                }
            }
        }
    }
    else if(orient == 'v' || orient == 'V' )
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m+1][n] == '~' && primary1[m+2][n] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 4;
                    primary1[m+1][n] = '#';
                    fire1[m+1][n] = 4;
                    primary1[m+2][n] = '#';
                    fire1[m+2][n] = 4;
                }
            }
        }
    }

    system("cls");
    printPrimary1();    //to print the grid for storing ships of Player 1
}

void destroyer1(char orient, int x, char y, int a) {

    C: printf("Destroyer:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto C;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'J' || y == 'j')
        {
            printf("The destroyer can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary1[x-1][a] != '~' || primary1[x-1][a+1] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 9)
        {
            printf("The destroyer can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary1[x-1][a] != '~' || primary1[x][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m][n+1] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 5;
                    primary1[m][n+1] = '#';
                    fire1[m][n+1] = 5;
                }
            }
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary1[m][n] == '~' && primary1[m+1][n] == '~')
                {
                    primary1[m][n] = '#';
                    fire1[m][n] = 5;
                    primary1[m+1][n] = '#';
                    fire1[m+1][n] = 5;
                }
            }
        }
    }

    system("cls");
    printPrimary1();    //to print the grid for storing ships of Player 1
}

void primaryGrid2(void) {

    char orient = '\0', y = '\0';
    int x = 0, a = 0;

    carrier2(orient, x, y, a);  //to store the carrier of Player 2

    for(int i=0; i<2; i++)
    {
        battleship2(orient, x, y, a);   //to store the battleship of Player 2
    }

    for(int i=0; i<3; i++)
    {
        cruiser2(orient, x, y, a);  //to store the cruiser of Player 2
    }

    for(int i=0; i<4; i++)
    {
        submarine2(orient, x, y, a);    //to store the submarine of Player 2
    }

    for(int i=0; i<5; i++)
    {
        destroyer2(orient, x, y, a);    //to store the destroyer of Player 2
    }
}

void carrier2(char orient, int x, char y, int a) {

    A: printf("Carrier:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto A;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'G' || y == 'g' || y == 'H' || y == 'h' || y == 'I' || y == 'i' || y == 'J' || y == 'j')
        {
            printf("The carrier can't be put.\nPlease enter again.\n");
            goto A;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary2[x-1][a] != '~' || primary2[x-1][a+1] != '~' || primary2[x-1][a+2] != '~' || primary2[x-1][a+3] != '~' || primary2[x-1][a+4] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto A;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 6)
        {
            printf("The carrier can't be put.\nPlease enter again.\n");
            goto A;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary2[x-1][a] != '~' || primary2[x][a] != '~' || primary2[x+1][a] != '~' || primary2[x+2][a] != '~' || primary2[x+3][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto A;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m][n+1] == '~' && primary2[m][n+2] == '~' && primary2[m][n+3] == '~' && primary2[m][n+4] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 1;
                    primary2[m][n+1] = '#';
                    fire2[m][n+1] = 1;
                    primary2[m][n+2] = '#';
                    fire2[m][n+2] = 1;
                    primary2[m][n+3] = '#';
                    fire2[m][n+3] = 1;
                    primary2[m][n+4] = '#';
                    fire2[m][n+4] = 1;
                }
            }
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m+1][n] == '~' && primary2[m+2][n] == '~' && primary2[m+3][n] == '~' && primary2[m+4][n] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 1;
                    primary2[m+1][n] = '#';
                    fire2[m+1][n] = 1;
                    primary2[m+2][n] = '#';
                    fire2[m+2][n] = 1;
                    primary2[m+3][n] = '#';
                    fire2[m+3][n] = 1;
                    primary2[m+4][n] = '#';
                    fire2[m+4][n] = 1;
                }
            }
        }
    }

    system("cls");
    printPrimary2();    //to print the grid for storing ships of Player 2
}

void battleship2(char orient, int x, char y, int a) {


    B: printf("Battleship:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto B;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'H' || y == 'h' || y == 'I' || y == 'i' || y == 'J' || y == 'j')
        {
            printf("The battleship can't be put.\nPlease enter again.\n");
            goto B;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary2[x-1][a] != '~' || primary2[x-1][a+1] != '~' || primary2[x-1][a+2] != '~' || primary2[x-1][a+3] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto B;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 7)
        {
            printf("The battleship can't be put.\nPlease enter again.\n");
            goto B;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary2[x-1][a] != '~' || primary2[x][a] != '~' || primary2[x+1][a] != '~' || primary2[x+2][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto B;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m][n+1] == '~' && primary2[m][n+2] == '~' && primary2[m][n+3] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 2;
                    primary2[m][n+1] = '#';
                    fire2[m][n+1] = 2;
                    primary2[m][n+2] = '#';
                    fire2[m][n+2] = 2;
                    primary2[m][n+3] = '#';
                    fire2[m][n+3] = 2;
                }
            }
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m+1][n] == '~' && primary2[m+2][n] == '~' && primary2[m+3][n] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 2;
                    primary2[m+1][n] = '#';
                    fire2[m+1][n] = 2;
                    primary2[m+2][n] = '#';
                    fire2[m+2][n] = 2;
                    primary2[m+3][n] = '#';
                    fire2[m+3][n] = 2;
                }
            }
        }
    }

    system("cls");
    printPrimary2();    //to print the grid for storing ships of Player 2
}

void cruiser2(char orient, int x, char y, int a) {

    C: printf("Cruiser:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto C;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'I' || y == 'i' || y == 'J' || y == 'j')
        {
            printf("The cruiser can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary2[x-1][a] != '~' || primary2[x-1][a+1] != '~' || primary2[x-1][a+2] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 8)
        {
            printf("The cruiser can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary2[x-1][a] != '~' || primary2[x][a] != '~' || primary2[x+1][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m][n+1] == '~' && primary2[m][n+2] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 3;
                    primary2[m][n+1] = '#';
                    fire2[m][n+1] = 3;
                    primary2[m][n+2] = '#';
                    fire2[m][n+2] = 3;
                }
            }
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m+1][n] == '~' && primary2[m+2][n] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 3;
                    primary2[m+1][n] = '#';
                    fire2[m+1][n] = 3;
                    primary2[m+2][n] = '#';
                    fire2[m+2][n] = 3;
                }
            }
        }
    }

    system("cls");
    printPrimary2();    //to print the grid for storing ships of Player 2
}

void submarine2(char orient, int x, char y, int a) {

    C: printf("Submarine:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto C;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'I' || y == 'i' || y == 'J' || y == 'j')
        {
            printf("The submarine can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary2[x-1][a] != '~' || primary2[x-1][a+1] != '~' || primary2[x-1][a+2] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 8)
        {
            printf("The submarine can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary2[x-1][a] != '~' || primary2[x][a] != '~' || primary2[x+1][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m][n+1] == '~' && primary2[m][n+2] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 4;
                    primary2[m][n+1] = '#';
                    fire2[m][n] = 4;
                    primary2[m][n+2] = '#';
                    fire2[m][n] = 4;
                }
            }
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m+1][n] == '~' && primary2[m+2][n] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 4;
                    primary2[m+1][n] = '#';
                    fire2[m+1][n] = 4;
                    primary2[m+2][n] = '#';
                    fire2[m+2][n] = 4;
                }
            }
        }
    }

    system("cls");
    printPrimary2();    //to print the grid for storing ships of Player 2
}

void destroyer2(char orient, int x, char y, int a) {

    C: printf("Destroyer:");
    printf("\nEnter your orientation: ");
    scanf("%c", &orient);
    fflush(stdin);

    if(orient != 'h' && orient != 'H' && orient != 'v' && orient != 'V')
    {
        printf("Invalid orientation entered.\nPlease enter again.\n");
        goto C;
    }

    printf("Enter your coordinates: ");
    scanf("%d %c", &x, &y);
    fflush(stdin);

    if(orient == 'h' || orient == 'H')
    {
        if(y == 'J' || y == 'j')
        {
            printf("The destroyer can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }

        a = y;

        if(primary2[x-1][a] != '~' || primary2[x-1][a+1] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        if(x > 8)
        {
            printf("The destroyer can't be put.\nPlease enter again.\n");
            goto C;
        }

        if(y>=65 && y<=74)
        {
            y -= 65;
        }
        else if(y>=97 && y<=106)
        {
            y -= 97;
        }
        a = y;

        if(primary2[x-1][a] != '~' || primary2[x][a] != '~')
        {
            printf("This place is already occupied!\nPlease enter again.\n");
            goto C;
        }
    }

    if(orient == 'h' || orient == 'H')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m][n+1] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 5;
                    primary2[m][n+1] = '#';
                    fire2[m][n+1] = 5;
                }
            }
        }
    }
    else if(orient == 'v' || orient == 'V')
    {
        for(int m=0; m<10; m++)
        {
            for(int n=0; n<10; n++)
            {
                if(m == (x-1) && n == y && primary2[m][n] == '~' && primary2[m+1][n] == '~')
                {
                    primary2[m][n] = '#';
                    fire2[m][n] = 5;
                    primary2[m+1][n] = '#';
                    fire2[m+1][n] = 5;
                }
            }
        }
    }

    system("cls");
    printPrimary2();    //to print the grid for storing ships of Player 2
}

void printSecondary2(void) {
    printf("   ");
    for(char firstLine=65; firstLine<=74; firstLine++)
    {
        printf("%c ", firstLine);
    }
    printf("\n");
    for(int m=0; m<10; m++)
    {
        if(m<9)
        {
            printf(" %d ", ++m);
            m--;
        }
        else
        {
            printf("%d ", ++m);
            m--;
        }

        for(int n=0; n<10; n++)
        {
            printf("%c ", secondary2[m][n]);
        }
        printf("\n");
    }
}

void printSecondary1(void) {
    printf("   ");
    for(char firstLine=65; firstLine<=74; firstLine++)
    {
        printf("%c ", firstLine);
    }
    printf("\n");
    for(int m=0; m<10; m++)
    {
        if(m<9)
        {
            printf(" %d ", ++m);
            m--;
        }
        else
        {
            printf("%d ", ++m);
            m--;
        }

        for(int n=0; n<10; n++)
        {
            printf("%c ", secondary1[m][n]);
        }
        printf("\n");
    }
}
