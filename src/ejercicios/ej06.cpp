//========================================================================================
// Ejercicio 6: un dardo de aviso
//
// TIENES QUE COMPLETAR ALGO: SceneGame::new_dart, en ❂❂ Your code ❂❂.
//
// 1. Pasa aquí tu código del papel, tal cual.
// 2. Ejecuta `make ej06`: las pruebas P1 y P2.
// 3. Si algo falla, corrígelo y explica cada cambio con su comentario:
//    `// FIX <tipo><nº>: <motivo>` (N, E, S o F, como dice la rúbrica).
//
// El juego no la usa: ningún guardia lanza dardos.
//========================================================================================
#include <cstdint>
#include <scn/rules.hpp>
#include <scn/scene_game.hpp>

void
SceneGame::new_dart(Entity const& guard, Vec2 target) {
   Entity& e = EM_.new_entity(CMP_RENDER|CMP_PHYSICS|CMP_PROJECTILE);
   e.phy = {.pos=guard.phy.pos, .vel = DART_SPEED};
   e.ren = {.color = guard.ren.color, .shape=Shape::Stone}
   int DART_TICKS = (target - guard.phy.pos)/DART_SPEED;
   e.proj = {.noise = DART_NOISE, .ticks = DART_TICKS};
}
