#include <GL/glut.h>
#include <stdio.h>

int xc, yc, r;


void drawPoints(int x, int y, int xc, int yc){
    glBegin(GL_POINTS);
    
    glVertex2i(x + xc, y + yc);
    glVertex2i(x + xc, -y + yc);
    glVertex2i(-x + xc, y + yc);
    glVertex2i(-x + xc, -y + yc);

    glVertex2i(y + xc, x + yc);
    glVertex2i(y + xc, -x + yc);
    glVertex2i(-y + xc, x + yc);
    glVertex2i(-y + xc, -x + yc);

    glEnd();

}

void getAns(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);

    int x = 0, y = r;
    int d = 3 - 2 * r;
    while(y >= x){
        x++;
        if(d > 0){
            y--;
            d = d + 4 * (x - y) + 10;
        }else{
            d = d + 4 * x + 6;
        }
        drawPoints(x, y, xc, yc);
    }

    glFlush();
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}


int main(int argc, char** argv){

    printf("Enter center of circle as x y\n");
    scanf("%d%d", &xc, &yc);
    printf("Enter radius of circle as r\n");
    scanf("%d", &r);
    if(r < 0){
        printf("Negative radius\n");
        return 0;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    //glutInitwindowPosition(50, 50);
    glutCreateWindow("Bresenham Circle Algo");
    init();
    glutDisplayFunc(getAns);
    glutMainLoop();

    return 0;
}

