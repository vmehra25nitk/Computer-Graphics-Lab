#include <GL/glut.h>
#include <stdio.h>

int len, r;



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


void drawCircle(int xc, int yc, int r){
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
}

void dda(int px1, int py1, int px2, int py2){

    float dx = px2 - px1;
    float dy = py2 - py1;
    float n = (abs(dx) > abs(dy) ? abs(dx) : abs(dy));


    dx = dx / n, dy = dy / n;
    for(int i = 0 ; i <= n ; i++){        
        glBegin(GL_POINTS);
        glVertex2i(px1, py1);
        px1 += dx;    py1 += dy;
        glEnd();
    }

}

void drawLine(int start, int len){
    int x1 = 0, y1 = start;
    int x2 = 0, y2 = start - len;
    dda(x1, y1, x2, y2);
}

void getAns(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    
    int start = 400;

    drawLine(start, len);
    int xc = 0, yc = start - len - r;
    drawCircle(xc, yc, r);

    glFlush();
}

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(1.2);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}


int main(int argc, char** argv){

    printf("Give length of pendulum wire\n");
    scanf("%d", &len);
    printf("Give radius of pendulum\n");
    scanf("%d", &r);

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

