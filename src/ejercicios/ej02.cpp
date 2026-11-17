//========================================================================================
// Ejercicio 2: el compañero más cercano que persigue y se oye
//
// TIENES QUE COMPLETAR ALGO: SceneGame::nearest_chaser, en ❂❂ Your code ❂❂.
//
// 1. Pasa aquí tu código del papel, tal cual. Borra el `return nullptr;`,
//    que solo está para que compile.
// 2. Ejecuta `make ej02`: las pruebas P1 y P2.
// 3. Si algo falla, corrígelo y explica cada cambio con su comentario:
//    `// FIX <tipo><nº>: <motivo>` (N, E, S o F, como dice la rúbrica).
// 4. Juega con tu versión: `make run CON=ej02`.
//========================================================================================
#include <scn/rules.hpp>
#include <scn/scene_game.hpp>

Entity const*
SceneGame::nearest_chaser(Entity const& guard) const {
   Entity const* best{nullptr};
   float best_d2{};
   EM_.for_each([&](Entity const& mate) {// FIX S1: EM está definido como EM_.
      GuardComponent const& m{mate.guard}; 
      if(&m == &guard.guard) {return;}; // FIX E1: Faltaba elegir el componente guard del guard inicial.
      if(m.action!=Action::Chase || m.memory <= 0) {return;};// FIX S2: El diferente (!) va con el = lo puse sin querer al inicio. // FIX E2: Para salir astaba con que una de las dos condiciones se diese y entendí que tenían que cumplirse las dos.
      Vec2 const to{guard.phy.pos - mate.phy.pos}; // FIX E3: Para poder acceder a la posición se usa mate no m.
      float const dist{to.length2()};// FIX S2: Faltaba el 2 en length2().
      if (dist > CALL_DIST* CALL_DIST){return;}
      if(!best || best_d2 > dist) {
         best = &mate; // FIX E4: Se devuelve mate como entidad no como tipo guard.
         best_d2 = dist;
      }
   });  // FIX F1: Me faltó el cierre de EM.
   return best;
}
