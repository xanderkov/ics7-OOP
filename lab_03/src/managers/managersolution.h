#pragma once

#include "basemanager.h"
#include "configmanager.h"
#include "drawmanager.h"
#include "loadmanager.h"
#include "scenemanager.h"


class ManagerSolution : public BaseManager
{
public:
    ManagerSolution() = delete;
	~ManagerSolution() = delete;
	ManagerSolution(ManagerSolution &) = delete;

	static std::shared_ptr<LoadManager> get_load_manager();
	static std::shared_ptr<SceneManager> get_scene_manager();
	static std::shared_ptr<ConfigManager> get_config_manager();
	static std::shared_ptr<DrawManager> get_draw_manager();
};
