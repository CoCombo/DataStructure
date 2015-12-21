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
       
       int  getCount() const{ return count; }
       void print()    const;

       INT & operator +=(const INT &second);
       INT & operator -=(const INT &second);
       INT & operator *=(const INT &second);
       INT & operator /=(const INT &second);

       void operator ++();
       void operator --();

       bool & operator > (const INT &second);
       bool & operator < (const INT &second);
       bool & operator ==(const INT &second);
       bool & operator <=(const INT &second);
       bool & operator >=(const INT &second);
       bool & operator !=(const INT &second);

       friend std::istream & operator >>(std::istream input,        INT &second);
       friend std::ostream & operator <<(std::ostream output, const INT &second);
    private:
	std::vector<int> hugeInt;
	bool sign;
	int  count;
};

void INT::print() const 
{
    if( !hugeInt.size() )
	std::cout << "-"; //negitive int print '-'0
    for(auto it = hugeInt.crbegin(); it != hugeInt.crend(); it++)
	std::cout << *it << " ";
    std::cout << std::endl;
}

INT & INT::operator +=(const INT &second)
{
    auto bit1 = hugeInt.begin();
    auto bit2 = second.hugeInt.begin();
    int  carry = 0;

    while(bit1 != hugeInt.end() && bit2 != second.hugeInt.end())
    {
	int sum;
	sum = *bit1 + *bit2 + carry;
	*bit1 = sum % 10;
	carry = sum / 10;
	bit1++;
	bit2++;
    }
    if( getCount() <= second.getCount() )
	while(bit2 != second.hugeInt.end())
	    hugeInt.push_back(*bit2);
    else
	return *this;
}

INT & INT::operator -=(const INT &second)
{
    
}
/* ++, -- */
void INT::operator ++()
{
    hugeInt[0]++;
}

void INT::operator --()
{
    hugeInt[0]--;
}
/* >, <, ==, >=, <= */
bool INT::operator >(const INT &second)
{
    if( hugeInt.getCount() > second.hugeInt.getCount() )
	return true;
    if( hugeInt.getCount() < second.hugeInt.getCount() )
	return false;
}
#endif
