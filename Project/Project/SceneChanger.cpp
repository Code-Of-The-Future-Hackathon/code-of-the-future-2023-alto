#include "MainMenu.h"
#include "Game.h"

void LoadNewScene() {
    auto sceneManager = SceneManager::GetInstance();

    if (sceneManager->GetScene() != nullptr) return;

    std::string newScene = sceneManager->GetSceneString();

    if (newScene == "Main Menu")
        sceneManager->SetScene(std::make_shared<MainMenu>()); // Changes current scene to Main Menu
    if (newScene == "Game")
        sceneManager->SetScene(std::make_shared<Game>()); // Changes current scene to Game

    sceneManager->LoadScene();
}