/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblanc <jleblanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:17:11 by jleblanc          #+#    #+#             */
/*   Updated: 2017/02/07 18:13:39 by jleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_CLASS_HPP
# define INT8_CLASS_HPP

#include "IOperand.class.hpp"

class Int8 : public IOperand
{
private:
	//char v; ca se discute, non? 
	//int _v8; // masqued by 0xFF
	long long int _v8;
public:
	Int8();
	Int8(Int8 const &);
	Int8 &operator=(Int8 const &);
	virtual ~IOperand( void );

	Int8i(char);
	Int8(int);
	Int8(long long int);

	int getPrecision( void ) const; // Precision of the type of the instance
	eOperandType getType( void ) const; // Type of the instance
	IOperand const * operator+( IOperand const & rhs ) const; // Sum
	IOperand const * operator-( IOperand const & rhs ) const; // Difference
	IOperand const * operator*( IOperand const & rhs ) const; // Product
	IOperand const * operator/( IOperand const & rhs ) const; // Quotient
	IOperand const * operator%( IOperand const & rhs ) const; // Modulo
	std::string const & toString( void ) const; // String representation of the instance
}

std::ostream	&operator<<(ostream &, Int8 const &);
