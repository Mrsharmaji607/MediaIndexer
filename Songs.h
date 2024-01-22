#ifndef SONGS_H
#define SONGS_H

#include <string>

class Song {
public:
    std::string name;
    std::string format;
    std::string path;
    long size;

    Song(const std::string& name, const std::string& format, const std::string& path, long size);
};

#endif // SONGS_H
