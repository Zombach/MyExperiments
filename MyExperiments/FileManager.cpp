#include "FileManager.h"
#include <fstream>
#include <iostream>

using namespace std;

FileManager::FileManager(const std::string& file_path) : file_path_(file_path)
{
    try
    {
        current_io_fs_ = new fstream(file_path_);
        map_fs_[file_path_] = current_io_fs_;
    }
    catch (...)
    {

    }
}


auto FileManager::Destroy() -> bool
{
    try
    {
        // manager->~FileManager();
        last_action = true;
    }
    catch (exception exception)
    {
        last_action = false;
    }
    return last_action;
}

FileManager::~FileManager() noexcept
{
    current_io_fs_->~basic_fstream();
}


/*
auto FileManager::try_append(std::string data) -> bool
{
}
*/

auto FileManager::IsOpenIOFs() const -> bool
{
    return current_io_fs_->is_open();
}

/*
auto FileManager::set_file(std::string file_path) -> void
{
    file_path_(file_path);
}
*/




auto FileManager::Open() -> bool
{
    try
    {
        current_io_fs_->open(file_path_);
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }

    return false;
}

auto FileManager::Close() -> bool
{
    if (current_io_fs_->is_open()) { current_io_fs_->close(); }
    return true;
}