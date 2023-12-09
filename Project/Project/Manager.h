#pragma once

#include <cstdint>
#include <raylib.h>
#include <memory>
#include "SceneManager.h"
#include "SceneChanger.h"

class Manager // Manager Singleton
{
public:
    ~Manager(); // Destructor

    static std::shared_ptr<Manager> GetInstance()
    {
        if (instance == nullptr)
            instance = std::make_shared<Manager>();

        return instance;
    }

    void Initialize(); 

    void Start();

    void Update();

    bool ShouldWindowClose();

    void Close(); 

private:
    static std::shared_ptr<Manager> instance;

    bool shouldWindowClose = 0;

};