/*
 * Uncopyable.hpp
 *
 *  Created on: Dec 4, 2016
 *      Author: eroc
 */

#ifndef UTILS_UNCOPYABLE_HPP_
#define UTILS_UNCOPYABLE_HPP_

class Uncopyable {
protected:
	Uncopyable(){}
	~Uncopyable(){}

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};



#endif /* UTILS_UNCOPYABLE_HPP_ */
