#pragma once
template<class T>
class FiniteElement { //Element that wraps around (min, max)
public:
	T _value;
	T _min;
	T _max;

	FiniteElement(T value, T min, T max)
	{
		_min = min;
		_max = max;
		_setValue(value);
	}

	FiniteElement(const FiniteElement<T>& other)
	{
		if (this != &other) {
			_min = other._min;
			_max = other._max;
			_setValue(other._value);
		}
	}

	T _sizeOfField() {
		return (_max - _min);
	}

	T diffTo(FiniteElement<T> end)
	{
		return diffTo(end._value);
	}

	//Used for interping rotators mostly
	T diffTo(T end)
	{
		//75 -> -25 is either -100 or +50 in (-100, 100), so we want +50

		//Field: -50-100, midpoint is 100 - (100 + 50) / 2
		FiniteElement<T> tempElem(end, _min, _max);
		T initialDiff = tempElem._value - _value;
		T size = _sizeOfField();
		if (abs(initialDiff) <= size / 2) //if difference is less than half, we already have the closest diff
			return initialDiff;
		//return -(_max - initialDiff);
		T midPoint = _max - ((_max - _min) / 2);
		if (tempElem._value < midPoint)
		{
			return tempElem._value + size - _value;
		}
		else if (tempElem._value >= midPoint)
		{
			return tempElem._value - size - _value;
		}
		return 0;
	}

	//Freezes RL when value is inf (when it is divided by 0). Should replace the while loops with some maths though
	void _setValue(T value)
	{
		T size = _sizeOfField();
		_value = value;
		while (_value < _min) //Theres probably a nicer implementation for this
		{
			_value += size;
		}
		while (_value > _max)
		{
			_value -= size;
		}
	}

	FiniteElement<T>& operator=(T& other) // move assignment
	{
		_setValue(other);
		return *this;
	}

	FiniteElement<T>& operator=(FiniteElement<T>& other) // move assignment
	{
		_min = other._min;
		_max = other._max;
		_setValue(other._value);

		return *this;
	}

	FiniteElement<T>& operator=(const FiniteElement<T>& other) // move assignment
	{
		_min = other._min;
		_max = other._max;
		_setValue(other._value);
		
		return *this;
	}

	template<typename T2>
	FiniteElement<T>& operator*=(T2 f)
	{
		_setValue(_value * (T)f); //Determine if this cast is OK when im more awake
		return *this;
	}

	template<typename T2>
	FiniteElement<T>& operator+=(T2 f)
	{
		_setValue(_value + (T)f);
		return *this;
	}

	template<typename T2>
	FiniteElement<T>& operator-=(T2 f)
	{
		_setValue(_value - (T)f);
		return *this;
	}

	template<typename T2>
	FiniteElement<T>& operator/=(T2 f)
	{
		_setValue(_value / (T)f);
		return *this;
	}

	template<typename T2>
	FiniteElement<T> operator* (T2 f) 
	{ 
		FiniteElement<T> result = *this;
		result *= f;
		return result;
	}

	template<typename T2>
	FiniteElement<T> operator+ (T2 f)
	{
		FiniteElement<T> result = *this;
		result += f;
		return result;
	}

	template<typename T2>
	FiniteElement<T> operator- (T2 f)
	{
		FiniteElement<T> result = *this;
		result -= f;
		return result;
	}

	template<typename T2>
	FiniteElement<T> operator/ (T2 f)
	{
		FiniteElement<T> result = *this;
		result /= f;
		return result;
	}

	template<typename T2>
	explicit operator T2() { return (T2)_value; }
	template<typename T2>
	explicit operator T2() const { return (T2)_value; }
};

