#ifndef LINUX
#include <windows.h>
#endif
#include <GL/glut.h>  
#include <GL/gl.h>   
#include <GL/glu.h> 
#include <stdio.h>  
#include <stdlib.h>

#define ESCAPE 27

int window;

int gelenk = 0;

float rot1 = 0.0f;
float rot2 = 0.0f;
float rot3 = 0.0f;
float rot4 = 0.0f;

static GLuint objekt_liste_blue    = 0;
static GLuint objekt_liste_red     = 0;
static GLuint objekt_liste_green   = 0;
static GLuint objekt_liste_yellow  = 0;


static void erzeuge_objekt_liste_blue (void){
  objekt_liste_blue = glGenLists(1);
  glNewList(objekt_liste_blue, GL_COMPILE);

  glColor3f(0.0f,0.0f,1.0f);   

  glBegin(GL_TRIANGLES);				
  glVertex3f( -2.8f, 0.8f, 0.0f);		        			
  glVertex3f( -3.0f, 0.0f, 0.0f);				
  glVertex3f(  0.0f, 0.0f, 0.0f);		        	  			

  glVertex3f( -2.8f, 0.8f, 0.7f);		        			
  glVertex3f( -3.0f, 0.0f, 0.7f);				
  glVertex3f(  0.0f, 0.0f, 0.7f);		        	
  glEnd();
  
  glBegin(GL_QUADS);
  glVertex3f( -2.8f, 0.8f, 0.0f);		        			
  glVertex3f( -3.0f, 0.0f, 0.0f);				
  glVertex3f( -3.0f, 0.0f, 0.7f);			      
  glVertex3f( -2.8f, 0.8f, 0.7f);		        			

  glVertex3f( -3.0f, 0.0f, 0.0f);				
  glVertex3f(  0.0f, 0.0f, 0.0f);		        	  			
  glVertex3f(  0.0f, 0.0f, 0.7f);		        	
  glVertex3f( -3.0f, 0.0f, 0.7f);				

  glVertex3f( -2.8f, 0.8f, 0.0f);		        			
  glVertex3f(  0.0f, 0.0f, 0.0f);		        	  			
  glVertex3f(  0.0f, 0.0f, 0.7f);		        	
  glVertex3f( -2.8f, 0.8f, 0.7f);		        			
  glEnd();

  glEndList();
}

static void erzeuge_objekt_liste_red (void){
  objekt_liste_red = glGenLists(1);
  glNewList(objekt_liste_red, GL_COMPILE);


  glColor3f(1.0f,0.0f,0.0f);
  
  glBegin(GL_TRIANGLE_FAN);				
  glVertex3f( 2.0f, 1.8f, 0.0f);		        			
  glVertex3f( 2.3f, 1.2f, 0.0f);				
  glVertex3f( 0.0f, 0.0f, 0.0f);		        	
  glVertex3f( 2.0f, 1.8f, 0.7f);		        			
  glVertex3f( 2.3f, 1.2f, 0.7f);				
  glVertex3f( 0.0f, 0.0f, 0.7f);		        	
  glEnd();

  glBegin(GL_QUADS);
  glVertex3f( 2.0f, 1.8f, 0.0f);		        			
  glVertex3f( 2.3f, 1.2f, 0.0f);				
  glVertex3f( 2.3f, 1.2f, 0.7f);				
  glVertex3f( 2.0f, 1.8f, 0.7f);		        			

  glVertex3f( 2.3f, 1.2f, 0.0f);				
  glVertex3f( 0.0f, 0.0f, 0.0f);		        	
  glVertex3f( 0.0f, 0.0f, 0.7f);		        	
  glVertex3f( 2.3f, 1.2f, 0.7f);				

  glVertex3f( 2.0f, 1.8f, 0.0f);		        			
  glVertex3f( 0.0f, 0.0f, 0.0f);		        	
  glVertex3f( 0.0f, 0.0f, 0.7f);		        	
  glVertex3f( 2.0f, 1.8f, 0.7f);		        			
  glEnd();

  glEndList();
}

static void erzeuge_objekt_liste_green (void){
  objekt_liste_green = glGenLists(1);
  glNewList(objekt_liste_green, GL_COMPILE);
  
  glColor3f(0.0f,1.0f,0.0f);
  glBegin(GL_TRIANGLES);				
  glVertex3f( 2.3f, 2.5f, 0.0f);		        			
  glVertex3f( 2.5f, 2.3f, 0.0f);				
  glVertex3f( 2.0f, 1.8f, 0.0f);		        	
  glVertex3f( 2.3f, 2.5f, 0.5f);		        			
  glVertex3f( 2.5f, 2.3f, 0.5f);				
  glVertex3f( 2.0f, 1.8f, 0.5f);		        	
  glEnd(); 
  
  glBegin(GL_QUADS);
  glVertex3f( 2.3f, 2.5f, 0.0f);		        			
  glVertex3f( 2.5f, 2.3f, 0.0f);				
  glVertex3f( 2.5f, 2.3f, 0.5f);				
  glVertex3f( 2.3f, 2.5f, 0.5f);		        			

  glVertex3f( 2.5f, 2.3f, 0.0f);				
  glVertex3f( 2.0f, 1.8f, 0.0f);		        	
  glVertex3f( 2.0f, 1.8f, 0.5f);		        	
  glVertex3f( 2.5f, 2.3f, 0.5f);				

  glVertex3f( 2.3f, 2.5f, 0.0f);		        			
  glVertex3f( 2.0f, 1.8f, 0.0f);		        	
  glVertex3f( 2.0f, 1.8f, 0.5f);		        	
  glVertex3f( 2.3f, 2.5f, 0.5f);		        			
  glEnd();

  glEndList();
}

