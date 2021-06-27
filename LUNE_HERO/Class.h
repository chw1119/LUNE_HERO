#ifndef _CLASS
#define _CLASS

#include <string>
#include <iostream>

class Class
{
private:
	int _id;

public:

	Class();
	~Class();


	virtual int GetClassId() const;

	virtual std::string ToString();
};


#endif