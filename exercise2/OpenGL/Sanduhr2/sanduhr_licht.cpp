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

int   n_vertices =  8;
float rot_x      = 0.0f;  
float rot_y      = 0.0f;  
float l_rot      = 0.0f;  

GLfloat mat_r_ambient[]	   = { 1.0,  0.0,  0.0,  1.0};
GLfloat mat_r_diffuse[]	   = { 0.8,  0.1,  0.1,  1.0};
GLfloat mat_r_specular[]   = { 0.7,  0.2,  0.1,  1.0};
GLfloat mat_r_shininess[]  = { 10.0 };
GLfloat mat_r_emission[]   = { 0.0,  0.0,  0.0,  0.0};

GLfloat mat_g_ambient[]	   = { 0.0,  1.0,  0.0,  1.0};
GLfloat mat_g_diffuse[]	   = { 0.1,  0.8,  0.1,  1.0 };
GLfloat mat_g_specular[]   = { 0.2,  0.7,  0.1,  1.0 };
GLfloat mat_g_shininess[]  = { 10.0 };
GLfloat mat_g_emission[]   = { 0.0,  0.0,  0.0,  0.0};

GLfloat mat_b_ambient[]	   = { 0.0,  0.0,  1.0,  1.0};
GLfloat mat_b_diffuse[]	   = { 0.1,  0.1,  0.8,  1.0};
GLfloat mat_b_specular[]   = { 0.1,  0.2,  0.8,  1.0};
GLfloat mat_b_shininess[]  = { 10.0 };
GLfloat mat_b_emission[]   = { 0.0,  0.0,  0.0,  0.0};

GLfloat light0_ambient[]   = { 0.1, 0.1, 0.1,   1.0 };
GLfloat light0_diffuse[]   = { 1.0, 1.0, 1.0,   1.0 };
GLfloat light0_specular[]  = { 1.0, 1.0, 1.0,   1.0 };
GLfloat light0_position[]  = { 0.0, 0.0, 0.0,   1.0 };
GLfloat spot0_direction[]  = { 0.0, 0.0, -1.0}; 

GLfloat light1_ambient[]   = { 0.0, 0.0, 0.0,   1.0 };
GLfloat light1_diffuse[]   = { 0.0, 0.0, 1.0,   1.0 };
GLfloat light1_specular[]  = { 0.0, 0.0, 1.0,   1.0 };
GLfloat light1_position[]  = { 0.0, 0.0, 0.0,   1.0 };
GLfloat spot1_direction[]  = { 0.0, 0.0, -1.0}; 

static GLuint objekt_liste;

static void erzeuge_objekt_liste (void){
  int i;
  float phi, r = 2.0, x, z;
  
  objekt_liste = glGenLists(1);
  glDeleteLists(objekt_liste,objekt_liste+1);
  
  glNewList(objekt_liste, GL_COMPILE);
  
  glBegin (GL_POLYGON);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_r_ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_r_diffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_r_specular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_r_shininess);
  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  mat_r_emission);

  for (i = 0; i < n_vertices; i ++) {
    phi = 2 * 3.14159265359 * i / (float) n_vertices;
    x = r * cos (phi);
    z = r * sin (phi);
    glNormal3f(0.0f,-1.0f, 0.0f);
    glVertex3f(x,   -3.0f, z);
  }
  glEnd ();

  glBegin (GL_POLYGON);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_r_ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_r_diffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_r_specular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_r_shininess);
  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  mat_r_emission);

  for (i = 0; i < n_vertices; i ++) {
    phi = 2 * 3.14159265359 * i / (float) n_vertices;
    x = r * cos (phi);
    z = r * sin (phi);
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x,    3.0f, z);
  }
  glEnd ();

  glBegin(GL_TRIANGLE_FAN);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_r_ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_r_diffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_r_specular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_r_shininess);
  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  mat_r_emission);

  glNormal3f(0.0,  1.0f, 0.0);
  glVertex3f(0.0f, 0.0f, 0.0f);
  for (i = 0; i < n_vertices + 1; i ++) {
    phi = 2 * 3.14159265359 * i / (float) n_vertices;
    x = r * cos (phi);
    z = r * sin (phi);
    if (i%2 == 0){
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_g_ambient);
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_g_diffuse);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_g_specular);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_g_shininess);
      glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  mat_g_emission);
    }
    else{
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_b_ambient);
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_b_diffuse);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_b_specular);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_b_shininess);
      glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  mat_b_emission);
    }
    glNormal3f(x,  0.0f, z);
    glVertex3f(x, -3.0f, z);
  }
  glEnd ();
  
  glBegin(GL_TRIANGLE_FAN);
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_r_ambient);
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_r_diffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_r_specular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_r_shininess);
  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  mat_r_emission);

  glNormal3f(0.0, -1.0f, 0.0);
  glVertex3f(0.0f, 0.0f, 0.0f);
  for (i = 0; i < n_vertices + 1; i ++) {
    phi = 2 * 3.14159265359 * i / (float) n_vertices;
    x = r * cos (phi);
    z = r * sin (phi);
    if (i%2 == 0){
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_g_ambient);
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_g_diffuse);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_g_specular);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_g_shininess);
      glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  mat_g_emission);
    }
    else{
      glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT,   mat_b_ambient);
      glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE,   mat_b_diffuse);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,  mat_b_specular);
      glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_b_shininess);
      glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION,  mat_b_emission);
    }
    glNormal3f(x, 0.0f, z);
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
  glEnable(GL_NORMALIZE);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-7.0f, 7.0f, -7.0f, 7.0f, -20.0f, 20.0f);
  glMatrixMode(GL_MODELVIEW);

  glLightfv(GL_LIGHT0, GL_AMBIENT,  light0_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE,  light0_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular);
  glLightfv(GL_LIGHT1, GL_AMBIENT,  light1_ambient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE,  light1_diffuse);
  glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

  /* Festlegen der Abschwaechung */
  glLightf(GL_LIGHT0,  GL_CONSTANT_ATTENUATION,     1.0);
  glLightf(GL_LIGHT0,  GL_LINEAR_ATTENUATION,       0.0);
  glLightf(GL_LIGHT0,  GL_QUADRATIC_ATTENUATION,    0.0); 
  glLightf(GL_LIGHT1,  GL_CONSTANT_ATTENUATION,     1.0);
  glLightf(GL_LIGHT1,  GL_LINEAR_ATTENUATION,       0.0);
  glLightf(GL_LIGHT1,  GL_QUADRATIC_ATTENUATION,    0.0); 
  
  /* Festlegen des Strahlerkegels */
  glLightf(GL_LIGHT0,  GL_SPOT_CUTOFF,   30.0);
  glLightf(GL_LIGHT0,  GL_SPOT_EXPONENT,  5.0); 
  glLightf(GL_LIGHT1,  GL_SPOT_CUTOFF,   30.0);
  glLightf(GL_LIGHT1,  GL_SPOT_EXPONENT,  5.0); 
}


