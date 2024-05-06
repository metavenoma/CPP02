/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          bsp.cpp                                       ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Point.hpp"
#include "bsp.h"

bool	bsp(const Point &a, const Point &b, const Point &c, const Point &point)
{
	Fixed	areaPAB = ((b.getX() - point.getX()) * (a.getY() - point.getY()))
		- ((a.getX() - point.getX()) * (b.getY() - point.getY()));
	Fixed	areaPBC = ((c.getX() - point.getX()) * (b.getY() - point.getY()))
		- ((b.getX() - point.getX()) * (c.getY() - point.getY()));
	Fixed	areaPCA = ((a.getX() - point.getX()) * (c.getY() - point.getY()))
		- ((c.getX() - point.getX()) * (a.getY() - point.getY()));

	bool negative = (areaPAB < 0) || (areaPBC < 0) || (areaPCA < 0);
	bool positive = (areaPAB > 0) || (areaPBC > 0) || (areaPCA > 0);

	return (!(negative && positive));
}
