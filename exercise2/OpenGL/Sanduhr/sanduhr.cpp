#ifndef LINUX
#include <windows.h>
#endif
#include <GL/glut.h>  
#include <GL/gl.h>   
#include <GL/glu.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>

#define ESCAPE 27

int window; 

int   n_vertices =  3;
float rot_x      = 0.0f;  
float rot_y      = 0.0f;  

static GLuint objekt_liste;

static void erzeuge_objekt_liste (void){
  int i;
  float phi, r = 2.0, x, z;
  
  glNewList(objekt_liste, GL_COMPILE);
  
  glBegin (GL_POLYGON);
  glColor3f(1.0f,0.0f,0.0f);
  for (i = 0; i < n_vertices; i ++) {
    phi = 2 * 3.14159265359 * i / (float) n_vertices;
    x = r * cos (phi);
    z = r * sin (phi);
    glVertex3f(x, -3.0f, z);
  }
  glEnd ();
  glBegin (GL_POLYGON);
  glColor3f(1.0f,0.0f,0.0f);
  for (i = 0; i < n_vertices; i ++) {
    phi = 2 * 3.14159265359 * i / (float) n_vertices;
    x = r * cos (phi);
    z = r * sin (phi);
    glVertex3f(x, 3.0f, z);
  }
  glEnd ();

  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0f,0.0f,0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  for (i = 0; i < n_vertices + 1; i ++) {
    phi = 2 * 3.14159265359 * i / (float) n_vertices;
    x = r * cos (phi);
    z = r * sin (phi);
    if (i%2 == 0){
      glColor3f(0.0f,1.0f,0.0f);
    }
    else{
      glColor3f(0.0f,0.0f,1.0f);
    }
    glVertex3f(x, -3.0f, z);
  }
  glEnd ();

  glBegin(GL_TRIANGLE_FAN);
  glColor3f(1.0f,0.0f,0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  for (i = 0; i < n_vertices + 1; i ++) {
    phi = 2 * 3.14159265359 * i / (float) n_vertices;
    x = r * cos (phi);
    z = r * sin (phi);
    if (i%2 == 0){
      glColor3f(0.0f,1.0f,0.0f);
    }
    else{
      glColor3f(0.0f,0.0f,1.0f);
    }
    glVertex3f(x, 3.0f, z);
  }
  glEnd ();

  glEndList();
}

void InitGL(int Width, int Height){
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);				
  glDepthFunc(GL_LESS);			        
  glEnable(GL_DEPTH_TEST);		        

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-5.0f, 5.0f, -5.0f, 5.0f, -7.0f, 7.0f);
  glMatrixMode(GL_MODELVIEW);
}

void DrawGLScene() {
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	

  glLoadIdentity();
  glTranslatef(0.0f, 0.0f,-2.0f);

  glRotatef(rot_x,1.0f,0.0f,0.0f);
  glRotatef(rot_y,0.0f,1.0f,0.0f);
  glCallList(objekt_liste);


  glutSwapBuffers();  /* Wechsele Buffer */
  glutReportErrors();					
}

void keyboard_func(unsigned char key, int x, int y) {
  if (key == ESCAPE) { 
    glutDestroyWindow(window); 
    exit(0);                   
  }
  if (key == '+') { 
    if (n_vertices < 50 ) {
      n_vertices++;
      erzeuge_objekt_liste();
      glutPostRedisplay();
      glutReportErrors();
    }
  }
  if (key == '-') { 
    if (n_vertices > 3 ) {
      n_vertices--;
      erzeuge_objekt_liste();
      glutPostRedisplay();
      glutReportErrors();
    }
  }
}

void specialkey_func (int key, int x, int y){
  if (key == GLUT_KEY_RIGHT) {
    rot_y += 2.0f;
  }
  if (key == GLUT_KEY_LEFT) {
    rot_y -= 2.0f;
  }
  if (key == GLUT_KEY_UP) {
    rot_x -= 2.0f;
  }
  if (key == GLUT_KEY_DOWN) {
    rot_x += 2.0f;
  }
  glutPostRedisplay();
  glutReportErrors();
}

int main(int argc, char **argv) {  
  glutInit(&argc, argv);  
  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);  /* Double-Buffer-Modus + Tiefen-Buffer-Modus*/
  glutInitWindowSize(640, 640);  
 
  glutInitWindowPosition(0, 0);  

  window = glutCreateWindow("Rotation");

  
  objekt_liste = glGenLists(1);
  erzeuge_objekt_liste();
  glutDisplayFunc(DrawGLScene);

  glutKeyboardFunc(keyboard_func);
  glutSpecialFunc(specialkey_func);
  InitGL(640, 480);
  glutMainLoop();  

  return 1;
}
