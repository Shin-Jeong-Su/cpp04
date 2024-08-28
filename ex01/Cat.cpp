#include "Cat.hpp"
#include <iostream>

Cat::Cat()
:Animal("Cat"), _brain(new Brain){
	std::cout<<"Cat()\n";
}

Cat::Cat(const Cat& rhs)
:Animal(rhs._type), _brain(new Brain(*(rhs._brain))){
	std::cout<<"Cat(const Cat& rhs)\n";
}

Cat::~Cat(){
	std::cout<<"~Cat()\n";
	delete _brain;
}

void	Cat::makeSound()const{
	std::cout<<"야옹\n";
}

Cat& Cat::operator=(const Cat& rhs){
	std::cout<<"operator=(const Cat& rhs)\n";
    if (this==&rhs){
        return (*this);
	}
	_type=rhs._type;
	delete rhs._brain;
	_brain=new Brain(*(rhs._brain));
	return (*this);
}