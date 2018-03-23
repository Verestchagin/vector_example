#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	size_ = 0;
	capacity_ = 0;
	elements_ = nullptr;
}

vector_t::vector_t(vector_t const & other)
{
	size_ = other.size_;
  	capacity_ = other.capacity_;
 	elements_ = new int[capacity_];
 	for (unsigned int i = 0; i < size_; i++)
    	elements_[i] = other.elements_[i];
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if (this != &other){
		if (elements_ != nullptr)
			delete[]elements_;
		size_ = other.size_;
		capacity_ = other.capacity_;
		elements_ = new int[capacity_];
		for (unsigned int i = 0; i < size; i++)
			elements_[i] = other.elements_[i];
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (size_ == other.size_){
		for (unsigned int i = 0; i < other.size_; i++)
			if (elements_[i] != other.elements_[i]){}
				return false;
				break;
			}
		return true;
	}
	else
		return false;
}

vector_t::~vector_t()
{
	if (elements_ != nullptr){
		delete[]elements_;
	}
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	if (!capacity_){
		capacity_ = 1;
		elements_ = new int [capacity_];
		elements_[0] = value;
	}
	else{
		int *elements_new = new int [capacity_];
		for (unsigned int i = 0; i < size_; i++)
			elements_new[i] = elements_[i];
		elements_[size_] = value;
		delete[]elements_new;
		elements_ = elements_new;
		size_++;
		if (capacity_ == size_)
			capacity_ *= 2;
	}
}

void vector_t::pop_back()
{
	if (elements_){
		if (capacity_ / 4 > size_){
			int *elements_new = new int [capacity_ / 2];
			for (unsigned int i = 0; i < size_ - 1; i++)
				elements_new[i] = elements_[i];
			delete[] elements_;
			elements_ = elements_new;
			size_--;
		}
		else{
			int *elements_new = new int [capacity_];
			for (unsigned int i = 0; i < size_ - 1; i++)
				elements_new[i] = elements_[i];
			delete[]elements_;
			elements_ = elements_new;
			size_--;
		}
	}
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	return !(lhs == rhs);
}
