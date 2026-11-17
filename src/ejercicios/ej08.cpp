//========================================================================================
// Ejercicio 8: de una tabla a un árbol, sin preguntas inútiles
//
// TIENES QUE COMPLETAR ALGO: build_tree, en ❂❂ Your code ❂❂.
//
// 1. Pasa aquí tu código del papel, tal cual.
// 2. Ejecuta `make ej08`: las pruebas P1 y P2.
// 3. Si algo falla, corrígelo y explica cada cambio con su comentario:
//    `// FIX <tipo><nº>: <motivo>` (N, E, S o F, como dice la rúbrica).
// 4. Juega con tu versión: `make run CON=ej08`.
//========================================================================================
#include <ai/dt.hpp>

std::expected<DecisionTree, BuildError>
build_tree(std::span<NodeDesc const> table, std::span<Question const> questions) {
   if (table.empty()) { return fail(BuildProblem::Empty, 0); }
   DecisionTree             t{};
   std::vector<Node const*> built{};          // built[i]: the node of row i
   for (std::size_t i{}; i < table.size(); i += 1) {
      NodeDesc const& row{ table[i] };
      // ❂❂ Your code ❂❂
      if( row.is_leaf ){
         built.push_back({&t.action(row.action)});
         continue;
      }
      if( row.question >= questions.size() ){
         return fail(BuildProblem::NoQuestion, i);
      }
      if( row.yes >= i || row.no >= i ){
         return fail(BuildProblem::ChildNotBuilt, i);
      }
      if( row.yes == row.no ){                                          // FIX E(1), era comparar entre los dos hijos.
         return fail(BuildProblem::SameChildren, i);
      }
      Question const& q (questions[row.question]);                      // FIX S(2), faltó crear question como Ref.
      built.push_back(&t.question(q, *built[row.yes],*built[row.no]));  // FIX E(3), faltaba toda esta linea
   }
   t.set_root(*built.back());
   if (depth(*t.root()) > MAX_DEPTH) {
      return fail(BuildProblem::TooDeep, table.size() - 1);
   }
   return t;
}
