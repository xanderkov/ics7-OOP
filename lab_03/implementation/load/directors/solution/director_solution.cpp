#include "director_solution.hpp"
#include <fstream>
#include "../../../exceptions/load_exceptions.hpp"
#include "../model/wireframe_model/wireframe_model_director.hpp"
#include "../camera/camera_director.hpp"

#define CONFIG_CAMERA_PATH "../../../../data/configuration/CameraDirector.cfg"
#define CONFIG_MODEL_PATH "../../../../data/configuration/WireframeModelDirector.cfg"

template <typename Tprod>
bool DirectorSolution::registration(size_t id) {
	return callbacks.emplace(id, std::make_shared<Tprod>()).second;
}

void DirectorSolution::initByConfig() {
	{
		std::string src_name = CONFIG_CAMERA_PATH;
		std::shared_ptr<std::ifstream> src_file = std::make_shared<std::ifstream>(src_name);
		//if (!(*(src_file))) throw FileOpenError(__FILE__, __LINE__, "could not open config file!");

		size_t id = 1;
		//if (!(*(src_file) >> id)) throw FileFormatError(__FILE__, __LINE__, "bad format of config file");
		this->registration<CameraDirector>(id);

		src_file->close();
	}
	{
		std::string src_name = CONFIG_MODEL_PATH;
		std::shared_ptr<std::ifstream> src_file = std::make_shared<std::ifstream>(src_name);
		//if (!(*(src_file))) throw FileOpenError(__FILE__, __LINE__, "could not open config file!");

		size_t id = 2;
		//if (!(*(src_file) >> id)) throw FileFormatError(__FILE__, __LINE__, "bad format of config file");
		this->registration<WireframeModelDirector>(id);

		src_file->close();
	}
}


std::shared_ptr<LoadDirector> DirectorSolution::createDirector(size_t id) {
	CallBackMap::const_iterator it = callbacks.find(id);

	if (it == callbacks.end())
	{
	    throw ConfigError(__FILE__, __LINE__, "wrong id");
	}

	return it->second;
}

