// Retrieves the metadata from media files and request to store it into media database
/*
class Mediaextractor{
    
    public:
       Mediaextractor();
       ~Mediaextractor();
       // Copy constructor
       // Move constructor
       // Operator overloading
      
      int getValue();
      void setValue(int valuetoset);

      private:
           int mvalue;
};
*/
#ifndef MEDIAEXTRACTOR_H
#define MEDIAEXTRACTOR_H

#include <iostream>
#include <vector>

class MediaExtractor {
public:
    MediaExtractor();
    ~MediaExtractor();

    void extractInformation(const std::vector<std::string>& mediaFiles);
};

#endif // MEDIAEXTRACTOR_H

