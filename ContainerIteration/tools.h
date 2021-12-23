#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <iostream>

template<class InputIterator>
void displayIterable(InputIterator first, InputIterator last) {
	/*while (first != last) {
		std::cout << *first << std::endl;
		++first;
	}*/
	if (std::distance(first, last) < 10) 
	{
		while (first != last) 
		{
			std::cout << *first << std::endl;
			++first;
		}
	}
	else 
	{
		displayIterable(first, std::next(first, 5));
		std::cout << "..." << std::endl;
		displayIterable(std::prev(last,5), last);
	}
}

template<class Container>
void displayContainer(const Container& container) {
	displayIterable(container.cbegin(), container.cend());
}

#endif // !_TOOLS_H_

