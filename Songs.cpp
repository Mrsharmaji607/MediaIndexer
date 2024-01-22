#include "Songs.h"

Song::Song(const std::string& name, const std::string& format, const std::string& path, long size)
    : name(name), format(format), path(path), size(size) {}
