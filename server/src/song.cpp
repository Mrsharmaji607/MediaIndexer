#include "/home/kpit/Downloads/media_sample_skeleton/sample_code/server/api/song.h"

Song::Song(const std::string& name, const std::string& format, const std::string& path, double size)
    : name(name), format(format), path(path), size(size) {}

std::string Song::getName() const {
    return name;
}

std::string Song::getFormat() const {
    return format;
}

std::string Song::getPath() const {
    return path;
}

double Song::getSize() const {
    return size;
}
