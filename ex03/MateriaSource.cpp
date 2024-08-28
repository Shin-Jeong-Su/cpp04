#include "MateriaSource.hpp"
#include <iostream>
#include "AMateria.hpp"

MateriaSource::MateriaSource(){
	_setSources();
}

MateriaSource::MateriaSource(const MateriaSource& rhs){
	_setSources();
	_copySources(rhs);
}

MateriaSource::~MateriaSource(){
	_deleteSources();
}

void		MateriaSource::learnMateria(AMateria* m){
	for(int i=0; i<4; i++){
		if (_sources[i] == nullptr){
			_sources[i] = m;
			return ;
		}
	}
	std::cout<<"MaterialSource is full. Can't put "<<m->getType()<<" to MaterialSources\n";
	delete m;
}

AMateria*	MateriaSource::createMateria(const std::string& type){
	AMateria*	ret;
	for(int i=0; i<4; i++){
		if (_sources[i] != nullptr && _sources[i]->getType() == type){
			ret = _sources[i];
			_sources[i] = nullptr;
			return (ret);
		}
	}
	return (nullptr);
}

void	MateriaSource::_setSources(){
	for(int i=0;i<4;i++){
		_sources[i]=nullptr;
	}
}

void		MateriaSource::_copySources(const MateriaSource& rhs){
	if (&rhs==this){
		return ;
	}
	for(int i=0;i<4;i++){
		if(rhs._sources[i]){
			_sources[i] = rhs._sources[i]->clone();
		}
	}
}

void		MateriaSource::_deleteSources(){
	for(int i=0; i<4; i++){
		if(_sources[i]){
			delete _sources[i];
			_sources[i] = nullptr;
		}
	}
}

MateriaSource&		MateriaSource::operator=(const MateriaSource& rhs){
	if (&rhs==this){
		return (*this);
	}
	_deleteSources();
	_copySources(rhs);
	return (*this);
}