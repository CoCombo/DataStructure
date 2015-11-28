#include <iostream>

template <typename Object>
class Vector
{
    private:
	int theSize;
	int theCapacity;
	Object *objects;
    public:
	//构造函数，析构函数
	explicit Vector(int initSize = 0) : theSize(initSize),
					    theCapacity(initSize + SPACE_CAPACITY)
                                    	             { objects = new Object [theCapacity]; }
	Vector(const Vector &rhs) : objects(nullptr) { operator = (rhs); }
       ~Vector()                                     { delete [] objects; }

	//
	const Vector &operator = (const Vector &rhs)
	{
	    if (this != &rhs)
	    {
		delete [] objects;
		theSize     = rhs.size();
		theCapacity = rhs.theCapacity;

		objects = new Object [capacity()];
		for (int i = 0; i < size(); i++)
		    objects[i] = rhs.objects[i];
	    }
	    return *this;
	}

	void resize(int newSize)
	{
	    if (newSize > theCapacity)
		reserve(newSize * 2 + 1);
	    theSize = newSize;
	}
	
	void reserve(int newCapacity)
	{
	    if (newCapacity < theSize)
		return;
	    Object *oldArray = objects;

	    objects = new Object [newCapacity];
	    for (int i = 0; i < theSize; i++)
		objects[i] = oldArray[i];

	    theCapacity = newCapacity;
	    delete [] oldArray;
	}

 	      Object & operator [](int index)       { return objects[index]; }
	const Object & operator [](int index) const { return objects[index]; }

	bool empty()    const { return size() == 0; }
	int  size()     const { return theSize; }
	int  capacity() const { return theCapacity;}

	void push_back(const Object &x)
	{
	    if (theSize == theCapacity)
		reserve(theCapacity * 2 + 1);
	    objects[theSize++] = x;
	}
	void           pop_back()       { theSize--; }
	const Object & back()     const { return objects[theSize-1]; }
	//iterator
	typedef       Object * iterator;
	typedef const Object * const_iterator;

	iterator       begin()       { return &objects[0]; }
	const_iterator begin() const { return &objects[0]; }
	iterator       end()         { return &objects[theSize]; }
	const_iterator end()   const { return &objects[theSize]; } 
	enum {SPACE_CAPACITY = 16};
};

int main()
{
    Vector<int> vec;
    std::cout << vec.size() << " " << vec.capacity()<< std::endl;
    vec.push_back(7);
    std::cout << vec.size();
    for (Vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	std::cout << *it;
    std::cout << std::endl;
    return 0;
}
