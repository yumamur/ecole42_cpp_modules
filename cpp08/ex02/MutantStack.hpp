#pragma  once

#include <deque>
#include <stack>

template<class T>
class MutantStack : public std::stack<T, std::deque<T> >
{
    public:
        typedef  typename  std::stack<T>::container_type::iterator iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
};
