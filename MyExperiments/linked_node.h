#pragma once

namespace zloo
{
	template<typename T>
	class linked_node
	{
	public:
		explicit linked_node(T value);
		explicit linked_node(T value, linked_node* p_previous);

		
		auto set_node(linked_node* p_next) -> void;
		auto remove_node() -> void;
		auto get_value() -> T;
	private:
		T value_;
		linked_node* p_next_;
		linked_node* p_prev_;
	};
};