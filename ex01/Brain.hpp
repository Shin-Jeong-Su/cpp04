#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <string>

class Brain{
    public:
        Brain();
        Brain(const Brain& rhs);
        ~Brain();
        Brain& operator=(const Brain& rhs);
    private:
        std::string _ideas[100];
        void    _deppCopyIdeas(const Brain& rhs);
};
#endif