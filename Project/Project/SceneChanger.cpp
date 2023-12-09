#include "MainMenu.h"
#include "Calculator.h"

void LoadNewScene() {
    auto sceneManager = SceneManager::GetInstance();

    if (sceneManager->GetScene() != nullptr) return;

    std::string newScene = sceneManager->GetSceneString();

    if (newScene == "Main Menu")
        sceneManager->SetScene(std::make_shared<MainMenu>()); // Changes current scene to Main Menu
    if (newScene == "Calculator")
        sceneManager->SetScene(std::make_shared<Calculator>()); // Changes current scene to Calculator


    sceneManager->LoadScene();
}