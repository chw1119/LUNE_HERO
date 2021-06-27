// LUNE_HERO.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "stdafx.h"



const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Context* ctx;

static float a = 0;

inline void loop() 
{
    bool Running = true;
    bool FullScreen = false;

    while (Running)
    {
        SDL_Event Event;
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_KEYDOWN)
            {
                switch (Event.key.keysym.sym)
                {

                case SDLK_ESCAPE:

                    Running = 0;
                    break;

                case 'f':
                    FullScreen = !FullScreen;
                    if (FullScreen)
                    {
                        SDL_SetWindowFullscreen(ctx->GetWindow(), SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN_DESKTOP);
                    }
                    else
                    {
                        SDL_SetWindowFullscreen(ctx->GetWindow(), SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
                    }
                    break;
                default:
                    break;
                }
            }
            else if (Event.type == SDL_QUIT)
            {
                Running = 0;
            }
        }

        glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        
        glClear(GL_COLOR_BUFFER_BIT);

        auto sprite = new Sprite();

        sprite->Draw();



        SDL_GL_SwapWindow(ctx->GetWindow());

        delete sprite;
        SDL_Delay(1000 / 60);
    }
}


const char* str = "Hello world!\n";
using namespace std;

int main(int argc, char* args[])
{
    Context context;
    Init::Init(context);
    ctx = &context;
    loop();

    return 0;
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
