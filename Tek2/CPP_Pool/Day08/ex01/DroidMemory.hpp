/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** DroidMemory
*/

#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <string>
#include <iostream>

class DroidMemory {
	public:
		DroidMemory(size_t exp = 0, size_t fingerprint = random());
		DroidMemory(const DroidMemory &ref);
		~DroidMemory();

		void setFingerprint(size_t fingerprint);
		size_t getFingerprint() const;
		void setExp(size_t exp);
		size_t getExp() const;

		DroidMemory operator<<(const DroidMemory &ref);
		DroidMemory operator>>(DroidMemory &ref) const;

		DroidMemory operator+=(const DroidMemory &ref);
		DroidMemory operator+=(const size_t size);

		DroidMemory & operator+(const DroidMemory &ref);
		DroidMemory & operator+(const size_t size);

	private:
		size_t _exp;
		size_t _fingerprint;

};

std::ostream & operator<<(std::ostream&, DroidMemory const &ref);

#endif /* !DROIDMEMORY_HPP_ */
