#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int	num;
		static const int _fractionalBits = 8; // ?

	public:
		Fixed();
		Fixed(const Fixed& other);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);

		Fixed& operator=(const Fixed& other);
};

#endif