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

   Vec2 displacement { target - guard.phy.pos };

   e.phy = {
      .pos = guard.phy.pos,
      .vel = displacement.normalized() * DART_SPEED
   }; // FIX F 1: la velocidad debe ser el desplazamiento normalizado y no un escalar

   e.ren = {
      .shape = Shape::Stone,
      .color = guard.ren.color
   }; // FIX F 2: el campo shape precede a color y se deben mantener en ese orden

   int DART_TICKS = static_cast<int>(displacement.length() / DART_SPEED); // FIX F 3: se usa la longitud y se truncan los ticks
   e.proj = {
      .ticks = DART_TICKS,
      .noise = DART_NOISE
   };
}
