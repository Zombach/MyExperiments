#pragma once

namespace zloo
{
	template<typename T>
	class LinkedNode
	{
	public:
		LinkedNode(T value);
		LinkedNode(T value, LinkedNode<T>* p_previous);
				
		auto AddNode(LinkedNode<T>* p_current) -> void;
		auto SwapNode(LinkedNode<T>* p_current) -> void;
		auto static RemoveNode(LinkedNode<T>* &current) -> void;
		auto GetValue() -> T;
	private:
		T value_;
		LinkedNode* p_next_;
		LinkedNode* p_prev_;
	};

	template <typename T>
	LinkedNode<T>::LinkedNode(T value)
	{
		value_ = value;
		p_next_ = nullptr;
		p_prev_ = nullptr;
	}

	template <typename T>
	LinkedNode<T>::LinkedNode(T value, LinkedNode<T>* p_prev)
	{
		value_ = value;
		p_next_ = nullptr;
		p_prev_ = p_prev;
	}

	template <typename T>
	auto LinkedNode<T>::AddNode(LinkedNode<T>* p_current) -> void
	{
		if(p_next_ != nullptr)
		{
			p_current->p_next_ = p_next_;
			p_next_->p_prev_ = p_current;
		}		
		p_next_ = p_current;
		p_current->p_prev_ = this;
	}

	template <typename T>
	auto LinkedNode<T>::SwapNode(LinkedNode<T>* p_current) -> void
	{
		if(p_next_ != nullptr)
		{
			LinkedNode<T>* p_tmp = p_next_;			
			if (p_next_->p_next_ != nullptr && p_next_->p_next_ != p_current)
			{
				p_current->p_next_ = p_next_->p_next_;
				p_next_->p_next_->p_prev_ = p_current;
			}
			delete p_tmp;
			p_tmp = nullptr;
		}
		p_next_ = p_current;
		p_current->p_prev_ = this;
	}

	template <typename T>
	auto LinkedNode<T>::RemoveNode(LinkedNode<T>* &current) -> void
	{
		if (current->p_prev_ != nullptr)
		{
			if (current->p_next_ != nullptr)
			{
				current->p_next_->p_prev_ = current->p_prev_;
				current->p_prev_->p_next_ = current->p_next_;
			}
			else
			{
				current->p_prev_->p_next_ = nullptr;
			}
		}
		else if (current->p_next_ != nullptr)
		{
			current->p_next_->p_prev_ = nullptr;
			delete current;
			current = nullptr;
			return;
		}

		current->p_next_ = nullptr;
		current->p_prev_ = nullptr;
		delete current;
		current = nullptr;
	}

	template <typename T>
	auto LinkedNode<T>::GetValue() -> T
	{
		return value_;
	}
};