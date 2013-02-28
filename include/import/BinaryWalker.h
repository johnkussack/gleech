#ifndef BINARYWALKER_H
#define BINARYWALKER_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class BinaryWalker{
    private:

        unsigned long offset;
        string content;

        float _strToFloat(string str){
            float fl;
            unsigned char bytes[] = {0x00,0x00,0x00,0x00};
            bytes[0] = str[0];
            bytes[1] = str[1];
            bytes[2] = str[2];
            bytes[3] = str[3];
            fl = *reinterpret_cast<float*>(bytes);
            return fl;
        }

    public:
        BinaryWalker();
        virtual ~BinaryWalker();

        bool loadData(string _filepath);
        void setData(string _content);

        unsigned long bytesRemaining();

        bool reachedEnd();
        void seek(unsigned long n);
        bool seekToStr(string key);

        unsigned long getOffset();
        unsigned char getChar();
        unsigned short getInt16();
        unsigned int getInt32();
        float getFloat();
        string getBlob(unsigned int len);



};

#endif // BINARYWALKER_H
