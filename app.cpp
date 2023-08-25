#include <filament/FilamentAPI.h>
#include <filament/Engine.h>

using namespace filament;

int main() {
    Engine* engine = Engine::create();
    engine->destroy(engine);

    return 0;
}