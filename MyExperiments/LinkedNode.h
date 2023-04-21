#pragma once

namespace zloo
{
	template<typename T, typename U>
	class LinkedNode
	{
	public:
		LinkedNode(T key = T(), U* value = nullptr);

		auto SetKey(T key) -> void;
		auto GetKey() -> T;
		auto SetValue(U* value) -> void;		
		auto GetValue() -> U*;
		auto SetNext(LinkedNode* p_next) -> void;
		auto GetNext() -> LinkedNode*;
		auto SetPrev(LinkedNode* p_prev) -> void;
		auto GetPrev() -> LinkedNode*;

		auto AddNode(LinkedNode<T, U>* p_current) -> void;
		auto SwapNextNode(LinkedNode<T, U>* p_current) -> LinkedNode<T, U>*&;
		auto static RemoveNode(LinkedNode<T, U>* &current) -> void;
		
	private:		
		T key_;
		U* value_;
		LinkedNode* p_next_;
		LinkedNode* p_prev_;
		auto CheckForNullptr(LinkedNode<T, U>* p_current) -> bool;
	};

	template<typename T, typename U>
	inline LinkedNode<T, U>::LinkedNode(T key, U* value)
	{
		key_ = key;
		value_ = value;
		p_next_ = nullptr;
		p_prev_ = nullptr;
	}	

	template<typename T, typename U>
	inline auto LinkedNode<T, U>::SetKey(T key) -> void
	{
		key_ = key;
	}

	template<typename T, typename U>
	inline auto LinkedNode<T, U>::GetKey() -> T
	{
		return key_;
	}

	template<typename T, typename U>
	inline auto LinkedNode<T, U>::SetValue(U* value) -> void
	{
		value_ = value;
	}

	template<typename T, typename U>
	auto LinkedNode<T, U>::GetValue() -> U*
	{
		return value_;
	}
	
	template<typename T, typename U>
	inline auto LinkedNode<T, U>::SetNext(LinkedNode* p_next) -> void
	{
		p_next_ = p_next;
	}

	template<typename T, typename U>
	inline auto LinkedNode<T, U>::GetNext() -> LinkedNode*
	{
		return p_next_;
	}

	template<typename T, typename U>
	inline auto LinkedNode<T, U>::SetPrev(LinkedNode* p_prev) -> void
	{
		p_prev_ = p_prev;
	}

	template<typename T, typename U>
	inline auto LinkedNode<T, U>::GetPrev() -> LinkedNode*
	{
		return p_prev_;
	}

	

	

	template<typename T, typename U>
	auto LinkedNode<T, U>::AddNode(LinkedNode<T, U>* p_current) -> void
	{
		bool isNull = CheckForNullptr(p_current);
		if (isNull) { return; }
		if (p_next_ != nullptr)
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
	template<typename T, typename U>
	auto LinkedNode<T, U>::SwapNextNode(LinkedNode<T, U>* p_current) -> LinkedNode<T, U>*&
	{
		LinkedNode<T, U>* p_forDelete = nullptr;
		bool isNull = CheckForNullptr(p_current);
		if (isNull) { return p_forDelete; }
		if (p_next_ != nullptr)
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

	template<typename T, typename U>
	auto LinkedNode<T, U>::RemoveNode(LinkedNode<T, U>*& current) -> void
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

	template<typename T, typename U>
	inline auto LinkedNode<T, U>::CheckForNullptr(LinkedNode<T, U>* p_current) -> bool
	{
		return p_current == nullptr ? true : false;
	}
};