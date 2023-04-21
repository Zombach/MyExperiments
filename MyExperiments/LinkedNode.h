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
		auto SwapNextNode(LinkedNode<T>* p_current) -> LinkedNode<T>*&;
		auto static RemoveNode(LinkedNode<T>* &current) -> void;
		auto GetValue() -> T;
	private:
		T value_;
		LinkedNode* p_next_;
		LinkedNode* p_prev_;

		auto CheckForNullptr(LinkedNode<T>* p_current) -> bool;
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
		bool isNull = CheckForNullptr(p_prev);
		if (isNull) { return; }
		p_prev_ = p_prev;
	}

	template <typename T>
	auto LinkedNode<T>::AddNode(LinkedNode<T>* p_current) -> void
	{
		bool isNull = CheckForNullptr(p_current);
		if (isNull) { return; }
		if(p_next_ != nullptr)
		{
			p_current->p_next_ = p_next_;
			p_next_->p_prev_ = p_current;
		}		
		p_next_ = p_current;
		p_current->p_prev_ = this;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="T">source</typeparam>
	/// <param name="p_current"></param>
	/// <returns>p for delete node</returns>
	template <typename T>
	auto LinkedNode<T>::SwapNextNode(LinkedNode<T>* p_current) -> LinkedNode<T>*&
	{
		LinkedNode<T>* p_forDelete = nullptr;
		bool isNull = CheckForNullptr(p_current);
		if (isNull) { return p_forDelete; }
		if(p_next_ != nullptr)
		{
			p_forDelete = p_next_;
			if (p_next_->p_next_ != nullptr && p_next_->p_next_ != p_current)
			{
				p_current->p_next_ = p_next_->p_next_;
				p_next_->p_next_->p_prev_ = p_current;
			}
			p_forDelete->p_next_ = nullptr;
			p_forDelete->p_prev_ = nullptr;
		}
		p_next_ = p_current;
		p_current->p_prev_ = this;
		return p_forDelete;
	}

	template <typename T>
	auto LinkedNode<T>::RemoveNode(LinkedNode<T>* &current) -> void
	{
		if (current == nullptr) { return; }
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

	template<typename T>
	inline auto LinkedNode<T>::CheckForNullptr(LinkedNode<T>* p_current) -> bool
	{
		return p_current == nullptr ? true : false;
	}
};