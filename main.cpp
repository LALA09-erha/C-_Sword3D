#include <windows.h>
#include <GL/glut.h>



double rotasi = 0;
double rotasi_1 = 0;
double rotasi_2 = 0;

GLfloat sumber_cahaya[] = {0.8, 0.8, 0.8, 1.0};

// Prosedur Pencahayaan
void cahaya(void)
{

    glShadeModel(GL_SMOOTH);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST); // untuk permukaan
    glEnable(GL_LIGHTING);   // pemanggilan parameter lihghting
    glLightfv(GL_LIGHT0, GL_DIFFUSE, sumber_cahaya);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void layar(int lebar, int tinggi)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 100);
}
void ganggang()
{
    float i;
    glTranslatef(0.0, 0.0, -0.25);
    glColor3f(0,0.5,1);
    glutSolidSphere(2,16,16);
    glColor3f(0,1,1);
    for (i = 0; i <= 7; i += 0.125)
    {
        glTranslatef(0.0, 0.0, 0.125);
        glutSolidTorus(0.25, 1, 16, 16);
    }
}

// buat method display(method penampilan gambar
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // membersihkan layar latar belakang
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, -15, -90); // POSISI AWAL
    glRotatef(rotasi, 0, 1, 0);
    glRotatef(rotasi_1, 1, 0, 0);
    glRotatef(rotasi_2, 0, 0, 1);
    glRotatef(270, 1.0, 0.0, 0.0); // kamera
    ganggang();
    glTranslatef(0.0, 0.0, 0);
    glColor3f(0,0.5,1);
    glutSolidTorus(4,2,3,4);
    glColor3f(1,1,1);
    glutSolidCone(3,35,3,3);
    glFlush();
    glutSwapBuffers();
}


// efek keyboard
void aksi_keyboard(unsigned char key, int x, int y)
{
     if(key == 'w')
        rotasi_1 -=15;
     else if(key =='s')
        rotasi_1 +=15;
     else if(key == 'a')
        rotasi_2 +=15;
     else if(key =='d')
        rotasi_2 -=15;


}

// interaksi melalui mouse
void aksi_mouse(int tombol, int aksi, int x, int y)
{
    if (aksi == GLUT_DOWN && tombol == GLUT_LEFT_BUTTON)
    {

        rotasi -= 15;
    }
    if (aksi == GLUT_DOWN && tombol == GLUT_RIGHT_BUTTON)
    {

        rotasi += 15;
    }
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("UAS GRAFKOM");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(layar);
    glutKeyboardFunc(aksi_keyboard);
    glutMouseFunc(aksi_mouse);
    cahaya();
    glutMainLoop();
    return (0);
}
