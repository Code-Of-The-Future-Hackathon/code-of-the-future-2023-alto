#include "Manager.h"

std::shared_ptr<Manager> Manager::instance = nullptr;

Manager::~Manager()
{
    CloseWindow();
}

void Manager::Initialize()
{
    SetConfigFlags(FLAG_VSYNC_HINT);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE);

    Image img = LoadImage("../assets/logo.png");
    SetWindowIcon(img);
    /*ToggleFullscreen();*/
    Start();
}

void Manager::Start()
{
    SceneManager::GetInstance()->ChangeScene("Main Menu");
    
}

void Manager::Update()
{
    BeginDrawing();
    GetFPS();
    LoadNewScene();
    SceneManager::GetInstance()->UpdateScene();

    if (UIManager::GetInstance()->GetShouldFpsShow())
        DrawFPS(2, 0);

    EndDrawing();
}

bool Manager::ShouldWindowClose()
{
    return WindowShouldClose() || shouldWindowClose;
}

void Manager::Close()
{
    shouldWindowClose = true;
}