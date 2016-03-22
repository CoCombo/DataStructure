#ifndef _HUGEINT_H_
#define _HUGEINT_H_

#include <iostream>
#include <string>
#include <vector>

class INT
{
    public:
	INT(std::string _hugeInt) : sign(true), count(0)
	{
	    if( _hugeInt[0] == '-')
		sign = false;
	    for(auto bit = _hugeInt.rbegin(); bit != _hugeInt.rend() && (*bit) != '-'; bit++)
		hugeInt.push_back(*bit - 48),   //turn to int
		count++;
	}
       //~INT();
       
       int  getCount() const { return count; }
       void print()    const;

       bool isZero()   const;

       void operator +=(const INT &second);
       void operator -=(const INT &second);
       void operator *=(const INT &second);
       void operator /=(const INT &second);

       void operator ++();
       void operator --();

       bool operator > (const INT &second);
       bool operator < (const INT &second);
       bool operator ==(const INT &second);
       bool operator <=(const INT &second);
       bool operator >=(const INT &second);
       bool operator !=(const INT &second);

       friend std::istream & operator >>(std::istream input,        INT &second);
       friend std::ostream & operator <<(std::ostream output, const INT &second);
    private:
	std::vector<int> hugeInt;
	bool sign;
	int  count;
};

void INT::print() const 
{
    if( !sign )
	std::cout << "-"; //negitive int print '-'0
    for(auto it = hugeInt.crbegin(); it != hugeInt.crend(); it++)
	std::cout << *it;
    std::cout << std::endl;
}

bool INT::isZero() const
{
    if(count == 1 && hugeInt[0] == 0)
	return true;
    return false;
}

void INT::operator +=(const INT &second)
{
    auto bit1  = hugeInt.begin();
    auto bit2  = second.hugeInt.begin();
    int  carry = 0;
    /*two huge nums with same sign +&+/-&-*/
    if( sign == second.sign )
    {
	while(bit1 != hugeInt.end() && bit2 != second.hugeInt.end())
	{
	    int sum;
	    sum = *bit1 + *bit2 + carry;
	    *bit1 = sum % 10;
	    carry = sum / 10;
	    bit1++;
	    bit2++;
	    //print();
	}
	if( getCount() < second.getCount() )
	    while(bit2 != second.hugeInt.end())
	    {
		hugeInt.push_back(*bit2++ + carry);
		carry = 0;
	    }
    /*two huge nums have different sign +&-/-&+*/
    else
    {
	if( sign )
	{
	    auto bit1   = hugeInt.begin();
	    auto bit2   = second.hugeInt.begin();
	    auto borrow = 0;

	    while( bit1 != hugeInt.end() && bit2 != second.hugeInt.end() )
	    {
		*bit -= borrow;
		if( *bit1 < *bit2)
		{
		    borrow = 1;
		    *bit1 = 10 * *bit1 - *bit2;
		    if( bit1 + 1 == hugeInt.end() )
			sign = false;
		}
		else
		    *bit1 -= *bit2;
	    }
	}
	else

    }
}

/*INT & INT::operator -=(const INT &second)
{
    
}*/
/* ++, -- */
/*void INT::operator ++()
{
    INT one("1");
    if(sign)
	hugeInt += one;
    else
	hugeInt -= one;
}

void INT::operator --()
{
    INT one("1");
    if(sign)	
	hugeInt -= one;
    else
	hugeInt += one;
}*/
/* >, <, ==, >=, <= */
/*bool INT::operator ==(const INT &second)
{
    if( (*this -= second).isZero() )
	return true;
    return  false;
}

bool INT::operator >(const INT &second)
{
    if( *this == second )
	return  false;
    return (*this -= second).sign;
}

bool INT::operator <(const INT &second)
{
    if( *this == second )
	return false;
    return !(*this -= second).sign;
}

bool INT::operator >=(const INT &second)
{
    if( *this < second)
	return false;
    return true;
}

bool INT::operator <=(const INT &second)
{
    if( *this > second )
	return false;
    return true;
}*/
#endif
