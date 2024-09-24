#include <GLFW/glfw3.h>
#include <unistd.h>
#include <GLUT/glut.h> 
#include <math.h> 

void showObj(){

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(.0f, .0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(.0f, .5f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(.5f, .5f); 
    glEnd(); 

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
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.7f, 1.0f, 0.7f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity(); 

        glRotated(alpha, 0, 0, 1);  

        alpha -= 0.1;  
        for (int i=0; i<8; i++){
            glPushMatrix();
            glRotated(i*45, 0, 0, 1);  
            showObj();
            glPopMatrix();
        }
       
        glfwPollEvents();
        glfwSwapBuffers(window);
        usleep(1);
    }

    glfwTerminate();
    return 0;
}