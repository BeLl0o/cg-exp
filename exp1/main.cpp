#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
//  #include "glfw3.h"
#include "gl/glut.h"
//GLfloat angle = 0.0;
GLfloat red = 1.0f, green = 1.0f, blue = 1.0f;
GLfloat x = 0.0f;
GLfloat y = 0.0f;
GLfloat rsize = 25;

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

GLfloat windowWidth;
GLfloat windowHeight;




void SetupRC(void){
 //   glClearColor(0.6f, 0.4f, 0.7f, 1.0f);
 //   glColor3f(1.0f, 0.0f, 0.0f);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

}

void changeSize(int w, int h){
/*
    if(h == 0) h=1;
    float ratio = 1.0 * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0,0,w,h);

    gluPerspective(45, ratio, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 2.0, 0.0, 0.0, -1.0, 0.0f, 1.0f, 0.0f);
*/
    GLfloat aspectRatio;

    if(h == 0)
        h = 1;
    
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    aspectRatio = (GLfloat)w / (GLfloat)h;
    if(w <= h){
        windowWidth = 100;
        windowHeight = 100 / aspectRatio;
        glOrtho (-100.0, 100.0, -windowHeight, windowHeight, 1.0, -1.0);
    }
    else{
        windowWidth = 100 * aspectRatio;
        windowHeight = 100;
        glOrtho (-windowWidth, windowWidth, -100.0, 100.0, 1.0, -1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void TimeFunction(int value){
/*    angle += 2.0f;

    glutPostRedisplay();
    glutTimerFunc(23, TimeFunction, 1);
*/
    if(x > windowWidth - rsize || x < -windowWidth)   
        xstep = -xstep;

    if(y > windowHeight || x < -windowHeight+rsize)   
        ystep = -ystep;

    x += xstep;
    y += ystep;

    if(x > (windowWidth-rsize+xstep))
        x = windowWidth-rsize-1;
    else if(x<-(windowWidth+xstep))
        x = -windowWidth-1;

    if(y>(windowHeight+ystep))
        y = windowHeight -1;
    else if(y<-(windowHeight-rsize+ystep))
        y=-windowHeight + rsize - 1;

    glutPostRedisplay();
    glutTimerFunc(33, TimeFunction, 1);

}


void renderScene(void){
    glClear(GL_COLOR_BUFFER_BIT);
   
//    glPushMatrix();
//    glRotatef(angle, 0.0f, 1.0f, 0.0f);

 //   glColor3f(1.0, 0.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);
  /*  glBegin(GL_TRIANGLES);
        glVertex3f(0, 0, 0.0);
        glVertex3f(25, 0.0, 0.0);
        glVertex3f(0, 25, 0.0);
    glEnd();
   
    glPopMatrix();
*/

    glRectf(x, y, x+rsize, y-rsize);
    glutSwapBuffers();
}

void processingNormalKeys(unsigned char key, int x, int y){
    if(key == 27) exit(0);
}

void processingSpecialKeys(int key, int x, int y){
    switch(key){
        case GLUT_KEY_F1:
            red = 1.0;
            green = 0.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F2:
            red = 0.0;
            green = 1.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F3:
            red = 0.0;
            green = 0.0;
            blue = 1.0;
            break;
    }
}


int main (int argc, char **argv) {
    //init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(800, 600);
//    glutInitWindowSize(320, 320);
    glutCreateWindow("Bounce");

    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutTimerFunc(33, TimeFunction, 1);
    
//    glutKeyboardFunc(processingNormalKeys);
//    glutSpecialFunc(processingSpecialKeys);

    SetupRC();

    glutMainLoop();

    return 0;

    //register callbacks

    //enter GLUT event processing cycle
}
