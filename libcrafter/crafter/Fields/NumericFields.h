/*
Copyright (c) 2012, Esteban Pellegrino
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL ESTEBAN PELLEGRINO BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef NUMERICFIELDS_H_
#define NUMERICFIELDS_H_

#include <iostream>
#include <ostream>
#include "FieldInfo.h"

namespace Crafter {

	class ByteField : public Field<byte> {

		void Print(std::ostream& str) const;

	protected:
		size_t nword;
		size_t nbyte;
		size_t offset;

	public:

		ByteField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~ByteField();
	};

	class XByteField : public ByteField {
		void Print(std::ostream& str) const;
	public:
		XByteField(const std::string& name, size_t nword, size_t nbyte);
		FieldInfo* Clone() const;
		virtual ~XByteField();
	};
	
	class TCPFlags : public ByteField {
		static const std::string flags[];
		void Print(std::ostream& str) const;
	public:
		TCPFlags(const std::string& name, size_t nword, size_t nbyte);
		FieldInfo* Clone() const;
		virtual ~TCPFlags();
	};

	class ShortField : public Field<short_word> {

		void Print(std::ostream& str) const;

	protected:
		size_t nword;
		size_t nbyte;
		size_t offset;

	public:

		ShortField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~ShortField();
	};

	class XShortField : public ShortField {
		void Print(std::ostream& str) const;
	public:
		XShortField(const std::string& name, size_t nword, size_t nbyte);
		FieldInfo* Clone() const;
		virtual ~XShortField();
	};

	class WordField : public Field<word> {

		void Print(std::ostream& str) const;

	protected:
		size_t nword;
		size_t nbyte;
		size_t offset;

	public:

		WordField(const std::string& name, size_t nword, size_t nbyte);

		void Write(byte* raw_data) const;

		void Read(const byte* raw_data);

		FieldInfo* Clone() const;

		virtual ~WordField();
	};

	class XWordField : public WordField {
		void Print(std::ostream& str) const;
	public:
		XWordField(const std::string& name, size_t nword, size_t nbyte);
		FieldInfo* Clone() const;
		virtual ~XWordField();
	};

}

#endif /* NUMERICFIELDS_H_ */