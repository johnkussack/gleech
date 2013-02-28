#include <import/BinaryWalker.h>

BinaryWalker::BinaryWalker(){
    offset = 0;
    content = "";
}

BinaryWalker::~BinaryWalker(){

}

bool BinaryWalker::loadData(string _filepath){

    ifstream ifs(_filepath.c_str());
    string content( (istreambuf_iterator<char>(ifs) ), (istreambuf_iterator<char>() ) );

    if (content.size()!=0){
        setData(content);
        return true;
    }

    return false;
}

void BinaryWalker::setData(string _content){
    content = _content;
    offset = 0;
}

void BinaryWalker::seek(unsigned long n){
    offset+=n;
}

unsigned long BinaryWalker::bytesRemaining(){
    return content.size() - offset;
}

bool BinaryWalker::reachedEnd(){
    return offset >= content.size();
}

unsigned long BinaryWalker::getOffset(){
    return offset;
}

unsigned char BinaryWalker::getChar(){
    unsigned char c = content[offset];
    seek(1);
    return c;
}

float BinaryWalker::getFloat(){
    string fl;
    fl+=content[offset];
    fl+=content[offset+1];
    fl+=content[offset+2];
    fl+=content[offset+3];
    seek(4);
    return _strToFloat(fl);
}

unsigned short BinaryWalker::getInt16(){
    unsigned short s = 0;
    s+=(content[offset]) & 0x00ff;
    s+=content[offset+1]<<8;
    seek(2);

    return s;
}

unsigned int BinaryWalker::getInt32(){
    unsigned int i = 0;
    i+=(content[offset]) & 0x000000ff;
    i+=content[offset+1]<<8;
    i+=content[offset+2]<<16;
    i+=content[offset+3]<<24;

    seek(4);
    return i;
}

bool BinaryWalker::seekToStr(string key){
    unsigned int pos = 0;
    bool keyFound = false;
    unsigned char c;

    while(!keyFound && !reachedEnd()){
        c = getChar();
        if (c==key[pos]){
            pos++;
        }else{
            pos = 0;
        }

        if(pos>=key.length()){
            return true;
        }
    }


    return false;
}

string BinaryWalker::getBlob(unsigned int len){

    string result;

    for(unsigned int i= 0;i<len;i++){
        result+=getChar();
    }

    return result;

}
