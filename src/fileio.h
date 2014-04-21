//外部文件读取

#ifndef demo_fileio_h
#define demo_fileio_h

class Loader
{
public:
	Loader();
	~Loader();
	void load(const char *fname);
	char* getbuff();
	void clear();
private:
	char* buff;
};

#endif