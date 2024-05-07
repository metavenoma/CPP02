/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/
/*  _____ _                                                                    */
/*  \_   ( ) __ ___   /\   /\___ _ __ _   _  /\   /\___ _ __ ___  _ __   __ _  */
/*   / /\// '_ ` _ \  \ \ / / _ \ '__| | | | \ \ / / _ \ '__/ _ \| '_ \ / _` | */
/*/\/ /_  | | | | | |  \ V /  __/ |  | |_| |  \ V /  __/ | | (_) | | | | (_| / */
/*\____/  |_| |_| |_|   \_/ \___|_|   \__, |   \_/ \___|_|  \___/|_| |_|\__,_\ */
/*                                    |___/                                    */
/*                                                                             */
/*                                                        ██╗  ██╗██████╗      */
/*          Fixed.hpp                                     ██║  ██║╚════██╗     */
/*   Created by rverona-                                  ███████║ █████╔╝     */
/*   Date: 2024-05-06                                     ╚════██║██╔═══╝      */
/*                                                             ██║███████╗     */
/*                                                             ╚═╝╚══════╝     */
/*☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆*/

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixed_value;
		static const int fract_bits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &fixed);

		~Fixed();
		
		Fixed	&operator= (const Fixed &fixed);
		Fixed	operator+(const Fixed &fix) const;
		Fixed	operator-(const Fixed &fix) const;
		Fixed	operator*(const Fixed &fix) const;
		Fixed	operator/(const Fixed &fix) const;
		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(int n);
		Fixed	operator--(int n);
		
		bool	operator<(const Fixed &fix) const;
		bool	operator>(const Fixed &fix) const;
		bool	operator<=(const Fixed &fix) const;
		bool	operator>=(const Fixed &fix) const;
		bool	operator==(const Fixed &fix) const;
		bool	operator!=(const Fixed &fix) const;

		static Fixed		&min(Fixed &first, Fixed &second);
		static const Fixed	&min(const Fixed &first, const Fixed &second);
		static Fixed		&max(Fixed &first, Fixed &second);
		static const Fixed	&max(const Fixed &first, const Fixed &second);

		int 		getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int		toInt(void) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
