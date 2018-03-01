

#ifndef BUFFERABLE_H
#define BUFFERABLE_H

/*************************************************
*
**************************************************/
struct bufferable_t
{
	private:

		char * buffer_;

	public:

		bufferable_t() : buffer_(){};

		bufferable_t(bufferable_t&& other) : bufferable_t{}
		{
			std::swap(*this, other);
		};

		bufferable_t& operator=(bufferable_t other)
		{
			std::swap(*this, other);
			return *this;
		};

		bufferable_t& operator=(const char* newBuffer)
		{
			char* local = new char[strlen(newBuffer) + 1];
			strcpy(local, newBuffer);
			delete [] newBuffer;
			buffer_ = local;
			return *this;
		};

		const char* get() const { return this->buffer_; };

};

/*************************************************
*
**************************************************/
class Bufferable {
	public:
		bufferable_t buffer;
};

#endif
