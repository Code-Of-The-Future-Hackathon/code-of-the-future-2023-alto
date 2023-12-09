#include "MainMenu.h"
#include "Demo.h"

void LoadNewScene() {
    auto sceneManager = SceneManager::GetInstance();

    if (sceneManager->GetScene() != nullptr) return;

    std::string newScene = sceneManager->GetSceneString();

    if (newScene == "Main Menu")
        sceneManager->SetScene(std::make_shared<MainMenu>()); // Changes current scene to Main Menu
    if (newScene == "Demo")
        sceneManager->SetScene(std::make_shared<Demo>()); // Changes current scene to Game

    sceneManager->LoadScene();
}