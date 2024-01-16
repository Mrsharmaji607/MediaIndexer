
#ifndef SONG_H
#define SONG_H

#include <iostream>

class Song {
private:
    std::string name;
    std::string format;
    std::string path;
    double size;

public:
    Song(const std::string& name, const std::string& format, const std::string& path, double size);

    // Getter methods
    std::string getName() const;
    std::string getFormat() const;
    std::string getPath() const;
    double getSize() const;
};

#endif // SONG_H
