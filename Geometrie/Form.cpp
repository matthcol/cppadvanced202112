#include "Form.h"

Form::Form()
{
}

Form::Form(const string& name):m_name(name)
{
}

Form::~Form()
{
}

const string& Form::name() const
{
	return m_name;
}

void Form::setName(const string& name)
{
	m_name = name;
}
