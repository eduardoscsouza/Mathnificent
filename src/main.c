#include <GL/glut.h>

void draw(void) {}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutCreateWindow("Teste");

    glutDisplayFunc(&draw);
    glutMainLoop();
    return 0;
}
