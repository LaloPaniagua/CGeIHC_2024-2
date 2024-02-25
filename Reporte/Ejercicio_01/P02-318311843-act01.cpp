//Las variables uniform se ocupan para mandarles datos desde openGL y que las reciba el shader
//Práctica 2 semestre 2024-2: índices, mesh, proyecciones, transformaciones geométricas
#include <stdio.h>
#include <string.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp>//Biblioteca matemácica con funciones para gráficas, se usará para matrices entre otros propósitos, ocupa matrices cuadradas
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
//clases para dar orden y limpieza al código
#include"Mesh.h"
#include"Shader.h"
#include"Window.h"
//Dimensiones de la ventana
const float toRadians = 3.14159265f / 180.0; //grados a radianes, rotate usa gradianes
Window mainWindow;
std::vector<Mesh*> meshList;
std::vector<MeshColor*> meshColorList;
std::vector<Shader>shaderList;
//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";
static const char* vShaderColor = "shaders/shadercolor.vert";
static const char* fShaderColor = "shaders/shadercolor.frag";
//shaders nuevos se crearían acá

float angulo = 0.0f;

//color café en RGB : 0.478, 0.255, 0.067


void CrearLetrasyFiguras()
{
	GLfloat vertices_letras[] = {

		//E

		//X			Y		Z			R		G		B
		-0.9f,	0.8f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.9f,	0.75f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.7f,	0.8f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.9f,	0.75f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.7f,	0.8f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.7f,	0.75f,	0.0f,			1.0f,	0.0f,	1.0f,

		-0.9f,	0.7f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.9f,	0.65f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.7f,	0.7f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.9f,	0.65f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.7f,	0.7f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.7f,	0.65f,	0.0f,			1.0f,	0.0f,	1.0f,

		-0.9f,	0.6f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.9f,	0.55f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.7f,	0.6f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.9f,	0.55f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.7f,	0.6f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.7f,	0.55f,	0.0f,			1.0f,	0.0f,	1.0f,

		-0.9f,	0.8f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.9f,	0.55f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.85f,	0.55f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.9f,	0.8f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.85f,	0.55f,	0.0f,			1.0f,	0.0f,	1.0f,
		-0.85f,	0.8f,	0.0f,			1.0f,	0.0f,	1.0f,

		//P
		//X			Y		Z			R		G		B
		-0.6f,	0.8f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.6f,	0.75f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.4f,	0.8f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.6f,	0.75f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.4f,	0.8f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.4f,	0.75f,	0.0f,			0.0f,	1.0f,	1.0f,

		-0.6f,	 0.7f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.6f,	0.65f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.4f,	0.7f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.6f,	0.65f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.4f,	0.7f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.4f,	0.65f,	0.0f,			0.0f,	1.0f,	1.0f,

		-0.4f,	0.8f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.45f,	0.8f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.4f,	0.65f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.4f,	0.65f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.45f,	0.65f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.45f,	0.8f,	0.0f,			0.0f,	1.0f,	1.0f,
		
		-0.6f,	0.8f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.6f,	0.55f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.55f,	0.55f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.6f,	0.8f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.55f,	0.55f,	0.0f,			0.0f,	1.0f,	1.0f,
		-0.55f,	0.8f,	0.0f,			0.0f,	1.0f,	1.0f,
	
		//B

		//X		 Y		Z				R		G		B
		-0.3f,	0.8f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.3f,	0.75f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.15f,	0.8f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.3f,	0.75f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.15f,	0.8f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.15f,	0.75f,	0.0f,			1.0f,	1.0f,	0.0f,

		-0.15f,	0.8f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.2f,	0.8f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.15f,	0.7f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.15f,	0.7f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.2f,	0.7f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.2f,	0.8f,	0.0f,			1.0f,	1.0f,	0.0f,

		-0.3f,	0.7f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.3f,	0.65f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.1f,	0.7f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.3f,	0.65f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.1f,	0.7f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.1f,	0.65f,	0.0f,			1.0f,	1.0f,	0.0f,

		-0.1f,	0.7f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.15f,	0.7f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.1f,	0.6f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.1f,	0.6f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.15f,	0.6f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.15f,	0.7f,	0.0f,			1.0f,	1.0f,	0.0f,

		-0.3f,	0.6f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.3f,	0.55f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.1f,	0.6f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.3f,	0.55f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.1f,	0.6f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.1f,	0.55f,	0.0f,			1.0f,	1.0f,	0.0f,

		-0.3f,	0.8f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.3f,	0.55f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.25f,	0.55f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.3f,	0.8f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.25f, 0.55f,	0.0f,			1.0f,	1.0f,	0.0f,
		-0.25f, 0.8f,	0.0f,			1.0f,	1.0f,	0.0f
	};
	MeshColor* letras = new MeshColor();
	letras->CreateMeshColor(vertices_letras, 504);
	meshColorList.push_back(letras);

	

}


void CreateShaders()
{
	Shader* shader1 = new Shader();//shader para usar color como parte del VAO: letras 
	shader1->CreateFromFiles(vShaderColor, fShaderColor);
	shaderList.push_back(*shader1);
}


int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();
	CrearLetrasyFiguras(); //usa MeshColor, índices en MeshColorList
	CreateShaders();
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;
	//Projection: Matriz de Dimensión 4x4 para indicar si vemos en 2D( orthogonal) o en 3D) perspectiva
	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);//Ortogonal, figura 2d
	//glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f); //Ángulo de visión (FOV)

	//Model: Matriz de Dimensión 4x4 en la cual se almacena la multiplicación de las transformaciones geométricas.
	glm::mat4 model(1.0); //fuera del while se usa para inicializar la matriz con una identidad

	//Loop mientras no se cierra la ventana
	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad, limpia ambos buffers


		//LETRAS
		//Para las letras hay que usar el segundo set de shaders con índice 1 en ShaderList 
		shaderList[0].useShader();
		uniformModel = shaderList[0].getModelLocation();
		uniformProjection = shaderList[0].getProjectLocation();
		//Inicializar matriz de dimensión 4x4 que servirá como matriz de modelo para almacenar las transformaciones geométricas
		model = glm::mat4(1.0);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -8.0f));//Traslación hacia dentro de la pantalla
		model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA y se envían al shader como variables de tipo uniform
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[0]->RenderMeshColor();

		

		glUseProgram(0);
		mainWindow.swapBuffers();

	}
	return 0;
}
// inicializar matriz: glm::mat4 model(1.0);
// reestablecer matriz: model = glm::mat4(1.0);
//Traslación
//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -5.0f));
//////////////// ROTACIÓN //////////////////
//model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 1.0f, 0.0f));
////////////////  ESCALA ////////////////
//model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
///////////////////// T+R////////////////
/*model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::rotate(model, glm::radians(angulo), glm::vec3(0.0f, 1.0f, 0.0f));
*/
/////////////R+T//////////
/*model = glm::rotate(model, 45 * toRadians, glm::vec3(0.0f, 0.0f, 1.0f));
model = glm::translate(model, glm::vec3(valor, 0.0f, 0.0f));
*/

//Primero trasladar, luego rotar y al final escalar


//Ejercicio de clase: 
//	Generar las figuras que se piden en el classroom
//Mostrarlos en la casita


//Se va a tener que crear un shader nuevo por cada color pedido en el reporte
//Casita en proyección perspectiva


//Los ejecutables estánm en la carpeta debugg de la solucicón, no la del proyecto