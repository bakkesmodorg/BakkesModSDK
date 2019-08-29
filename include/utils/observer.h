#pragma once
template<typename T>
class assignment_hook {
public:
	typedef void (hook_t)(const T& old_value, const T& new_value);

	assignment_hook(T& value, hook_t hook) : ref_(value), hook_(hook) {}

	T& operator=(const T& rhs)
	{
		hook_(ref_, rhs);
		ref_ = rhs;
	}
private:
	// I'd rather not want to think about copying this
	assignment_hook(const assignment_hook&);
	void operator=(const assignment_hook&);

	T& ref_;
	hook_t hook_;
};