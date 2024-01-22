#ifndef MEDIADATABSE_H
#define MEDIADATABSE_H

#include "Songs.h"
#include "Songs.h"
#include <vector>

class MediaDatabase {
private:
    std::vector<Song> songs;

public:
    void addSong(const Song& song);
    void displayAllSongs() const;


    std::vector<Song> getSongs() const { return songs; }
};
#endif // MEDIADATABASE_H

