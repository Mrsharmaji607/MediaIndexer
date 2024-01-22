#include "MediaDatabse.h"
#include <iostream>

void MediaDatabase::addSong(const Song& song) {
    songs.push_back(song);
}

void MediaDatabase::displayAllSongs() const {
    for (const auto& song : songs) {
        std::cout << "Name: " << song.name << "\n"
                  << "Format: " << song.format << "\n"
                  << "Path: " << song.path << "\n"
                  << "Size: " << song.size << " bytes\n\n";
    }
 
}

