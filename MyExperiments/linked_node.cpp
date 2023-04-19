#include "linked_node.h"

#include <string>

namespace zloo
{
	template linked_node<int>;
	template linked_node<std::string>;

	template <typename T>
	linked_node<T>::linked_node(T value)
	{
		value_ = value;
		p_next_ = nullptr;
		p_prev_ = nullptr;
	}

	template <typename T>
	linked_node<T>::linked_node(T value, linked_node* p_prev)
	{
		value_ = value;
		p_next_ = nullptr;
		p_prev_ = p_prev;
	}

	template <typename T>
	auto linked_node<T>::set_node(linked_node* p_next) -> void
	{
		p_next_ = p_next;
		p_next->p_prev_ = this;
	}

	template <typename T>
	auto linked_node<T>::remove_node() -> void
	{
		if(p_prev_ != nullptr)
		{
			if (p_next_ != nullptr)
			{
				p_next_->p_prev_ = p_prev_;
				p_prev_->p_next_ = p_next_;
			}
			else
			{
				p_prev_->p_next_ = nullptr;
			}
		}
		else if (p_next_ != nullptr)
		{
			value_ = p_next_->value_;
			p_next_ = p_next_->p_next_;
			if(p_next_ != nullptr)
			{
				p_next_->p_prev_ = this;
			}
			return;
		}
		
		p_next_ = nullptr;
		p_prev_ = nullptr;
		delete this;
	}

	template <typename T>
	auto linked_node<T>::get_value() -> T
	{
		return value_;
	}		
};