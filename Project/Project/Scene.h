#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "UIManager.h"

class Scene { // Abstract class
public:
	virtual void LoadScene() = 0;

	virtual void LoadText() = 0;

	void ClearSceneBackground() {
		ClearBackground(backgroundColor);
	}

protected:
	Color backgroundColor;
};

