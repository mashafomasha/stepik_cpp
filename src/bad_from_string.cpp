#include <iostream>
#include <string>

#include <string>
#include <sstream>
#include <exception>

// описание класса исключения bad_from_string
struct bad_from_string : std::exception {
	bad_from_string() {
		s_ = "";
	};
	bad_from_string(char const * s) {
		s_ = s;
	};

	virtual ~bad_from_string() {};

	virtual const char * what() noexcept {
		return s_;
	};
private:
	char const * s_;
};

// функция from_string
template<class T>
T from_string(std::string const& s)
{
	T v;
	std::istringstream stream(s);

	stream >> std::noskipws >> v;

	if (stream.fail() || stream.peek() != EOF) {
		throw bad_from_string(s.c_str());
	}

	return v;
}
