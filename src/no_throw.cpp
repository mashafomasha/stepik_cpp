#include <iostream>
#include <utility>
#include <cstddef>
#include <type_traits>

/**
 * Специфицируйте noexcept для шаблонной функции do_math, если известно, что в её реализации значения типа T копируются,
 * присваиваются и складываются при помощи оператора +.
 */

// внутри do_math объекты типа T
// - копируются
// - присваиваются
// - перемещаются
// - складываются оператором +
template<class T>
void do_math()
noexcept(
	std::is_nothrow_copy_constructible<T>::value &&
	std::is_nothrow_copy_assignable<T>::value &&
	std::is_nothrow_move_constructible<T>::value &&
	std::is_nothrow_move_assignable<T>::value &&
	noexcept(std::declval<T>() + std::declval<T>())
)
{
    // тело функции нужно оставить пустым
}
