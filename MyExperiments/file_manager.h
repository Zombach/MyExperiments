#pragma once
#include <string>
#include <fstream>
#include <map>

class file_manager
{
public:
	explicit file_manager(const std::string& file_path);
	static auto destroy() -> bool;
	~file_manager() noexcept;
	inline static bool last_action = false;


	//auto set_file(std::string file_path) -> void;
	//auto try_append(std::string data) -> bool;
private:
	std::string file_path_;
	std::fstream* current_io_fs_;
	std::map<std::string, std::fstream*> map_fs_;


	auto is_open_io_fs() const -> bool;
	auto open() -> bool;
	auto close() -> bool;
};