

#ifndef BUFFERABLE_H
#define BUFFERABLE_H

/*************************************************
*		bufferable_t
*		@brief:	Memory Safe(er) Buffer
**************************************************/
struct bufferable_t
{
	protected:
		char * buffer_;

	public:

		/*************************************************
		*		bufferable_t()
		**************************************************/
		bufferable_t() : buffer_() {};
		/*************************************************/

		/*************************************************
		*		bufferable_t(bufferable_t&& other)
		**************************************************/
		bufferable_t(bufferable_t&& other) : bufferable_t{}
		{
			std::swap(*this, other);
		};
		/*************************************************/

		/*************************************************
		*		bufferable_t& operator=(bufferable_t other)
		**************************************************/
		bufferable_t& operator=(bufferable_t other)
		{
			std::swap(*this, other);
			return *this;
		};
		/*************************************************/

		/*************************************************
		*		bufferable_t& operator=(const char* const newBuffer)
		**************************************************/
		bufferable_t& operator=(const char* const newBuffer)
		{
			char* local = new char[strlen(newBuffer) + 1];
			strcpy(local, newBuffer);
			delete [] newBuffer;
			buffer_ = local;
			return *this;
		};
		/*************************************************/

		/*************************************************
		*		const char* get()
		**************************************************/
		const char* get() const { return this->buffer_; };
		/*************************************************/

};
/*************************************************/


/*************************************************
*		Bufferable
*		@brief:	Inheritible buffer
**************************************************/
class Bufferable {
	public:
		bufferable_t buffer;
};
/*************************************************/

#endif
