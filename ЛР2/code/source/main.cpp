#include <GLFW/glfw3.h>
#include <unistd.h>
#include <GLUT/glut.h> 
#include <OpenGL/gl.h> 
#include <math.h> 


typedef struct _POINTFLOAT {
  float x;
  float y;
  float z;
} POINTFLOAT, *PPOINTFLOAT;

void showObj(){
    float colors[] = {
        0, 0, 0,
        0, 0, 1, 
        0, 1, 0,
        0, 1, 1,
        1, 0, 0, 
        1, 0, 1
    };

    POINTFLOAT verties[] = {
        {0, 0, 2}, 
        {1, 1, 0},
        {1, -1, 0}, 
        {-1, -1, 0}, 
        {-1, 1, 0}, 
        {1, 1, 0},

    };
    glPushMatrix();
    glVertexPointer(3, GL_FLOAT, 0, &verties);
    glColorPointer(3, GL_FLOAT, 0, &colors);
    
    glEnableClientState(GL_VERTEX_ARRAY); 
    glEnableClientState(GL_COLOR_ARRAY);
        //glColor3f(0.5f, 0.5f, 0.5f);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 6); 

    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();


}

int main(void)
{
    float alpha = 0.0f; 
    int height = 700; 
    int weith = 700; 

    GLFWwindow* window;
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(height, weith, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glLoadIdentity(); 
    glFrustum(-1, 1, -1, 1, 2, 80); // перспективная проекция 
    glTranslatef(0, -1, -5); 
    glRotated(-90, 1, 0, 0);
    glEnable(GL_DEPTH_TEST);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        showObj();
        glRotatef(1, 0, 0, 1);
        glfwPollEvents();
        glfwSwapBuffers(window);
        
        usleep(1);
    }

    glfwTerminate();
    return 0;
}