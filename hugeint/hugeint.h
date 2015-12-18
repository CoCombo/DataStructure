#ifndef _HUGEINT_H_
#define _HUGEINT_H_

#include <iostream>
#include <string>

class INT
{
    public:
	INT(string _hugeInt) : sign(true), count(0)
	{
	    if( _hugeInt[0] == '-')
		sign = false;
	    for(auto bit = _hugeInt.rbegin(); bit != _hugeInt.rend() && (*bit) != '-'; bit++)
		hugeInt.push_back(*bit),
		count++;
	}
       ~INT();

       friend INT & operator +(const INT &);
       friend INT & operator -(const INT &);
       friend INT & operator *(const INT &);
       friend ITN & operator /(const INT &);

       friend INT & operator ++();
       friend INT & operator --();

       friend bool & operator > (const INT &, const INT &);
       friend bool & operator < (const INT &, const INT &);
       friend bool & operator ==(const INT &, const INT &);
       friend bool & operator <=(const INT &, const INT &);
       friend bool & operator >=(const INT &, const INT &);
       friend bool & operator !=(const INT &, const INT &);

       friend std::istream & operator >>(std::istream &input, INT &);
       friend std::ostream & operator <<(std::ostream &output, const INT &);
    private:
	vector<char> hugeInt;
	bool sign;
	int  count;
};

INT & operator +(const INT &second)
{
    auto bit1 = hugeInt.begin();
    auto bit2 = second.hugeInt.begin();
    int  carry = 0;

    while(bit1 != hugeInt.end() && bit2 != second.hugeInt.end())
    {
	char sum;
	sum = *bit1 + *bit2 - 96 + carry;
	*bit1 = sum % 10;
	carry = sum / 10;
    }
}
#endif
