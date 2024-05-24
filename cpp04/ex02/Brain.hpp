#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	public:
		std::string ideas[100];
		Brain();
		~Brain();
		Brain(Brain& b);
		Brain& operator=(Brain& b);
		void setIdea(int i, std::string s);
		std::string getIdea(int i);
};

#endif
