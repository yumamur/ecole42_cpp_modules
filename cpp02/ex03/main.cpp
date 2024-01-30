/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:32:36 by lrocca            #+#    #+#             */
/*   Updated: 2021/11/20 19:47:40 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void) {
	std::cout << std::boolalpha

		<< "a(0, 0), b(0, 5), c(5, 0), point(1, 1): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 1)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 5): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 5)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 3): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 3)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, 0): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, 0)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0.1, 0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0.1f, 0.01f)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(10, 0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(10, 0.01f)) << std::endl

		<< "a(0, 0), b(0, 5), c(5, 0), point(0, -0.01): "
		<< bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(0, -0.01f)) << std::endl;
}
