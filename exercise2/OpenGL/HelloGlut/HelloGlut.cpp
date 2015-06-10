#ifndef LINUX
#include <windows.h>
#endif

#include <iostream>

#include <GL/gl.h>
#include <GL/glut.h>

#define ESCAPE 27


void display_func (void)
{
  //Festlegen der Leerfarbe
  glClearColor (1, 1, 1, 0);
  //Setzt die Leerfarbe
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush ();
  glutReportErrors ();
}


static void keyboard_func (unsigned char key, int x, int y)
{
  /* Abbrechen mit ESCACE */
  if (key == ESCAPE) exit (0); /* Einfach aber unschön. Bessere Version siehe 02_Sanduhr */
  else
	  std::cout << "KEY = " << key << std::endl;
}

static void special_key_func(int key, int x, int y)
{
  if (key == GLUT_KEY_RIGHT) {
    std::cout << "KEY: " << "RIGHT" << std::endl;
  }
  if (key == GLUT_KEY_LEFT) {
    std::cout << "KEY: " << "LEFT" << std::endl;
  }
  if (key == GLUT_KEY_UP) {
    std::cout << "KEY: " << "UP" << std::endl;
  }
  if (key == GLUT_KEY_DOWN) {
	  std::cout << "KEY: " << "DOWN" << std::endl;
  }
}


int main(int argc, char **argv)
{
  
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_RGB);
  
  glutInitWindowPosition (200, 100);
  glutInitWindowSize (800, 600);
  glutCreateWindow("Hello Glut");
  
  glutDisplayFunc(display_func);

  glutKeyboardFunc(keyboard_func);  	
  glutSpecialFunc(special_key_func);
  glutMainLoop();
  
  return 0;
}
