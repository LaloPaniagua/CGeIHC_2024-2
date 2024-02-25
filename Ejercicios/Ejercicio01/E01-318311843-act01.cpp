#include <stdio.h>
#include <windows.h>   
#include <glew.h>
#include <glfw3.h>
//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;
float ROJO, VERDE, AZUL = 0.0f;
int estado = 2;
int main()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1 ejercicio 1", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	//Se guarda en memoria el tamaño de la ventana por si es necesario redimensionarla en tiempo de ejecución
	int BufferWidth, BufferHeight;
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//asignar el contexto
	//Establece al contenedor como la ventana activa
	glfwMakeContextCurrent(mainWindow);

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//Primera línea de OpenGL :D
	// Asignar valores de la ventana y coordenadas
	//Asignar Viewport
	glViewport(0, 0, BufferWidth, BufferHeight); //Recibe el tamaño de acuerdo a lo guardado en el buffer de memoria
	printf("Version de Opengl: %s \n",glGetString(GL_VERSION));
	printf("Marca: %s \n", glGetString(GL_VENDOR));
	printf("Renderer: %s \n", glGetString(GL_RENDERER));
	printf("Shaders: %s \n", glGetString(GL_SHADING_LANGUAGE_VERSION));



	//Loop mientras no se cierra la ventana
	while (!glfwWindowShouldClose(mainWindow))
	{
		if (estado < 2)
		{
			estado = estado + 1;
		}
		else
		{
			estado = 0;
		}

		switch (estado) 
		{
			case 0:
				ROJO = 1.0f;
				VERDE = 0.0f;
				AZUL = 0.0f;
				break;
			case 1:
				ROJO = 0.0f;
				VERDE = 1.0f;
				AZUL = 0.0f;
				break;
			default:
				ROJO = 0.0f;
				VERDE = 0.0f;
				AZUL = 1.0f;
				break;
		}

		//Recibir eventos del usuario
		glfwPollEvents();

		//Limpiar la ventana
		glClearColor(ROJO,VERDE,AZUL,1.0f);

		Sleep(500);

		glClear(GL_COLOR_BUFFER_BIT);//Limpiar el buffer de color

		glfwSwapBuffers(mainWindow);
		//Lo que se escriba después de este while no se ve en pantalla
	}


	return 0;
}