#include "LinkedNode.h"

#include <string>

namespace zloo
{
	template LinkedNode<int>;
	template LinkedNode<std::string>;

	template <typename T>
	LinkedNode<T>::LinkedNode(T value)
	{
		value_ = value;
		p_next_ = nullptr;
		p_prev_ = nullptr;
	}

	template <typename T>
	LinkedNode<T>::LinkedNode(T value, LinkedNode* p_prev)
	{
		value_ = value;
		p_next_ = nullptr;
		p_prev_ = p_prev;
	}

	template <typename T>
	auto LinkedNode<T>::SetNode(LinkedNode* p_next) -> void
	{
		p_next_ = p_next;
		p_next->p_prev_ = this;
	}

	template <typename T>
	auto LinkedNode<T>::RemoveNode() -> void
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
	auto LinkedNode<T>::GetValue() -> T
	{
		return value_;
	}		
};