#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>

//Variables that will be used on render loop
typedef struct{
    unsigned int VAO;
    unsigned int shaderProgramID;
    const char* vertexShaderSource;
}RENDER;

void framebufferCallback(GLFWwindow* window, int width, int height){
    
    glViewport(0, 0, width, height);
}

int initializing(GLFWwindow** window){
    
    /*------------------------------------*/
    glfwInit(); //Initializing the GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //setting the version of OPENGL
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); //setting the version of OPENGL
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //setting the version of OPENGL
    /*------------------------------------*/

    /*-----Creating a window--------------*/
    (*window) = glfwCreateWindow(800, 600, "CG ICMC", NULL, NULL);

    if(window == NULL)
    {
        printf("Wasn't possible create a window GLFW");
        glfwTerminate(); //finish the application
        return 0; //error mensage
    }
    /*------------------------------------*/

    /*-----Loading the GLAD---------------*/
    glfwMakeContextCurrent(*window);
    
    if(!(gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)))
    {
        printf("Error loading GLAD");
        glfwTerminate(); //finish the application
        return 0; //error mensage
    }
    /*------------------------------------*/

    //function to resize the window
    glfwSetFramebufferSizeCallback(*window, framebufferCallback);
    
    return 1;
}

void processKeyEvent(GLFWwindow* window){
    
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void changeColor(GLFWwindow* window){

    if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
    {    
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    else if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {    
        glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    else if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
    {
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    
}

unsigned int loadVertexShader(RENDER* vars){
    
    /*-----Loading the GLSL---------------*/
    vars->vertexShaderSource = "#version 330 core\n"
                               "layout(location = 0) in vec3 aPos;\n"
                               "uniform mat4 transform;\n"
                               "void main(){\n"
                               "gl_Position = transform * vec4(aPos, 1.0f);\n"
                               "}\0";
    //The vertexShader load some characteristics like the object position
    //or your transformations
    /*------------------------------------*/

    /*-----Compiling the shader-----------*/
    unsigned int vertexShaderID;
    vertexShaderID = glCreateShader(GL_VERTEX_SHADER); //Setting the type
    glShaderSource(vertexShaderID, 1, &(vars->vertexShaderSource), NULL); //Source of the GLSL
    glCompileShader(vertexShaderID);
    /*------------------------------------*/

    /*---Checking if there was no error---*/
    int sucess;
    glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &sucess);
    if(!sucess)
    {
        char infoLog[512];
        glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
        fprintf(stderr, "Vertex shader error: %s", infoLog);
    }
    /*------------------------------------*/

    return vertexShaderID;
}

unsigned int loadFragmentShader() {

    /*-----Loading the GLSL---------------*/
    const char *shaderSource = "#version 330 core\n"
                               "out vec4 FragColor;\n"
                               "void main()\n"
                               "{\n"
                               "   FragColor = vec4(0.6f, 0.8f, 0.8f, 1.0f);\n"
                               "}\n\0";
    //The fragmentShader load some characteristics like the color of
    //an object
    /*------------------------------------*/

    /*-----Compiling the shader-----------*/
    unsigned int fragmentShaderID;
    fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER); //Setting the type
    glShaderSource(fragmentShaderID, 1, &shaderSource, NULL); //Source of the GLSL
    glCompileShader(fragmentShaderID);
    /*------------------------------------*/

    /*---Checking if there was no error---*/
    int success;
    glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
        printf("Shader source: %s", shaderSource);
        fprintf(stderr, "Fragment shader error: %s", infoLog);
    }
    /*------------------------------------*/

    return fragmentShaderID;
}

void loadShaders(RENDER* vars){

    unsigned int vertexShaderID = loadVertexShader(vars);
    unsigned int fragmentShaderID = loadFragmentShader();

    /*-----Making the program-------------*/
    vars->shaderProgramID = glCreateProgram();
    glAttachShader(vars->shaderProgramID, fragmentShaderID); //Inserting the Fragment Shader on program
    glAttachShader(vars->shaderProgramID, vertexShaderID); //Inserting the Vertex Shader on program
    glLinkProgram(vars->shaderProgramID); //Connecting the Shaders
    /*------------------------------------*/

    /*---Checking if there was no error---*/
    int sucess;
    glGetProgramiv(vars->shaderProgramID, GL_LINK_STATUS, &sucess);
    if(!sucess)
    {
        char infoLog[512];
        glGetProgramInfoLog(vars->shaderProgramID, 512, NULL, infoLog);
        fprintf(stderr, "Program shader error: %s", infoLog);
    }
    /*------------------------------------*/

    glDeleteShader(vertexShaderID);
    glDeleteShader(fragmentShaderID);
}

void prepare(RENDER* vars){

    /*-Defining the array in Vertex Shader*/
    float vertices[9] = {-0.5f, -0.286f, 0.0f,
                        0.5f, -0.286f, 0.0f,
                        0.0f, 0.5f, 0.0f};
    /*------------------------------------*/

    unsigned int VBO;

    glGenVertexArrays(1, &(vars->VAO)); //Creating the Vertex Array Object
    glGenBuffers(1, &VBO); //Creating the Vertex Buffer Object

    glBindVertexArray(vars->VAO); //Linking the use of Array
    glBindBuffer(GL_ARRAY_BUFFER, VBO); //Linking the use of Buffer
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 9, vertices, GL_STATIC_DRAW); //Allocating the buffer
    
    /*-----Passing the buffer to Shader-----*/
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    /*------------------------------------*/

     /*---Cleaning the buffer and array---*/
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    /*------------------------------------*/
}

void run(GLFWwindow* window, RENDER* vars){

    unsigned int shaderTransform;

    //transformation matrix
    float myMatrix[16]={0.8f, -0.5f, 0.0f, 0.0f,
                        0.5f, 0.8f, 0.0f, 0.0f,
                        0.0f, 0.0f, 1.0f, 0.0f,
                        0.0f, 0.0f, 0.0f, 1.0f};
    
    //render loop
    while(!glfwWindowShouldClose(window))
    {
        /*-----The background color-----------*/
        glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        /*------------------------------------*/
        
        /*-----Event functions---------------*/
        processKeyEvent(window);
        changeColor(window);
        /*------------------------------------*/

        /*-----Apply of the transformation----*/
        shaderTransform = glGetUniformLocation(vars->shaderProgramID, "transform");
        glUniformMatrix4fv(shaderTransform, 1, GL_TRUE, myMatrix);
        /*------------------------------------*/

        /*-----Drawing the triangle-----------*/
        glUseProgram(vars->shaderProgramID); //Using the program described above
        glBindVertexArray(vars->VAO); //Linking the Vetex Array Object in render loop
        glDrawArrays(GL_TRIANGLES, 0, 3); //Finally, drawing the object
        /*------------------------------------*/

        glfwSwapBuffers(window); //Change of buffers for frame
        glfwPollEvents(); //Checking events
    }
}

int main(){

    RENDER vars;
    GLFWwindow* window;
    
    //The object just will be load if the window could be open
    if(initializing(&window)){
        loadShaders(&vars);
        prepare(&vars);
        run(window, &vars);
    }

    glfwTerminate();
}