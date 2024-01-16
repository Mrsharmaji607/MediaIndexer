#include<iostream>
using namespace std;

class DatabaseManager{
public:

/**
 * @brief Creating the sqlite database for media 
 * 
 */
void initialise(); 
/**
 * @brief 
 *   Adding entries to the database
 * @param artist 
 * @param song_name 
 * @param size 
 */
  void addSongEntries(string artist, string song_name, int size);
};