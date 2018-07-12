/**********************************************************
* Name: Ana Garcia
* Student ID : 105903173
* Seneca email : agarcia - caicedo@myseneca.ca
* Date of Completion : 09 / 07 / 2018
* *********************************************************/ 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

#include "Contact.h"

using namespace std;

namespace sict{

	Contact::Contact() {
		set('\0', nullptr, 0);
	}

	Contact::Contact(const char* name, const long long* phoneNo, const int no) {
		set(name, phoneNo, no);
	}

	Contact::Contact(const Contact& src) {
		strncpy(m_name, src.m_name, 19);
		m_no = src.m_no;

		if (src.m_phone_no != nullptr) {
			m_phone_no = new long long[m_no];
			for (int i = 0; i < m_no; i++) {
				m_phone_no[i] = src.m_phone_no[i];
			}
		}
		else {
			m_phone_no = nullptr;
		}
	}
	
	Contact& Contact::operator=(const Contact& src) {
		if (this != &src) {
			strncpy(m_name, src.m_name, 19);
			m_no = src.m_no;

			delete[] m_phone_no;
			if (src.m_phone_no != nullptr) {
				m_phone_no = new long long[m_no];
				for (int i = 0; i < m_no; i++) {
					m_phone_no[i] = src.m_phone_no[i];
				}
			}
			else {
			m_phone_no = nullptr;
			}
		}
		return *this;
	}

	
	void Contact::set(const char* name, const long long* phoneNo, const int no) {
		if (name == nullptr || name[0] == '\0' || strcmp(name, "") == 0)
		{
			m_name[0] = '\0';
			m_phone_no = nullptr;
			m_no = 0;
		}
		else if (name != nullptr && phoneNo == nullptr)
		{
			strncpy(m_name, name, 19);
			m_name[19] = '\0';
			m_phone_no = nullptr;
			m_no = 0;
		}
		else {
			strncpy(m_name, name, 19);
			m_no = no;
			m_phone_no = new long long[m_no];
			if (m_no > 0) {
				for (int i = 0; i < m_no; i++) {

					bool x = validNo(phoneNo[i]);
					if (x != true) {
						m_phone_no[i] = '\0';
					}
					else {
						m_phone_no[i] = phoneNo[i];
					}
				}
			}
			else {
				m_phone_no = nullptr;
			}

		}
	}

	bool Contact::validNo(const long long no) {
		bool x;
		long long y;
		long long temp_no = no;

		if (temp_no < 10000000000 || temp_no > 999999999999) {
			x = false;
		}
		else if (temp_no >= 10000000000 && temp_no <= 999999999999) {
			y = temp_no / 1000000000;
			y = y % 10;
			if (y == 0) {
				x = false;
			}
			else {
				y = temp_no / 1000000;
				y = temp_no % 10;
				if (y == 0) {
					x = false;
				}
				else {
					x = true;
				}
			}

		}
		return x; 
	}

	bool Contact::isEmpty() const {
		bool x;
		if ((m_name[0] == '\0' ) && (m_phone_no == nullptr)  && (m_no == 0)) {
			x = true;
		}
		else {
			x = false;
		}
		return x; 
	}

	void Contact::display() const {
		bool x = isEmpty();
		if (x == true) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << m_name << endl;
			for (int i = 0; i < m_no; i++) {

				if (m_phone_no[i] != '\0')
				{
					int countr_code = m_phone_no[i] / 10000000000;
					int area_code = (m_phone_no[i] / 10000000) % 1000;
					int NNN = (m_phone_no[i] / 10000) % 1000;
					int NNNN = m_phone_no[i] % 10000;
					if (NNNN < 1000 && NNNN > 100) {
						cout << "(+" << countr_code << ") " << area_code << " " << NNN << "-0" << NNNN << endl;
					}
					else if (NNNN < 100 && NNNN >10) {
						cout << "(+" << countr_code << ") " << area_code << " " << NNN << "-00" << NNNN << endl;
					}
					else if (NNNN < 10) {
						cout << "(+" << countr_code << ") " << area_code << " " << NNN << "-000" << NNNN << endl;
					}
					else {
						cout << "(+" << countr_code << ") " << area_code << " " << NNN << "-" << NNNN << endl;
					}
				}
			}
		}
	}


	Contact& Contact::operator+=(const long long no) {
		const long long y = no;
		bool x = validNo(y);
		int z = m_no;
		if (x == true) {
			Contact con;
			z++;
			con.set(m_name, &no, z);
			*this = con;
			
		}
		else {
			Contact con;
			con.set(m_name, m_phone_no, m_no);
			con = *this;
		}
		return *this;
	}

	Contact::~Contact() {
		delete[] m_phone_no;
		m_phone_no = nullptr;
	}
}