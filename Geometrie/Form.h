#pragma once

#include <string>

using namespace std;

class Form
{
private:
	string m_name;

protected:
	// constructors : +copy/move
	Form();
	Form(const string& name);

	// destructor
	virtual ~Form();

public:
	const string& name() const;
	void setName(const string& name);

	// abstract method
	virtual void translate(double deltaX, double deltaY)=0;
};