static void erzeuge_objekt_liste_yellow (void){
  objekt_liste_yellow = glGenLists(1);
  glNewList(objekt_liste_yellow, GL_COMPILE);

  glColor3f(1.0f,1.0f,0.0f);
  glBegin(GL_TRIANGLES);				
  glVertex3f( 2.95f, 1.6f,  0.0f);		        			
  glVertex3f( 3.0f,  1.35f, 0.0f);				
  glVertex3f( 2.3f,  1.2f,  0.0f);		        	
  glVertex3f( 2.95f, 1.6f,  0.5f);		        			
  glVertex3f( 3.0f,  1.35f, 0.5f);				
  glVertex3f( 2.3f,  1.2f,  0.5f);		        	
  glEnd();  

  glBegin(GL_QUADS);
  glVertex3f( 2.95f, 1.6f,  0.0f);		        			
  glVertex3f( 3.0f,  1.35f, 0.0f);				
  glVertex3f( 3.0f,  1.35f, 0.5f);				
  glVertex3f( 2.95f, 1.6f,  0.5f);		        			

  glVertex3f( 3.0f,  1.35f, 0.0f);				
  glVertex3f( 2.3f,  1.2f,  0.0f);		        	
  glVertex3f( 2.3f,  1.2f,  0.5f);		        	
  glVertex3f( 3.0f,  1.35f, 0.5f);				

  glVertex3f( 2.95f, 1.6f,  0.0f);		        			
  glVertex3f( 2.3f,  1.2f,  0.0f);		        	
  glVertex3f( 2.3f,  1.2f,  0.5f);		        	
  glVertex3f( 2.95f, 1.6f,  0.5f);		        			
		        			
  glEnd();

  glEndList();
}


void keyboard_func(unsigned char key, int x, int y) {
  //Zahleneingabe
  if (key=='1' || key=='2' || key=='3' || key=='4'){
    gelenk = key-48;
    printf("Gelenk Nr. %i ist aktiv.\n", gelenk);
  }
  if(key=='-'){
    if(gelenk==1 && rot1<45.0) rot1 += 1.0f;
    if(gelenk==2 && rot2<45.0) rot2 += 1.0f;
    if(gelenk==3 && rot3<45.0) rot3 += 1.0f;
    if(gelenk==4 && rot4<45.0) rot4 += 1.0f;
  }
  
  if(key=='+'){
    if(gelenk==1 && rot1>-45.0) rot1 -= 1.0f;
    if(gelenk==2 && rot2>-45.0) rot2 -= 1.0f;
    if(gelenk==3 && rot3>-45.0) rot3 -= 1.0f;
    if(gelenk==4 && rot4>-45.0) rot4 -= 1.0f;
  }
  if (key == ESCAPE) { 
    glutDestroyWindow(window); 
    exit(0);                   
  }
  glutPostRedisplay();
  glutReportErrors();
}


void DrawGLScene() {
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);	
 
  glLoadIdentity();
  glTranslatef(-3.0f, 0.0f,0.0f);
  glRotatef(rot1,0.0f,0.0f,1.0f);
  glTranslatef(3.0f, 0.0f,0.0f);
  
  glCallList(objekt_liste_blue);
  
  glRotatef(rot2,0.0f,0.0f,1.0f);
  
  glCallList(objekt_liste_red);
  
  glPushMatrix();
  
  glTranslatef(2.0f, 1.8f,0.0f);
  glRotatef(rot3,0.0f,0.0f,1.0f);
  glTranslatef(-2.0f, -1.8f,0.0f);
  glCallList(objekt_liste_green);
  
  glPopMatrix();
  
  glTranslatef(2.3f, 1.2f,0.0f);
  glRotatef(rot4,0.0f,0.0f,1.0f);
  glTranslatef(-2.3f, -1.2f,0.0f);
  glCallList(objekt_liste_yellow);
  
  //Wechsel-Buffer
  glutSwapBuffers();
  glutReportErrors();					
}

void InitGL(int Width, int Height){
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);				
  glDepthFunc(GL_LESS);			        
  glEnable(GL_DEPTH_TEST);		        

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-5.0f, 5.0f, -5.0f, 5.0f, -5.0f, 5.0f);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {  
  glutInit(&argc, argv);  
  
  //Double-Buffer
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);  /* Double-Buffer-Modus */

  glutInitWindowSize(640, 640);  

  glutInitWindowPosition(0, 0);  

  window = glutCreateWindow("Roboterarm");

  erzeuge_objekt_liste_blue();
  erzeuge_objekt_liste_red();
  erzeuge_objekt_liste_green();
  erzeuge_objekt_liste_yellow();
  glutDisplayFunc(DrawGLScene);

  glutKeyboardFunc(keyboard_func);
  InitGL(640, 480);
  glutMainLoop();  

  return 1;
}
