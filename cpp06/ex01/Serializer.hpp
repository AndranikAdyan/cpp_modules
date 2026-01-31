#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>

struct	Data{
	int		index;
	int		serialNumber;
	double	coefficient;
};

class	Serializer {
	public:
		static uintptr_t	serialize(Data*);
		static Data*		deserialize(uintptr_t);
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer&);
		Serializer&	operator=(const Serializer&);
};

#endif
