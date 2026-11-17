//========================================================================================
// Ejercicio 7: el árbol del panel, hasta un nivel
//
// TIENES QUE COMPLETAR ALGO: level_rows, en ❂❂ Your code ❂❂.
//
// 1. Pasa aquí tu código del papel, tal cual.
// 2. Ejecuta `make ej07`: las pruebas P1 y P2.
// 3. Si algo falla, corrígelo y explica cada cambio con su comentario:
//    `// FIX <tipo><nº>: <motivo>` (N, E, S o F, como dice la rúbrica).
//
// El juego no la usa: su panel enseña el árbol entero o plegado.
//========================================================================================
#include <ai/dt.hpp>

void level_rows(Node const& n, TreePath const& path, std::size_t level
              , std::string_view branch, bool parent_on_way, std::size_t max_level
              , std::vector<TreeRow>& rows) {
   bool const on_way{ parent_on_way && level < path.size
                      && path.steps[level].node == n.id() };
   // ❂❂ Your code ❂❂
   bool const leaf {!n.yes()};                                 // FIX S(1), en vez de () era {} para inicializar
   bool const folded {!leaf && level == max_level};            // FIX F(1), faltaba crear folded para despues utilizarlo.
   rows.push_back({.node = &n, .branch = branch, .level = level, .on_way = on_way, .folded = folded}); // FIX E(1), faltan llaves y .folded no era correcto.
   if(leaf || folded){ return; }                               // FIX E(2), la condicion no era la correcta
   bool const answer { on_way && path.steps[level].answer };   // FIX F(2), faltaba preguntar si está folded
   level_rows(*n.yes(), path, level+1, "sí", answer, max_level, rows);
   level_rows(*n.no(), path, level+1, "no", on_way && !answer, max_level, rows);
}
