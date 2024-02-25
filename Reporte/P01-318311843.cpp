//ARCHIVO SEMESTRE 2024-1
#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
#include <string.h>
#include <glew.h>
#include <glfw3.h>

//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 800;
GLuint VAO, VBO, shader;
float Rojo, Verde, Azul;

//Vertex Shader
//recibir color, salida Vcolor
static const char* vShader = "						\n\
#version 330										\n\
layout (location =0) in vec3 pos;					\n\
void main()											\n\
{													\n\
gl_Position=vec4(pos.x,pos.y,pos.z,1.0f); 			\n\
}";
//recibir Vcolor y dar de salida color
static const char* fShader = "						\n\
#version 330										\n\
out vec4 color;										\n\
void main()											\n\
{													\n\
	color = vec4(0.4f,0.0f,1.0f,1.0f);	 			\n\
}";



void CrearTriangulo()
{
	GLfloat vertices[] = {

		//Letra E

		-0.9f, 0.8f,0.0f,
		-0.9f,0.75f, 0.0f,
		-0.7f,0.8f,0.0f,

		- 0.9f,0.75f, 0.0f,
		-0.7f,0.8f,0.0f,
		-0.7f,0.75f, 0.0f,
		//
		-0.9f, 0.7f,0.0f,
		-0.9f,0.65f, 0.0f,
		-0.7f,0.7f,0.0f,

		-0.9f,0.65f, 0.0f,
		-0.7f,0.7f,0.0f,
		-0.7f,0.65f, 0.0f,
		//
		- 0.9f, 0.6f,0.0f,
		-0.9f,0.55f, 0.0f,
		-0.7f,0.6f,0.0f,

		-0.9f,0.55f, 0.0f,
		-0.7f,0.6f,0.0f,
		-0.7f,0.55f, 0.0f,
		//
		- 0.9f, 0.8f,0.0f,
		-0.9f,0.55f, 0.0f,
		-0.85f,0.55f, 0.0f,

		-0.9f, 0.8f,0.0f,
		-0.85f,0.55f, 0.0f,
		-0.85f,0.8f, 0.0f,

		//Letra P

		-0.6f, 0.8f,0.0f,
		-0.6f,0.75f, 0.0f,
		-0.4f,0.8f,0.0f,

		-0.6f,0.75f, 0.0f,
		-0.4f,0.8f,0.0f,
		-0.4f,0.75f, 0.0f,
		//
		-0.6f, 0.7f,0.0f,
		-0.6f,0.65f, 0.0f,
		-0.4f,0.7f,0.0f,

		-0.6f,0.65f, 0.0f,
		-0.4f,0.7f,0.0f,
		-0.4f,0.65f, 0.0f,
		//
		-0.4f,0.8f,0.0f,
		-0.45f,0.8f,0.0f,
		-0.4f,0.65f,0.0f,

		-0.4f,0.65f,0.0f,
		-0.45f,0.65f,0.0f,
		-0.45f,0.8f,0.0f,
		//
		-0.6f, 0.8f,0.0f,
		-0.6f,0.55f, 0.0f,
		-0.55f,0.55f, 0.0f,

		-0.6f, 0.8f,0.0f,
		-0.55f,0.55f, 0.0f,
		-0.55f,0.8f, 0.0f,

		//Letra B

		-0.3f, 0.8f,0.0f,
		-0.3f,0.75f, 0.0f,
		-0.15f,0.8f,0.0f,

		-0.3f,0.75f, 0.0f,
		-0.15f,0.8f,0.0f,
		-0.15f,0.75f, 0.0f,
		//
		-0.15f,0.8f,0.0f,
		-0.2f,0.8f,0.0f,
		-0.15f,0.7f,0.0,

		-0.15f,0.7f,0.0f,
		-0.2f,0.7f,0.0f,
		-0.2f,0.8f,0.0,
		//
		-0.3f, 0.7f,0.0f,
		-0.3f,0.65f, 0.0f,
		-0.1f,0.7f,0.0f,
	
		-0.3f,0.65f, 0.0f,
		-0.1f,0.7f,0.0f,
		-0.1f,0.65f, 0.0f,
		//
		-0.1f,0.7f,0.0f,
		-0.15,0.7f,0.0f,
		-0.1f,0.6f,0.0f,

		-0.1f,0.6f,0.0f,
		-0.15,0.6f,0.0f,
		-0.15f,0.7f,0.0f,
		//
		-0.3f, 0.6f,0.0f,
		-0.3f,0.55f, 0.0f,
		-0.1f,0.6f,0.0f,

		-0.3f,0.55f, 0.0f,
		-0.1f,0.6f,0.0f,
		-0.1f,0.55f, 0.0f,
		//
		-0.3f, 0.8f,0.0f,
		-0.3f,0.55f, 0.0f,
		-0.25f,0.55f, 0.0f,

		-0.3f, 0.8f,0.0f,
		-0.25f,0.55f, 0.0f,
		-0.25f,0.8f, 0.0f


	};
	glGenVertexArrays(1, &VAO); //generar 1 VAO
	glBindVertexArray(VAO);//asignar VAO

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //pasarle los datos al VBO asignando tamano, los datos y en este caso es est�tico pues no se modificar�n los valores

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);//Stride en caso de haber datos de color por ejemplo, es saltar cierta cantidad de datos
	glEnableVertexAttribArray(0);
	//agregar valores a v�rtices y luego declarar un nuevo vertexAttribPointer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}
