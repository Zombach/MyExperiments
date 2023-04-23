#pragma once
#include <map>
#include "LinkedNode.h"
#include "Hash.h"
#include <iostream>

namespace zloo
{
	template<typename T, typename U>
	class Dictionary
	{
	public:
		Dictionary();
		~Dictionary();

		auto operator[](T& key) -> U&;

		auto TryAdd(T key, U *value) -> bool;
		auto TryGetValue(T key, U& value) -> bool;
	private:
		LinkedNode<int, LinkedNode<T, U>> *head_;
		Hash<T> *hash_;
	};
	
	template <typename T, typename U>
	Dictionary<T, U>::Dictionary()
	{
		head_ = new LinkedNode<int, LinkedNode<T, U>>();
		hash_ = new Hash<T>();
	}

	template <typename T, typename U>
	Dictionary<T, U>::~Dictionary()
	{
		delete head_;
		head_ = nullptr;
	}

	template<typename T, typename U>
	auto Dictionary<T, U>::operator[](T& key) -> U&
	{
		U* u = new U();
		bool is_done = TryGetValue(key, *u);
		return *u;
	}

	template <typename T, typename U>
	auto Dictionary<T, U>::TryAdd(T key, U *value) -> bool
	{
		bool is_done = false;
		int hash = hash_->GetHash(key);
		//Если в словаре нет элементов, то создаем главный и добавляем в него ноду.
		if (head_->GetNext() == nullptr && head_->GetValue() == nullptr)
		{
			head_->SetKey(hash);
			auto node = new LinkedNode<T, U>(key, value);
			head_->SetValue(node);
		}
		//Если элементы есть, то обходим все главные ноды и сравниваем хеш
		else
		{
			auto p_current = head_;
			while (true)
			{
				if (p_current->GetKey() != hash)
				{
					//Если есть следующая главная нода, переходим к ней
					if (p_current->GetNext() != nullptr) { p_current = p_current->GetNext(); }
					else
					{
						//Сюда попадаем, если нету главной ноды с таким же значением
						auto new_node = new LinkedNode<int, LinkedNode<T, U>>();
						new_node->SetKey(hash);
						p_current->SetNext(new_node);
						new_node->SetPrev(p_current);

						auto node = new LinkedNode<T, U>(key, value);
						new_node->SetValue(node);
						return true;
					}
				}
				//Если найдена главная нода с таким же хешем
				else
				{
					//Делаем проверку на наличие коллизий(В главной ноде уже присутствует элемент'ы)
					if (p_current->GetValue() != nullptr)
					{
						//Сравниваем ключи в нодах
						LinkedNode<T, U>* p_node = p_current->GetValue();						
						while (true)
						{
							//Если не совпадает ключ, переходим к следующей ноде.
							if (p_node->GetKey() != key)
							{
								//Если есть следующая нода, переходим к ней
								if (p_node->GetNext() != nullptr) { p_node = p_node->GetNext(); }
								//Если ноды закончили, а ключи так и не совпали
								else
								{
									//Добавляем новую ноду
									auto node = new LinkedNode<T, U>(key, value);
									p_node->SetNext(node);
									node->SetPrev(p_node);
									return true;
								}								
							}
							//Если ключи совпали, завершаем метод;
							else { return false; }
						}
					}
					//Создаем ноду и вкладываем её в главную ноду
					else
					{
						auto node = new LinkedNode<T, U>(key, value);
						p_current->SetValue(node);
						return true;
					}
				}
			}			
		}
		return is_done;
	}

	template <typename T, typename U>
	auto Dictionary<T, U>::TryGetValue(T key, U& value) -> bool
	{
		int hash = hash_->GetHash(key);
		auto p_current = head_;
		while (p_current != nullptr)
		{
			if (p_current->GetKey() != hash || p_current->GetValue() == nullptr)
			{
				p_current = p_current->GetNext();
			}
			else
			{
				auto p_node = p_current->GetValue();
				while (p_node != nullptr)
				{
					if (p_node->GetKey() != key)
					{
						p_node = p_node->GetNext();
					}
					else
					{
						value = *p_node->GetValue();
						return true;
					}
				}
				return false;
			}
		}
		return false;
	}
};