#include "file_manager.h"
#include <fstream>
#include <iostream>

using namespace std;

file_manager::file_manager(const std::string& file_path) : file_path_(file_path)
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


auto file_manager::destroy() -> bool
{
    try
    {
        // manager->~file_manager();
        last_action = true;
    }
    catch (exception exception)
    {
        last_action = false;
    }
    return last_action;
}

file_manager::~file_manager() noexcept
{
    current_io_fs_->~basic_fstream();
}


/*
auto file_manager::try_append(std::string data) -> bool
{
}
*/

auto file_manager::is_open_io_fs() const -> bool
{
    return current_io_fs_->is_open();
}

/*
auto file_manager::set_file(std::string file_path) -> void
{
    file_path_(file_path);
}
*/




auto file_manager::open() -> bool
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

auto file_manager::close() -> bool
{
    if (current_io_fs_->is_open()) { current_io_fs_->close(); }
    return true;
}