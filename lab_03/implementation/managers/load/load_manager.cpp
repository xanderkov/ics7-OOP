#include "../../exceptions/load_exceptions.hpp"
#include "../../load/directors/solution/director_solution.hpp"
#include "load_manager.hpp"

std::shared_ptr<Object> LoadManager::load(const std::string &name, size_t director_id) {
    DirectorSolution solution;
    solution.initByConfig();
    this->director = solution.createDirector(director_id);

    return this->director->load(name);
}
