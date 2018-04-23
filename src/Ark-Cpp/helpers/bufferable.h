

#ifndef BUFFERABLE_H
#define BUFFERABLE_H

/*************************************************
*		bufferable_t
*		@brief:	Memory Safe(er) Buffer
**************************************************/
struct bufferable_t
{
protected:
	char *buffer_;

public:
	bufferable_t();
	bufferable_t(bufferable_t &&other);

	bufferable_t &operator=(bufferable_t other);
	bufferable_t &operator=(const char *const newBuffer);

	const char *get() const;
};
/*************************************************/

/*************************************************
*		Bufferable
*		@brief:	Inheritible buffer
**************************************************/
class Bufferable
{
public:
	bufferable_t buffer;
};
/*************************************************/

#endif
