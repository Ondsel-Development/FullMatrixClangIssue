/***************************************************************************
 *   Copyright (c) 2023 Ondsel, Inc.                                       *
 *                                                                         *
 *   This file is part of OndselSolver.                                    *
 *                                                                         *
 *   See LICENSE file for details about copyright.                         *
 ***************************************************************************/
 
#pragma once

#include <ostream>
#include <vector>
#include <memory>
#include <cmath>
#include <cassert>

namespace MbD {
	using ListD = std::initializer_list<double>;
	using ListListD = std::initializer_list<std::initializer_list<double>>;
	using ListListPairD = std::initializer_list<std::initializer_list<std::initializer_list<double>>>;

	template<typename T>
	class Array : public std::vector<T>
	{
	public:
		Array() {}
		Array(std::vector<T> vec) : std::vector<T>(vec) {}
		Array(int count) : std::vector<T>(count) {}
		Array(int count, const T& value) : std::vector<T>(count, value) {}
		Array(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) : std::vector<T>(begin, end) {}
		Array(std::initializer_list<T> list) : std::vector<T>{ list } {}
		void copyFrom(std::shared_ptr<Array<T>> x);
		double rootMeanSquare();
		void swapElems(int i, int ii);
		double maxMagnitudeOfVector();
		void equalArrayAt(std::shared_ptr<Array<T>> array, int i);
		void atiput(int i, T value);
		void magnifySelf(T factor);
		void negateSelf();
		void atitimes(int i, double factor);

		virtual std::ostream& printOn(std::ostream& s) const {
			std::string str = typeid(*this).name();
			auto classname = str.substr(11, str.size() - 11);
			s << classname << std::endl;
			return s;
		}
		friend std::ostream& operator<<(std::ostream& s, const Array& array)
		{
			return array.printOn(s);
		}

	};
	template<typename T>
	inline void Array<T>::copyFrom(std::shared_ptr<Array<T>> x)
	{
		for (int i = 0; i < x->size(); i++) {
			this->at(i) = x->at(i);
		}
	}
	//template<typename T>
	//inline void Array<T>::zeroSelf()
	//{
	//	for (int i = 0; i < this->size(); i++) {
	//		this->at(i) = (T)0;
	//	}
	//}
	template<typename T>
	inline double Array<T>::rootMeanSquare()
	{
		return std::sqrt(this->sumOfSquares() / this->numberOfElements());
	}
	template<typename T>
	inline void Array<T>::swapElems(int i, int ii)
	{
		auto temp = this->at(i);
		this->at(i) = this->at(ii);
		this->at(ii) = temp;
	}
	//template<>
	//inline double Array<double>::maxMagnitude()
	//{
	//	double max = 0.0;
	//	for (int i = 0; i < this->size(); i++)
	//	{
	//		auto element = this->at(i);
	//		if (element < 0.0) element = -element;
	//		if (max < element) max = element;
	//	}
	//	return max;
	//}
	template<typename T>
	inline double Array<T>::maxMagnitudeOfVector()
	{
		double answer = 0.0;
		for (int i = 0; i < this->size(); i++)
		{
			double mag = std::abs(this->at(i));
			if (answer < mag) answer = mag;
		}
		return answer;
	}
	template<typename T>
	inline void Array<T>::equalArrayAt(std::shared_ptr<Array<T>> array, int i)
	{
		for (int ii = 0; ii < this->size(); ii++)
		{
			this->at(ii) = array->at(i + ii);
		}
	}
	template<typename T>
	inline void Array<T>::atiput(int i, T value)
	{
		this->at(i) = value;
	}
	//template<>
	//inline double Array<double>::length()
	//{
	//	double ssq = 0.0;
	//	for (int i = 0; i < this->size(); i++)
	//	{
	//		double elem = this->at(i);
	//		ssq += elem * elem;
	//	}
	//	return std::sqrt(ssq);
	//}
	template<typename T>
	inline void Array<T>::magnifySelf(T factor)
	{
		for (int i = 0; i < this->size(); i++)
		{
			this->atitimes(i, factor);
		}
	}
	template<typename T>
	inline void Array<T>::negateSelf()
	{
		magnifySelf(-1);
	}
	template<typename T>
	inline void Array<T>::atitimes(int i, double factor)
	{
		this->at(i) *= factor;
	}
}
