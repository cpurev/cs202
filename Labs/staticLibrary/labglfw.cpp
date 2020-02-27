//labglfw.cpp
//2020-2-20
//Chuluunbat Purev
//GLFW lib lab

#include <GLFW/glfw3.h>
#include <cmath>

#pragma comment(lib, "GLFW3.lib")
#pragma comment(lib, "OpenGL32.lib")

int main(void) {

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);



	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {

		glClearColor(0, 0, 0, 1);

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glColor3f(0, 1, 0.94);
		glLoadIdentity();
		float angle = (float)glfwGetTime(); // This GLFW function returns the time in seconds as a double
		float c = 0.1f * std::cos(angle * 3.14159f / 180.0f);
		float s = 0.1f * std::cos(angle * 3.14159f / 180.0f);
		glTranslatef(c, s, 0.0f);
		glScalef(1 + c, 1 + s, 1.0f);
		glRotatef(angle * 30.0f, 0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		glVertex3f(-1.f, -1.f, 0.0f); // bottom left
		glVertex3f(1.f, -1.f, 0.0f); // bottom right
		glVertex3f(0.0f, 1.f, 0.0f); // middle top
		glEnd();

		glLoadIdentity();
		glBegin(GL_LINE_LOOP);
		for (float a = 0.0f; a < 360.0f; a += 1.0f) {
			float c = std::cos(a * 3.14159f / 180.0f);
			float s = std::sin(a * 3.14159f / 180.0f);
			glColor3f(std::abs(c), std::abs(s), 0.0f);
			glVertex3f(c, s, 0.0f);
		}
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}