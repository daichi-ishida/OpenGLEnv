
#include <cstdio>
#include <string>
#include <GLFW/glfw3.h>

constexpr int WIN_WIDTH   = 500;                 // ウィンドウの幅
constexpr int WIN_HEIGHT  = 500;                 // ウィンドウの高さ
constexpr char WIN_TITLE[] = "OpenGL Course";     // ウィンドウのタイトル

// ユーザ定義のOpenGLの初期化
void initializeGL() 
{
    // 背景色の設定
    glClearColor(0.2f, 0.0f, 0.6f, 1.0f);
}

// ユーザ定義のOpenGL描画
void paintGL() 
{
    // 背景色の描画
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv) 
{
    // OpenGLを初期化する
    if (glfwInit() == GL_FALSE) 
    {
        fprintf(stderr, "Initialization failed!\n");
        return 1;
    }

    // Windowの作成
    GLFWwindow *window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_TITLE,
                                          NULL, NULL);
    if (window == NULL) 
    {
        fprintf(stderr, "Window creation failed!");
        glfwTerminate();
        return 1;
    }

    // OpenGLの描画対象にWindowを追加
    glfwMakeContextCurrent(window);

    // 初期化
    initializeGL();

    // メインループ
    while (glfwWindowShouldClose(window) == GL_FALSE) 
    {
        // 描画
        paintGL();

        // 描画用バッファの切り替え
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
