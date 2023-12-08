#include "SceneManager.h"

std::shared_ptr<SceneManager> SceneManager::instance = nullptr;

void SceneManager::LoadScene() { // Loads current scene
    if (!isSceneLoaded) {
        UIManager::GetInstance()->UpdateLists();
        scene->LoadScene();
        isSceneLoaded = 1;
        std::cout << "Loaded";
    }

}

void SceneManager::UpdateScene() { // Updates current scene
    scene->ClearSceneBackground();
    UIManager::GetInstance()->UpdateAll();
    UIManager::GetInstance()->DrawAll();

}

void SceneManager::ChangeScene(std::string scene) { // Changes to new scene
    isSceneLoaded = 0;
    this->scene = nullptr;
    this->sceneString = scene;
}

void SceneManager::SetScene(std::shared_ptr<Scene> newScene) {
    this->scene = newScene;
}

std::shared_ptr<Scene> SceneManager::GetScene() {
    return this->scene;
}

std::string SceneManager::GetSceneString() {
    return this->sceneString;
}

void SceneManager::ReloadText() {
    UIManager::GetInstance()->GetTextList().clear();
    scene->LoadText();
    std::cout << "Reloaded";
}