void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType) //Funci�n para agregar los shaders a la tarjeta gr�fica
//the Program recibe los datos de theShader


{
	GLuint theShader = glCreateShader(shaderType);//theShader es un shader que se crea de acuerdo al tipo de shader: vertex o fragment
	const GLchar* theCode[1];
	theCode[0] = shaderCode;//shaderCode es el texto que se le pasa a theCode
	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);//longitud del texto
	glShaderSource(theShader, 1, theCode, codeLength);//Se le asigna al shader el c�digo
	glCompileShader(theShader);//Se comila el shader
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	//verificaciones y prevenci�n de errores
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al compilar el shader %d es: %s \n", shaderType, eLog);
		return;
	}
	glAttachShader(theProgram, theShader);//Si no hubo problemas se asigna el shader a theProgram el cual asigna el c�digo a la tarjeta gr�fica
}

void CompileShaders() {
	shader = glCreateProgram(); //se crea un programa
	if (!shader)
	{
		printf("Error creando el shader");
		return;
	}
	AddShader(shader, vShader, GL_VERTEX_SHADER);//Agregar vertex shader
	AddShader(shader, fShader, GL_FRAGMENT_SHADER);//Agregar fragment shader
	//Para terminar de linkear el programa y ver que no tengamos errores
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	glLinkProgram(shader);//se linkean los shaders a la tarjeta gr�fica
	//verificaciones y prevenci�n de errores
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al linkear es: %s \n", eLog);
		return;
	}
	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al validar es: %s \n", eLog);
		return;
	}



}
int main()
{
	//Inicializaci�n de GLFW
	if (!glfwInit())
	{
		printf("Fall� inicializar GLFW");
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
	GLFWwindow* ventana01 = glfwCreateWindow(WIDTH, HEIGHT, "Primer ventana", NULL, NULL);
	GLFWwindow* ventana02 = glfwCreateWindow(WIDTH, HEIGHT, "Segunda ventana", NULL, NULL);

	if (!ventana01 or !ventana02)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tama�o de Buffer
	int BufferWidth_01, BufferHeight_01;
	glfwGetFramebufferSize(ventana01, &BufferWidth_01, &BufferHeight_01);

	int BufferWidth_02, BufferHeight_02;
	glfwGetFramebufferSize(ventana01, &BufferWidth_02, &BufferHeight_02);

	//asignar el contexto
	glfwMakeContextCurrent(ventana02);

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Fall� inicializaci�n de GLEW");
		glfwDestroyWindow(ventana01);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas
	//Asignar Viewport
	glViewport(0, 0, BufferWidth_02, BufferHeight_02);

	//Crear tr�angulo
	CrearTriangulo();
	CompileShaders();


	//Loop mientras no se cierra la ventana
	while (!glfwWindowShouldClose(ventana01) && !glfwWindowShouldClose(ventana02))
	{
		Rojo = (float)(rand() % 101) / 100;
		Verde = (float)(rand() % 101) / 100;
		Azul = (float)(rand() % 101) / 100;
		
		glfwMakeContextCurrent(ventana02);
		//Recibir eventos del usuario
		glfwPollEvents();

		//Limpiar la ventana
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 84);
		glBindVertexArray(0);

		glUseProgram(0);

		glfwSwapBuffers(ventana02);


		glfwMakeContextCurrent(ventana01);
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(Rojo, Verde, Azul, 1.0f);

		Sleep(2000);

		glClear(GL_COLOR_BUFFER_BIT);//Limpiar el buffer de color

		glfwSwapBuffers(ventana01);

	}


	return 0;
}