#pragma once
//========================================================================================
// Ejercicio 9: Pixels, unos píxeles que no se mezclan con nada
//
// TIENES QUE COMPLETAR ALGO: el tipo mine::Pixels (su dato, n_, ya está), en
// ❂❂ Your code ❂❂.
//
// 1. Pasa aquí tu código del papel, tal cual.
// 2. Ejecuta `make ej09`: las pruebas P1 y P2.
// 3. Si algo falla, corrígelo y explica cada cambio con su comentario:
//    `// FIX <tipo><nº>: <motivo>` (N, E, S o F, como dice la rúbrica).
//    Hasta que escribas todo lo que pide el enunciado, las pruebas no compilan: el
//    compilador dice qué falta.
//
// Es un tipo de cabecera (todo constexpr): va en el espacio de nombres `mine` y el
// juego no lo usa.
//========================================================================================
#include <compare>

namespace mine {

// A distance in pixels. Not a float: a float is not Pixels by accident, and Pixels are
// only added to Pixels
struct Pixels {
   // ❂❂ Your code ❂❂
   // constexpr Pixels{} = default;
   constexpr Pixels() = default; // Fix 1 había puesto Pixels {} = default, es con ()
   
   // explicit constexpr Pixels(float x) float : n_ { x };
   explicit constexpr Pixels(float x) : n_ { x } {} // Fix 2 el ; del final y haber puesto float antes del : n_ y faltaba el {} de la función del constructor
   
   // [[nodiscard]] constexpr float value() { n_; }
   [[nodiscard]] constexpr float value() const { return n_; } // Fix 3 faltaba el return y el const
   
   [[nodiscard]] constexpr Pixels operator+(Pixels otro) {
      return static_cast<Pixels> (n_ + otro.n_);
   }
   
   [[nodiscard]] constexpr Pixels operator- (Pixels otro) {
      return static_cast<Pixels>(n_ - otro.n_);
   }

   [[nodiscard]] constexpr Pixels operator*(float x) {
      return static_cast<Pixels>(n_*x);
   }

   // [[nodiscard]] constexpr auto operator<=>(const Pixels &) = default; 
   [[nodiscard]] constexpr auto operator<=>(const Pixels &) const = default; // Fix 4 faltaba el const de antes del =

private:
   float n_{};
};

} // namespace mine

// Fix general: las funciones no deberían acabar con ;
// Fix 1: había puesto float : n_ antes del { x }, es s