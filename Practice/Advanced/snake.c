#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>

// Game dimensions
#define WIDTH 40
#define HEIGHT 20

// Game variables
bool gameOver;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;

// Enumeration for directions
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
enum eDirection dir;

// Initialize game state
void Setup() {
    gameOver = false;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    score = 0;
    nTail = 0;

    // Seed random number generator
    srand(time(NULL));
    
    // Spawn initial fruit
    fruitX = rand() % (WIDTH - 2) + 1;
    fruitY = rand() % (HEIGHT - 2) + 1;
}

// Render the game board in the console
void Draw() {
    // Reset cursor to top-left instead of system("cls") to reduce flickering
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    // Top wall
    for (int i = 0; i < WIDTH; i++) printf("#");
    printf("\n");

    // Map body
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Left wall
            if (j == 0) {
                printf("#");
            }
            // Snake head
            else if (i == y && j == x) {
                printf("O");
            }
            // Fruit
            else if (i == fruitY && j == fruitX) {
                printf("F");
            }
            // Right wall
            else if (j == WIDTH - 1) {
                printf("#");
            }
            // Snake body/tail & empty space
            else {
                bool printTail = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o");
                        printTail = true;
                        break;
                    }
                }
                if (!printTail) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    // Bottom wall
    for (int i = 0; i < WIDTH; i++) printf("#");
    printf("\n");

    // Display Score
    printf("\nScore: %d\n", score);
    printf("Controls: W (Up), A (Left), S (Down), D (Right) | X to Quit\n");
}

// Handle non-blocking user input
void Input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
            case 'A':
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd':
            case 'D':
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w':
            case 'W':
                if (dir != DOWN) dir = UP;
                break;
            case 's':
            case 'S':
                if (dir != UP) dir = DOWN;
                break;
            case 'x':
            case 'X':
                gameOver = true;
                break;
        }
    }
}

// Update game logic (movement, collisions, scoring)
void Logic() {
    // Save previous position of the head
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    // Move the rest of the tail
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    // Move the head based on direction
    switch (dir) {
        case LEFT:  x--; break;
        case RIGHT: x++; break;
        case UP:    y--; break;
        case DOWN:  y++; break;
        default: break;
    }

    // Wall collision (Ends the game)
    if (x >= WIDTH - 1 || x <= 0 || y >= HEIGHT || y < 0) {
        gameOver = true;
    }

    // Tail collision (Self-cannibalism ends the game)
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            gameOver = true;
        }
    }

    // Fruit collision (Eating the fruit)
    if (x == fruitX && y == fruitY) {
        score += 10;
        nTail++;
        // Respawn fruit at a new random location
        fruitX = rand() % (WIDTH - 2) + 1;
        fruitY = rand() % (HEIGHT - 2) + 1;
    }
}

int main() {
    // Hide the console cursor for cleaner rendering
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);

    Setup();

    // Main Game Loop
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        
        // Control game speed (smaller number = faster game)
        Sleep(100); 
    }

    // Game Over screen
    system("cls");
    printf("\n\n=================================\n");
    printf("           GAME OVER!            \n");
    printf("=================================\n");
    printf("Final Score: %d\n\n", score);

    return 0;
}