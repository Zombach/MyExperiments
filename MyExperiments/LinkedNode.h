#pragma once

namespace zloo
{
	template<typename T>
	class LinkedNode
	{
	public:
		explicit LinkedNode(T value);
		explicit LinkedNode(T value, LinkedNode* p_previous);

		
		auto SetNode(LinkedNode* p_next) -> void;
		auto RemoveNode() -> void;
		auto GetValue() -> T;
	private:
		T value_;
		LinkedNode* p_next_;
		LinkedNode* p_prev_;
	};
};