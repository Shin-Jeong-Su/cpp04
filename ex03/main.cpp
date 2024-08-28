#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

void chl(){
	system("leaks a.out");
}

int main(){
	atexit(chl);

	{
		//subject's test
		// IMateriaSource* src = new MateriaSource();
		// src->learnMateria(new Ice());
		// src->learnMateria(new Cure());
		// ICharacter* me = new Character("me");
		// AMateria* tmp;
		// tmp = src->createMateria("ice");
		// me->equip(tmp);
		// tmp = src->createMateria("cure");
		// me->equip(tmp);
		// ICharacter* bob = new Character("bob");
		// me->use(0, *bob);
		// me->use(1, *bob);
		// delete bob; delete me; delete src;
	}
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Ice());
		src.learnMateria(new Ice());
		src.learnMateria(new Ice());
		//1
		Cure *cure = new Cure;
		src.learnMateria(cure);
		std::cout<<cure->getType();
		//2
		// src.learnMateria(new Cure());
	}
	return 0; 
}