void DrawGLScene() {
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);

  glDisable(GL_LIGHTING);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f,-15.0f);


  glPushMatrix();
  ///* Beachte: Die folgenden Transformationen werden in inverser Reihenfolge durchgefuehrt !*/
  glTranslatef(-6.0f, 6.0f, 6.0f);   
  glRotatef(-45.0, 1.0f,1.0f,0.0f); /* Drehe -z Achse auf -x,-y,-z-Achse */
  glRotatef(l_rot, 0.0f,0.0f,1.0f); /* Rotation um z-Achse */ 
  glRotatef(-15.0, 1.0f,0.0f,0.0f); /* 15°-Winkel*/ 

  glLightfv(GL_LIGHT0, GL_POSITION,       light0_position);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot0_direction);
  glEnable(GL_LIGHT0); 
  glutSolidSphere (0.1, 20, 16);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(6.0f, 0.0f,0.0f);    
  glRotatef(90.0, 0.0f,1.0f,0.0f);  /* Drehe -z-Achse auf -x-Achse */
  glRotatef(l_rot, 0.0f,0.0f,1.0f); /* Rotation um z-Achse */ 
  glRotatef(-15.0, 1.0f,0.0f,0.0f); /* 15°-Winkel*/ 
  /* Strahler befindet sich im Ursprung und zeigt in -z-Richtung */
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot1_direction);
  glLightfv(GL_LIGHT1, GL_POSITION,       light1_position);
  glEnable(GL_LIGHT1);
  glutSolidSphere (0.1, 20, 16);
  glPopMatrix();

  glEnable(GL_LIGHTING);
  glPushMatrix();
  glRotatef(rot_x,1.0f,0.0f,0.0f);
  glRotatef(rot_y,0.0f,1.0f,0.0f);
  glCallList(objekt_liste);
  glPopMatrix();
  glutSwapBuffers();  /* Wechsele Buffer */
  glutReportErrors();					
}

void keyboard_func(unsigned char key, int x, int y) {
  if (key == ESCAPE) { 
    glutDestroyWindow(window); 
    exit(0);                   
  }
  if (key == '+') {
    l_rot += 2.0f;
    rot_y += 2.0f;
  }
  if (key == '-') {
    rot_y -= 2.0f;
    l_rot -= 2.0f;
  }
  glutPostRedisplay();
  glutReportErrors();
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
  
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);  /* Double-Buffer-Modus */
  glutInitWindowSize(640, 640);  
 
  glutInitWindowPosition(0, 0);  

  window = glutCreateWindow(argv[0]);

  erzeuge_objekt_liste();
  glutDisplayFunc(DrawGLScene);

  glutKeyboardFunc(keyboard_func);
  glutSpecialFunc(specialkey_func);
  InitGL(640, 640);
  glutMainLoop();  

  return 1;
}
