/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Fixed.cpp                                     ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#include "Fixed.hpp"

Fixed::Fixed() : fixed_value(0) {}

Fixed::Fixed(const int value)
{
	this->fixed_value = value << this->fract_bits;
}

Fixed::Fixed(const float value)
{
	this->fixed_value = roundf(value * (1 << this->fract_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed() {}

Fixed	&Fixed::operator = (const Fixed &fixed)
{
	this->fixed_value = fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator + (const Fixed &fix) const
{
	return (fix.toFloat() + this->toFloat());
}

Fixed	Fixed::operator - (const Fixed &fix) const
{
	return (fix.toFloat() - this->toFloat());
}

Fixed	Fixed::operator * (const Fixed &fix) const
{
	return (fix.toFloat() * this->toFloat());
}

Fixed	Fixed::operator / (const Fixed &fix) const
{
	return (fix.toFloat() / this->toFloat());
}

Fixed	Fixed::operator ++ (void)
{
	this->fixed_value += 1;
	return (*this);
}

Fixed	Fixed::operator -- (void)
{
	this->fixed_value -= 1;
	return (*this);
}

Fixed	Fixed::operator ++ (int n)
{
	(void)n;
	Fixed	aux = *this;
	this->fixed_value += 1;
	return (aux);
}

Fixed	Fixed::operator -- (int n)
{
	(void)n;
	Fixed	aux = *this;
	this->fixed_value += 1;
	return (aux);
}

bool	Fixed::operator < (const Fixed &fix) const
{
	return (this->fixed_value < fix.getRawBits());
}

bool	Fixed::operator > (const Fixed &fix) const
{
	return (this->fixed_value > fix.getRawBits());
}

bool	Fixed::operator <= (const Fixed &fix) const
{
	return (this->fixed_value <= fix.getRawBits());
}

bool	Fixed::operator >= (const Fixed &fix) const
{
	return (this->fixed_value >= fix.getRawBits());
}

bool	Fixed::operator == (const Fixed & fix) const
{
	return (this->fixed_value == fix.getRawBits());
}

bool	Fixed::operator != (const Fixed &fix) const
{
	return (this->fixed_value != fix.getRawBits());
}

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first < second)
		return (first);
	return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first < second)
		return (first);
	return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first > second)
		return (first);
	return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first > second)
		return (first);
	return (second);
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_value);
}

void	Fixed::setRawBits(int const raw)
{
	fixed_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (roundf((float)this->fixed_value) / (1 << this->fract_bits));
}

int		Fixed::toInt(void) const
{
	return (this->fixed_value >> this->fract_bits);
}

std::ostream& operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
