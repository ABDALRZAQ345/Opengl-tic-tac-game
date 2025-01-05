#include <GL/glut.h>
#include <vector>
#include <iostream>
#include "Texture.h"

using namespace std;

bool gameEnded = false;
Texture xTexture, oTexture;
vector<int> board(9, -1);// -1 empty cell ,1 cell filled with x , 2 cell filled with o
bool player = false;      // 0 for first player ,1 for second 

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
}


void drawBoard() {
    glColor3f(1.0, 0.0, 0.0); 
    glLineWidth(5.0);

    glBegin(GL_LINES);
 
    glVertex2f(0.0, 1.0);
    glVertex2f(3.0, 1.0);

    glVertex2f(0.0, 2.0);
    glVertex2f(3.0, 2.0);

    
    glVertex2f(1.0, 0.0);
    glVertex2f(1.0, 3.0);

    glVertex2f(2.0, 0.0);
    glVertex2f(2.0, 3.0);
    glEnd();
}


void drawSymbols() {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == -1) continue;

        float x = (i % 3) + 0.5; 
        float y = 0.5+ (i / 3); 

        glEnable(GL_TEXTURE_2D);
        if (board[i] == 0)
            xTexture.Use(); 
        else
            oTexture.Use(); 

        glColor3f(1.0, 1.0, 1.0); 
        glBegin(GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex2f(x - 0.4, y - 0.4);
        glTexCoord2f(1.0, 0.0); glVertex2f(x + 0.4, y - 0.4);
        glTexCoord2f(1.0, 1.0); glVertex2f(x + 0.4, y + 0.4);
        glTexCoord2f(0.0, 1.0); glVertex2f(x - 0.4, y + 0.4);
        glEnd();

        glDisable(GL_TEXTURE_2D);
    }
}


bool checkWin() {
    // all win status :)
    int winPatterns[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };

    for (auto& pattern : winPatterns) {
        if (board[pattern[0]] != -1 &&
            board[pattern[0]] == board[pattern[1]] &&
            board[pattern[1]] == board[pattern[2]]) {
            return true;
        }
    }
    return false;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    drawBoard();
    drawSymbols();

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 3.0, 0.0, 3.0);
    glMatrixMode(GL_MODELVIEW);
}


void keyboard(unsigned char key, int x, int y) {
    if (gameEnded) return;

    if (key >= '1' && key <= '9') {
        int cell = (key - '1'); 

        if (board[cell] == -1) {
            board[cell] = player ; 
            player ^=1;     

            if (checkWin()) {
                gameEnded = true;
            }
            glutPostRedisplay();
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 600); 
    glutCreateWindow("XO Game");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    init();
    xTexture.loadTexture("C:\\Users\\abd alrzaq\\source\\repos\\Project1\\images\\x.png");
    oTexture.loadTexture("C:\\Users\\abd alrzaq\\source\\repos\\Project1\\images\\o.png");

    glutMainLoop();
    return 0;
}
