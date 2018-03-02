

#ifndef VALUEPRINTABLE_H
#define VALUEPRINTABLE_H

struct ValuePrintable :
    public Printable
{
  private:
    char value_[];
  public:
    virtual size_t printTo(Print& p) const
		{
			size_t size = 0;
			size += p.print(this->value_);
			return size;
		};
};

#endif