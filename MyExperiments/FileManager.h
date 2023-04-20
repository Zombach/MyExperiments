#pragma once
#include <string>
#include <fstream>
#include <map>

class FileManager
{
public:
	explicit FileManager(const std::string& file_path);
	static auto Destroy() -> bool;
	~FileManager() noexcept;
	inline static bool last_action = false;


	//auto set_file(std::string file_path) -> void;
	//auto try_append(std::string data) -> bool;
private:
	std::string file_path_;
	std::fstream* current_io_fs_;
	std::map<std::string, std::fstream*> map_fs_;


	auto IsOpenIOFs() const -> bool;
	auto Open() -> bool;
	auto Close() -> bool;
};