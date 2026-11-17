//========================================================================================
// Ejercicio 4: el tick de un guardia, que con la alarma piensa más
//
// TIENES QUE COMPLETAR ALGO: SceneGame::guard_tick, en ❂❂ Your code ❂❂.
//
// 1. Pasa aquí tu código del papel, tal cual.
// 2. Ejecuta `make ej04`: las pruebas P1 y P2.
// 3. Si algo falla, corrígelo y explica cada cambio con su comentario:
//    `// FIX <tipo><nº>: <motivo>` (N, E, S o F, como dice la rúbrica).
// 4. Juega con tu versión: `make run CON=ej04`.
//========================================================================================
#include <algorithm>
#include <scn/scene_game.hpp>

void
SceneGame::guard_tick(Entity& guard) {
   // ❂❂ Your code ❂❂
   GuardComponent& g = guard.guard;
   
   if (g.memory > 0) {
      g.memory -= 1;
   }

   if (g.react_in > 0) {
      g.react_in -= 1;
   
      if (g.react_in == 0) {
         g.action = g.pending;
      }
   }

   g.think_in -= 1;

   if (g.think_in <= 0) {
      if (alarm_ > 0) { g.think_in = std::max(1, g.traits.think_every/2); }
      else            { g.think_in = g.traits.think_every; }

      think(guard);
   }

   act(guard);
}
