//Student.cpp
#include <iostream>

#include "Core.h"
#include "Grad.h"
#include "Student_info.h"

using std::istream;

istream& Student_info::read(istream& is) {
	delete cp;

	char ch;
	is >> ch;

	if (ch == 'U') cp = new Core(is);
	else cp = new Grad(is);

	return is;
}

Student_info::Student_info(const Student_info& s) : cp(0) {
	if (s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& s) {
	if (&s != this) {
		delete cp;
		if (s.cp)
			cp = s.cp->clone();
		else
			cp = 0;
	}
	return *this;
}